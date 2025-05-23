#include <iostream>
using namespace std;

//Programa que representa um semáforo
//1 - Qual o objetivo? Ser um semáforo
//2 - Quais propriedades e capacidades o objeto vai possuir e COMO será a interação: semaforo(estado atual dele: verde, vermelho ou amarelo)
//3 - Quais operações o semaforo vai realizar - mostrar o estado e mudar de estado
//4 - Seleciona a interface da classe

class Semaforo{
  //membros da classe
  public: //dados ou funcoes PUBLICOS que podem ser utilizados por outros objetos/funcoes
    int getEstado(); //funcoes que conseguem acessar o dado, mas nao modifica-lo, acessora
    void mudaEstado(); //funcoes que vai executar exatamente o que está descrito
    void setEstado(int est); //metodo para modificar o estado inicial, inicializadora
    Semaforo(int est = 0);
  private: //É visivel APENAS para o objeto pertencente a classe
    int estado;
};

void Semaforo::setEstado(int est){
  //this->estado = est;
  Semaforo::estado = est;
}

int Semaforo::getEstado()
{
  return Semaforo::estado;
}

void Semaforo::mudaEstado(){
  //0 - verde, 1 - amarelo, 2 - vermelho
  if(Semaforo::estado == 0){
    Semaforo::estado = 1;
  }
  else if(Semaforo::estado == 1){
    Semaforo::estado = 2;
  }
  else{
    Semaforo::estado = 0;
  }
}

Semaforo::Semaforo(int est){ //metodo de inicializacao
  setEstado(est); //Inicializando o semaforo em verde
}

int main(){
  //Semaforo sem; //cria o objeto da classe
  int est;

  //cout << "Digite o estado inicial (0 - verde, 1 - amarelo, 2 - vermelho)" << endl;
 // cin >> est;
  Semaforo sem;
  //sem.setEstado(est); // inicializo meu semaforo
    
  for(int i = 0; i < 3; i++){
    cout << "O estado atual do semaforo é: "; //acesso o valor do semaforo
    if(!sem.getEstado())
      cout << "Verde" << endl;
    else if(sem.getEstado() == 1)
      cout << "Amarelo" << endl;
    else
      cout << "Vermelho" << endl;
    sem.mudaEstado();  
  } 
  //cin >> est;
  Semaforo sem1(2);
  cout << endl << sem1.getEstado() << endl;
}
 


















