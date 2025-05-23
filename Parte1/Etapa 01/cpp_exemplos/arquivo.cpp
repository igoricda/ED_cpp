#include <iostream>
#include <iomanip>

using namespace std;

#define tamanho 200

const int tam = 200;	
void principal(){
	printf("%d\n", tam);	
}
int main(){
	principal();
	int inteiro ;	//32 bits
	char character;	//8 bits
	bool boolean;	//8 bits
	float reais = 2.65833;	//32 bits
	double realb;	//64 bits
  	
	cout << "Hello, World!" << endl;
	cout << "Digite um inteiro: ";
	cin >> inteiro;
	int resultado = inteiro * 2;

	if(resultado > 10 || inteiro == 2){
		cout << "Novo número: " << resultado << endl;
	}
	else{
		cout << fixed << setprecision(2);
		cout << "Número original: " << reais << endl;
		printf("o núemro float é %.2f\n", &reais);
	}
	return 0;
}





