#include <iostream>
using namespace std;

int main(){
  int a = 8;
  int b = 3;
  int& c = a; //referencia
  int *ptr; //ponteiro que aponta para um tipo inteiro
  ptr = &b;
  c -= 4;
  cout << a << endl;
  cout << "O valor do meu ponteiro " << ptr << endl;
  cout << "O conteudo do endereco contido em ptr é " << *ptr << endl;
  cout << "O valor da referencia é " << c << endl;
  return 0;
}
