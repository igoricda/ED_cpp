#include <iostream>
using namespace std;

#define pi 3.1415

class FormaGeometrica{
  //atributos
  //funcoes-membro/metodos
  protected:
    int lados;
  public:
    virtual void getDados() = 0;
    virtual double imprimeArea() = 0;
    //Crio um metodo virtual para ser modificado pelas classe derivadas / subclasses
    FormaGeometrica(int lados);
};

FormaGeometrica::FormaGeometrica(int lados){
  this->lados = lados;
}
//Heranca 
//class NovaClasse : modificador_de_acesso ClasseBase
class Circulo : public FormaGeometrica{
  private:
    double raio;
  public:
    double imprimeArea();
    void getDados();
    Circulo(int lados, double raio);
};

Circulo::Circulo(int lados, double raio) : FormaGeometrica(lados){
  this->raio = raio;
}
//metódo que vai caluclar a area e imprimir
double Circulo::imprimeArea(){
  double area;
  area = raio * raio * pi;
  cout << "Área do círculo: " << area << endl;
  return area;
}

void Circulo::getDados(){
  cout << "Digite o raio do circulo: ";
  cin >> Circulo::raio; //this->raio
}

class Retangulo : public FormaGeometrica{
  private:
    double base, altura;
  public:
    double imprimeArea();
    void getDados();
    Retangulo(int lados, double base, double altura);
};

Retangulo::Retangulo(int lados, double base, double altura) : FormaGeometrica (lados){
  this->base = base;
  this->altura = altura;
}

double Retangulo::imprimeArea(){
  double area = base * altura;
  cout << "Área do retangulo: " << area << endl;
  return area;
}

void Retangulo::getDados(){
  cout << "Digite a base do retangulo: ";
  cin >> this->base;
  cout << "Digite a altura do retangulo: ";
  cin >> this ->altura;
}

class Triangulo : public FormaGeometrica{
  private:
    double base, altura;
  public:
    double imprimeArea();
    void getDados();
    Triangulo(int lados, double base, double altura);
};

Triangulo::Triangulo(int lados, double base, double altura) : FormaGeometrica(lados){
  this->base = base;
  this->altura = altura;
}

double Triangulo::imprimeArea(){
  double area = (base * altura)/2;
  cout << "Area do triangulo: " << area << endl;
  return area;
}

void Triangulo::getDados(){
  cout << "Digite a base do triangulo: ";
  cin >> this->base;
  cout << "Digite a altura do triangulo: ";
  cin >> this->altura;
}

int main(){
  //Quando eu instancio, chamo o construtor da classe
  Circulo c(0, 2.1);
  Retangulo r(4, 3.3, 6.4);
  Triangulo t(3, 4, 8);
  //c. getDados();
  c.imprimeArea();
  //r.getDados();
  r.imprimeArea();
  //t.getDados();
  t.imprimeArea();

  return 0;
}
