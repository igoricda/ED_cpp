#ifndef ARVORE_H
#define ARVORE_H

class node
{
private:
	node *esq, *dir;
	int chave;
  int height;
public:
	node(int chave);
	int getChave();	
        void setChave(int key);
	node* getEsq();
	node* getDir();
	void setEsq(node *no);
	void setDir(node *no);
        int getHeight(node *no);
        void setHeight(node *no, int h);
        int fatorBalanceamento(node *no);
        node* rotDir(node *no);
        node* rotEsq(node *no);
        node* rotDuplaEsq(node *no);
        node* rotDuplaDir(node *no);
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
	node* inserir(node *no, int chave);
	node *getRaiz();
	void setRaiz(node* no);
        node* balancear(node *no);
        node* remocao(node *no, int chave);
        node* sucessor(node *no);
	// percurso!!
	void emOrdem(node* no, int level);
	void preOrdem(node* no);
	void posOrdem(node* no);
};
#endif
