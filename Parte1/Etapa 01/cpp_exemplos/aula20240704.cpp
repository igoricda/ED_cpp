#include <iostream>
using namespace std;

int fatorial(int a, int w = -1){
  int v = 1;
  for(; a>=1; a--){
    v*= a;
  }
  cout << w << endl;
  return v;
}

int main(){
  int a;
  cin >> a;
  cout << fatorial(a) << endl;
    
  return 0;
}
