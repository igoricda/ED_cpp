#include<iostream>
using namespace std;

class node
{
private:
	node *esq, *dir;
	int chave;
public:
	node(int chave)
	{
		this->chave = chave;
		esq = NULL;
		dir = NULL;
	}
	int getChave()
	{
		return chave; 
	}
	node* getEsq()
	{
		return esq;
	}
	node* getDir()
	{
		return dir;
	}
	void setEsq(node *no)
	{
		esq = no;	
	}
	void setDir(node *no)
	{
		dir = no;
	}
};

class arvore
{
private:
	node *raiz;
public:
	arvore()
	{
		raiz = NULL;
	}
	// métodos de inserção
	void inserir(int chave);
	void inserirAux(node *no, int chave);
	node *getRaiz()
	{
		return raiz;
	}
	// percurso!!
	void emOrdem(node* no);
	void preOrdem(node* no);
	void posOrdem(node* no);
};

void arvore::emOrdem(node* no)
{
	if (no != NULL)
	{
		emOrdem(no->getEsq());
		cout << no->getChave() << " ";
		emOrdem(no->getDir());
	}
}

void arvore::preOrdem(node *no)
{
	if (no != NULL)
	{
		cout << no->getChave() << " ";
		preOrdem(no->getEsq());
		preOrdem(no->getDir());
	}
}

void arvore::posOrdem(node *no)
{
	if (no != NULL)
	{
		posOrdem(no->getEsq());
		posOrdem(no->getDir());
		cout << no->getChave() << " ";
	}
}

void arvore::inserir(int chave)
{
	//inserção na árvore vazia
	if (raiz == NULL)
		raiz = new node(chave);
	else // nao ta vazia
		inserirAux(raiz, chave);
}

void arvore::inserirAux(node *no, int chave)
{
	//inserir a esquerda
	//verifica se o valor é MENOR do que a raiz
	if (chave < no->getChave())
	{
		//verificar se existe filho da esquerda
		if (no->getEsq() == NULL)
		{
			node *novo_no = new node(chave);
			no->setEsq(novo_no); //filho da esquerda
		}
		else //se tiver um filho, esse filho é a raiz da subarvore
		{
			//percorre recursivamente
			inserirAux(no->getEsq(), chave);
		}
	} //direita
	else if(chave > no->getChave())
	{
		if (no->getDir() == NULL)
		{
			node *novo_no = new node(chave);
			no->setDir(novo_no);
		}
		else
		{
			inserirAux(no->getDir(), chave);
		}
	}
	else if (chave == no->getChave()) // se for igual nao insere na arvore
	{
		cout << "esse valor já existe!" << endl;
	}
}

int main(int argc, char const *argv[])
{
	arvore tree;
	tree.inserir(20);
	tree.inserir(15);
	tree.inserir(18);
	tree.inserir(23);
	tree.inserir(17);
	tree.inserir(30);
	tree.posOrdem(tree.getRaiz());


	return 0;
}