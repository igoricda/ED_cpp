#include <iostream>
#include "arvore.h"
using namespace std;

// Construtor para inicializar o nó com uma chave
node::node(int chave) {
    this->chave = chave;
    esq = NULL; // Ponteiro para o filho esquerdo
    dir = NULL; // Ponteiro para o filho direito
    height = 0; // Altura inicial do nó
}

// Retorna a chave do nó
int node::getChave() {
    return chave; 
}

// Define uma nova chave para o nó
void node::setChave(int key) {
    chave = key;
}

// Retorna o ponteiro para o filho esquerdo
node* node::getEsq() {
    return esq;
}

// Retorna o ponteiro para o filho direito
node* node::getDir() {
    return dir;
}

// Define o ponteiro para o filho esquerdo
void node::setEsq(node *no) {
    esq = no;    
}

// Define o ponteiro para o filho direito
void node::setDir(node *no) {
    dir = no;
}

// Retorna a altura do nó; se nulo, retorna -1
int node::getHeight(node *no) {
    if (no == NULL)
        return -1;
    else
        return no->height;
}

// Define a altura do nó
void node::setHeight(node *no, int h) {
    no->height = h;
}

// Calcula o fator de balanceamento do nó
int node::fatorBalanceamento(node *no) {
    if (no)
        return (getHeight(no->esq) - getHeight(no->dir));
    else {
        return 0;
    }
}

// Rotação simples à direita
node* node::rotDir(node *no) {
    node *aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    no->height = max(getHeight(no->esq), getHeight(no->dir)) + 1;
    aux->height = max(getHeight(aux->esq), getHeight(aux->dir)) + 1;
    no = aux;
    return aux;
}

// Rotação simples à esquerda
node* node::rotEsq(node *no) {
    node *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    no->height = max(getHeight(no->esq), getHeight(no->dir)) + 1;
    aux->height = max(getHeight(aux->esq), getHeight(aux->dir)) + 1;
    no = aux;
    return aux;
}

// Rotação dupla à direita
node* node::rotDuplaDir(node *no) {
    no->esq = rotEsq(no->esq);
    return rotDir(no);
}

// Rotação dupla à esquerda
node* node::rotDuplaEsq(node *no) {
    no->dir = rotDir(no->dir);
    return rotEsq(no);
}

// Percurso em ordem na árvore
void arvore::emOrdem(node* no, int level) {
    if (no != NULL) {
        emOrdem(no->getEsq(), level+1);
        cout << no->getChave() << "," << level << "\n";
        emOrdem(no->getDir(), level+1);
    }
}

// Percurso pré-ordem
void arvore::preOrdem(node *no) {
    if (no != NULL) {
        cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

// Percurso pós-ordem
void arvore::posOrdem(node *no) {
    if (no != NULL) {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << no->getChave() << " ";
    }
}

// Inserção de um novo nó na árvore
node* arvore::inserir(node *no, int chave) {
    if (no == NULL) {
        return new node(chave);
    } else {
        if (chave < no->getChave()) {
            no->setEsq(inserir(no->getEsq(), chave));
        } else if (chave > no->getChave()) {
            no->setDir(inserir(no->getDir(), chave));
        } else
            cout << "Elemento já presente na arvore \n";
    }
    no->setHeight(no, max(no->getHeight(no->getEsq()), no->getHeight(no->getDir())) + 1); //Atualizar altura de todos os nos
    no = balancear(no); //balancear a arvore a partir de cada no
    return no;
}

// Balanceia o nó
node* arvore::balancear(node *no) {
    short fb = no->fatorBalanceamento(no);
    if (fb < -1 && no->fatorBalanceamento(no->getDir()) <= 0) {
        no = no->rotEsq(no);
    } else if (fb > 1 && no->fatorBalanceamento(no->getEsq()) >= 0) {
        no = no->rotDir(no);
    } else if (fb > 1 && no->fatorBalanceamento(no->getEsq()) < 0) {
        no = no->rotDuplaDir(no);
    } else if (fb < -1 && no->fatorBalanceamento(no->getDir()) > 0) {
        no = no->rotDuplaEsq(no);
    }
    return no;
}

// Remoção de um nó na árvore, padrao de arvore binaria, mas com balanceamento ao final
node* arvore::remocao(node* no, int chave) {
    if (no == NULL)
        return NULL;
    else {
        if (no->getChave() == chave) {
            if (no->getEsq() == NULL && no->getDir() == NULL) {
                delete no;
                return NULL;
            } else {
                if (no->getEsq() != NULL && no->getDir() != NULL) {
                    node *aux = no->getEsq();
                    while (aux->getDir() != NULL) { //acha sucessor
                        aux = aux->getDir();
                    }
                    no->setChave(aux->getChave()); //Troca as chaves do no a ser removido e do sucessor
                    aux->setChave(chave);
                    no->setEsq(remocao(no->getEsq(), chave)); //remove sucessor
                    return no;
                } else {
                    node *aux;
                    if (no->getEsq() != NULL) {
                        aux = no->getEsq();
                    } else {
                        aux = no->getDir();
                    }
                    delete no;
                    return aux;
                }
            }
        } else {
            if (chave < no->getChave()) {
                no->setEsq(remocao(no->getEsq(), chave));
            } else
                no->setDir(remocao(no->getDir(), chave));
        }
    }
    no->setHeight(no, max(no->getHeight(no->getEsq()), no->getHeight(no->getDir())) + 1); //Atualizar altura de todos os nos
    no = balancear(no); //balancear a arvore a partir de cada no
    return no;
}

// Retorna o sucessor de um nó
node* arvore::sucessor(node* no) {
    no = no->getDir();
    while (no != NULL && no->getEsq() != NULL)
        no = no->getEsq();
    return no;
}

// Retorna a raiz da árvore
node* arvore::getRaiz() {
    return raiz;
}

// Define a raiz da árvore
void arvore::setRaiz(node* no) {
    raiz = no;
}

