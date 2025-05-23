#include <iostream>
using namespace std;

class node{
  private: 
    node *esq, *dir;
    int key;
    
  public:
    node(int key){
      this->key = key;
      esq = NULL;
      dir = NULL;
    }
    int getKey(){
      return key;
    }
    node *getEsq(){
      return  esq;
    }
    node *getDir(){
      return dir;
    }
    void setEsq(node *no){
      esq = no;
    }
    void setDir(node *no){
      dir = no;
    }
    void setKey(int chave){
      this->key = chave;
  }
};

class tree{
  private:
    node *root;
  public:
    tree(){
     root = NULL;
  }
  void inserir(int key);
  void inserirAux(node *no, int key);
  node *getRoot(){
    return root;
  }
  //percurso
  void emOrdem(node* no);
  void preOrdem(node* no);
  void posOrdem(node* no);
  node* remocao(node *no, int chave);
  node* sucessor(node *no);
  node* antecessor(node *no);
};

void tree::inserir(int key){
  //Insercao em arvore vazia
  if(root == NULL)
    root = new node(key);
  else {
    inserirAux(root, key);
  }
}

void tree::inserirAux(node *no, int key){
  //Inserir em arvore nao vazia
  if(key < no->getKey()){
    if(no->getEsq() == NULL){
      node *novo = new node(key);
      no->setEsq(novo);
    }
    else{
      inserirAux(no->getEsq(), key);
    }
  }
  else if(key > no->getKey()){
    if(no->getDir() == NULL){
      node *novo = new node(key);
      no->setDir(novo);
    }
    else{
      inserirAux(no->getDir(), key);
    }
  }
  else{
    cout << "Esse valor já existe!\n";
  }
}

void tree::emOrdem(node* no){
  if(no != NULL){
    emOrdem(no->getEsq());
    cout << no->getKey() << " ";
    emOrdem(no->getDir());
  }
  else{
    return;
  }
}

void tree::preOrdem(node* no){
  if(no != NULL){
    cout << no->getKey() << " ";
    preOrdem(no->getEsq());
    preOrdem(no->getDir());
  }
  else{
    return;
  }
}

void tree::posOrdem(node* no){
  if(no != NULL){
    posOrdem(no->getEsq());
    posOrdem(no->getDir());
    cout << no->getKey() << " ";
  }
  else{
    return;
  }
}

node* tree::remocao(node* no, int chave){
  //arvore nula
  if(no == NULL)
    return no;
  //verificar qual subarvore a chave se encontra
  if(no->getKey() > chave){
    no->setEsq(remocao(no->getEsq(), chave));
  }
  else if(no->getKey() < chave){
    no->setDir(remocao(no->getDir(), chave));
  }
  else{ //O no atual contem a chave
    if(no->getEsq() == NULL && no->getDir() == NULL){
      delete no;
      return NULL;
    }
    else{
      if(no->getEsq() == NULL){
        node *tmp = no->getDir();
        delete no;
        return tmp;
      }
      else if(no->getDir() == NULL){
        node *tmp = no->getEsq();
        delete no;
        return tmp;
      }
      else{
        node *s = sucessor(no);
        no->setKey(s->getKey());
        no->setDir(remocao(no->getDir(), s->getKey()));
      }
      return no;
    }
  }
  return no;
}

node* tree::sucessor(node* no){
  no = no->getDir();
  while(no != NULL && no->getEsq() != NULL)
    no = no->getEsq();
  return no;
}

node* tree::antecessor(node* no){
  no = no->getEsq();
  while(no != NULL && no->getDir() != NULL)
    no = no->getDir();
  return no;
}

int main(){
  tree arvore;
  arvore.inserir(50);
  arvore.inserir(30);
  arvore.inserir(90);
  arvore.inserir(85);
  arvore.inserir(100);
  arvore.inserir(20);
  arvore.inserir(40);
  arvore.inserir(35);
  arvore.inserir(45);
  arvore.inserir(37);
  arvore.emOrdem(arvore.getRoot());
  cout << endl;
  arvore.remocao(arvore.getRoot(), 30);
  arvore.emOrdem(arvore.getRoot());
  cout << endl;
}











