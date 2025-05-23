#include <iostream>
#include <string>

using namespace std;

#define TAM 20

struct endereco{
  char rua[TAM];
  int numero;
};

struct pessoa{
  char nome[TAM];
  int idade;
  struct endereco moradia;
};

struct endereco obtem_endereco(){
  struct endereco end;
  cout << "Digite o nome da rua: \n";
  cin.getline(end.rua, TAM);
  cout << "Digite o numero da casa: " << endl;
  cin >> end.numero;
  return end;
}

int main(){
  struct pessoa estudante;
  estudante.moradia = obtem_endereco();
  getchar();
  cout << "Digite o nome do estudante: ";
  cin.getline(estudante.nome, TAM);
  cout << "Digite a idade: ";
  cin >> estudante.idade;
  cout << "Nome: " << estudante.nome << endl << "Idade: " << estudante.idade <<endl;
  cout << "Rua: " << estudante.moradia.rua << ", " << estudante.moradia.numero << endl;
}
