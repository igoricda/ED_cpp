#include<iostream>
using namespace std;

class node
{
private:
	node *esq, *dir;
	int chave;
  int height;
public:
	node(int chave)
	{
		this->chave = chave;
		esq = NULL;
		dir = NULL;
                height = 0;
	}
	int getChave()
	{
		return chave; 
	}
  void setChave(int key){
    chave = key;
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
  int getHeight(node *no){
    if(no == NULL)
      return -1;
    else
      return no->height;
  }
  void setHeight(node *no, int h){
    no->height = h;
  }
  int fatorBalanceamento(node *no){
    if(no)
      return (getHeight(no->esq) - getHeight(no->dir));
    else {
      return 0;
    }
  }
  node* rotDir(node *no){
    node *aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    no->height = max(getHeight(no->esq), getHeight(no->dir))+1;
    aux->height = max(getHeight(aux->esq), getHeight(aux->dir)) +1;
    no = aux;
    return aux;
  }

  node* rotEsq(node *no){
    node *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    no->height = max(getHeight(no->esq), getHeight(no->dir))+1;
    aux->height = max(getHeight(aux->esq), getHeight(aux->dir)) +1;
    no = aux;
    return aux;
  }

  node* rotDuplaEsq(node *no){
    no->dir = rotDir(no->dir);
    return rotEsq(no);
  }

  node* rotDuplaDir(node *no){
    no->esq = rotEsq(no->esq);
    return rotDir(no);
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
	node* inserir(node *no, int chave);
	node *getRaiz()
	{
		return raiz;
	}
	void setRaiz(node* no){
	  raiz = no;
	}
        node* balancear(node *no);
        node* remocao(node *no, int chave);
        node* sucessor(node *no);
	// percurso!!
	void emOrdem(node* no, node* raiz);
	void preOrdem(node* no);
	void posOrdem(node* no);
};

void arvore::emOrdem(node* no, node* raiz)
{
	if (no != NULL)
	{
		emOrdem(no->getEsq(), raiz);
		int h = 0;
		node *aux = raiz;
		while(aux->getChave() != no->getChave()){
		  h++;
		  if(aux->getChave() > no->getChave())
		    aux = aux->getEsq();
		  else if (aux->getChave() < no->getChave())
		    aux = aux->getDir();
		}
                cout << no->getChave() <<"," << h << "\n";
		emOrdem(no->getDir(), raiz);
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

node* arvore::inserir(node *no, int chave){
  if(no == NULL){
    return new node(chave);}
  //Inserir em arvore nao vazia
  else{
    if(chave < no->getChave()){
        no->setEsq(inserir(no->getEsq(), chave));
    } else if(chave > no->getChave()){
      no->setDir(inserir(no->getDir(), chave));
    }
    else
      cout << "Elemento já presente na arvore \n";
  }
   no->setHeight(no, max(no->getHeight(no->getEsq()), no->getHeight(no->getDir())) + 1);
   no = balancear(no);
   return no;
}

node* arvore::balancear(node *no){
  short fb = no->fatorBalanceamento(no);
  
  if(fb < -1 && no->fatorBalanceamento(no->getDir()) <= 0){
    no = no->rotEsq(no);
  } else if(fb > 1 && no->fatorBalanceamento(no->getEsq()) >= 0){
    no = no->rotDir(no);
  } else if(fb > 1 && no->fatorBalanceamento(no->getEsq()) < 0){
    no = no->rotDuplaDir(no);
  } else if (fb < -1 && no->fatorBalanceamento(no->getDir()) > 0){
    no = no->rotDuplaEsq(no);
  }
  return no;
}
node* arvore::remocao(node* no, int chave){
  //arvore nula
  if(no == NULL)
    return NULL;
  //verificar qual subarvore a chave se encontra
  else{
    if(no->getChave() == chave){
      if(no->getEsq() == NULL && no->getDir() == NULL){
        delete no;
        return NULL;
      }
      else{
        if(no->getEsq() != NULL && no->getDir() != NULL){
          node *aux = no->getEsq();
          while(aux->getDir() != NULL){
            aux = aux->getDir();
          }
          no->setChave(aux->getChave());
          aux->setChave(chave);
          no->setEsq(remocao(no->getEsq(), chave));
          return no;
        }
        else{
          node *aux;
          if(no->getEsq() != NULL){
            aux = no->getEsq();
          }
          else{
            aux = no->getDir();
          }
          delete no;
          return aux;
        }
      }
    } else{
      if(chave < no->getChave()){
        no->setEsq(remocao(no->getEsq(), chave));
      } else
        no->setDir(remocao(no->getDir(), chave));  
    }
  }
  no->setHeight(no, max(no->getHeight(no->getEsq()), no->getHeight(no->getDir())) + 1);
  no = balancear(no);
  return no;
}

node* arvore::sucessor(node* no){
  no = no->getDir();
  while(no != NULL && no->getEsq() != NULL)
    no = no->getEsq();
  return no;
}


int main(int argc, char const *argv[])
{
	arvore tree;
	int chave;
	char op;

	cin >> op >> chave;
	//cout << chave <<"," << op << "\n";
	 if(op == 'i'){
	    tree.setRaiz(tree.inserir(tree.getRaiz(), chave));
	  } else if(op == 'r'){
	    tree.setRaiz(tree.remocao(tree.getRaiz(), chave));
	  }
	while(cin >> op >> chave){
          //cout << chave <<"," << op<< "\n";
	  if(op == 'i'){
	    tree.setRaiz(tree.inserir(tree.getRaiz(), chave));
	  } else if(op == 'r'){
	    tree.setRaiz(tree.remocao(tree.getRaiz(), chave));
	  }
	}
	
	tree.emOrdem(tree.getRaiz(),tree.getRaiz());


	return 0;
}
