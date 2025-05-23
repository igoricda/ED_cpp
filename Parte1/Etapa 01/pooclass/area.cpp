#include <iostream>
using namespace std;

class Retangulo
{
  private:
    double h, b;
  public:
    void ImprimeArea(double area);
    Retangulo(double base, double altura);
    double area();
};

Retangulo::Retangulo(double base, double altura)
{
  Retangulo::b = base;
  Retangulo::h = altura;
}

void Retangulo::ImprimeArea(double area){
  cout << "A área solicitada é " << area << endl;
}

double Retangulo::area(){
  return this->b * this->h;
}

class Triangulo{
  private:
    double b, h;
  public:
    double area();
    Triangulo(double base, double altura);
};

Triangulo::Triangulo(double base, double altura){
  Triangulo::b = base;
  Triangulo::h = altura;
}

double Triangulo::area(){
  return (this->b*this->h)/2;
}

class Circulo{
  private:
    double r;
  public:
    Circulo(double raio);
    double area();
};

Circulo::Circulo(double raio){
  Circulo::r = raio;
}

double Circulo::area(){
  return 3.14 * this->r * this->r;
}

int main(){
  Circulo circ(10.0);
  Retangulo ret(12.0, 4.0);
  Triangulo tri(3.5, 3.0);

  double area_tri = tri.area();
  double area_ret = ret.area();
  double area_circ = circ.area();

  ret.ImprimeArea(area_tri);
  ret.ImprimeArea(area_circ);
  ret.ImprimeArea(area_ret);

  return 0;
}











