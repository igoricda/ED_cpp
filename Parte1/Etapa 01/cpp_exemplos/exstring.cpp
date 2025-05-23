#include <iostream>
using namespace std;

int main(){
	char str[11], invert[11];

	cin >> str;
	int j = 0, i = 0;
	while(str[j] != '\0'){
		j++;
	}
	while(j){
		invert[i] = str[j-1];
		j--;
		i++;
	}
	invert[i] = '\0';
	cout << invert;

	return 0;
}
