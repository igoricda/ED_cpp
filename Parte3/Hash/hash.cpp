#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class hashtable1{
public:
  int bucket;

  //vetor para guardar as chaves
  vector<vector<int>> tabela;
  
  //metodo de insercao
  void insere(int chave){
    int index = funcao_hash(chave);
    tabela[index].push_back(chave);
  }

  //funcao hash
  int funcao_hash(int chave){ return chave % bucket;}

  //deleta chave da tabela
  void remove(int chave);

  //impressao
  void imprime();

  //construtor
  hashtable1(int b){ this->bucket = b; tabela.resize(b);}
};

//remocao

void hashtable1::remove(int chave){
  int index = this->funcao_hash(chave);
  
  //encontra e remove a chave da tabela
  auto i = find(tabela[index].begin(), tabela[index].end(), chave);
  if( i != tabela[index].end()){
    tabela[index].erase(i);
  }
}

//impressao da tabela
void hashtable1::imprime(){
  for(int i = 0; i < bucket; i++){
    cout << i;
    for(int x: tabela[i]){
      cout <<  " -- " << x;
    }
    cout << endl;
  }
}

int main(){

  //vetor com as chaves
  vector<int> v = {30, 99, 23, 65};
  hashtable1 h(6);

  //inserir as chaves
  for(int i: v){
    h.insere(i);
  }

  h.imprime();
  h.remove(23);
  h.imprime();


  return 0;

}

