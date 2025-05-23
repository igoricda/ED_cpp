#include<iostream>
#include "arvore.h"
using namespace std;

//Arquivo main
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
	
	tree.emOrdem(tree.getRaiz(),0);


	return 0;
}
