#include <iostream>
#include <cstring>
using namespace std;

class livro{
  protected:
    char titulo[64];
    int edicao;
  public:
  livro(char *titulo, int edicao);
  void mostralivro();
};

livro::livro(char *titulo, int edicao){
  livro::edicao = edicao;
  strcpy(livro::titulo, titulo);
}

void livro::mostralivro(){
  cout << "Titulo: " << titulo << endl << "Edicao: " <<edicao <<endl;
}

class disco{
  protected:
    char cantor[64];
    int tempo;
  public:
    disco(char *cantor, int tempo);
    void mostra_disco();
};

disco::disco(char *cantor, int tempo){
  this->tempo = tempo;
  strcpy(disco::cantor, cantor);
}

void disco::mostra_disco(){
    cout << "Cantor: " << cantor << endl << "Tempo: " << tempo << endl;
}

//heranca multipla, herda membros de livro e disco
class pacote : public livro, public disco{
  double preco;
  public:
    pacote(char *titulo, int edicao, char *cantor, int tempo, double preco);
    void mostra_pacote();
};

pacote::pacote(char *titulo, int edicao, char *cantor, int tempo, double preco): livro(titulo, edicao), disco(cantor, tempo){
  this->preco = preco;
}
void pacote::mostra_pacote(){
  cout << "Pacote: \nPreco: " << this->preco << endl;
  cout << "Livro: \nTitulo: " << this->titulo << " Edicao: " << this->edicao;
  cout << "\nDisco:\nCantor: " << this->cantor << " Tempo: " << this->tempo << endl;
}
    
int main(){
  char tit[] = "Biblia do edmar";
  livro bliba(tit, 4);
  bliba.mostralivro();
  char canta[] = "MCDALAS";
  disco albm(canta, 80);
  albm.mostra_disco();
  pacote pack(tit, 4, canta, 10, 99.99);
  pack.mostra_pacote();
}
