#include <iostream>
using namespace std;
template <typename T>
T Min(T a, T b){
  return (a < b) ? a : b;
}

int main(){
  int a = 1;
  int b = 2;

  double d1 = 2.2;
  double d2 = 2.3;

  char c1 = 'a';
  char c2 = 'b';

  cout << "Min(1, 2) = " << Min(a, b) << endl;
  cout << "Min(2.2, 2.3) = " << Min(d1, d2) << endl;
  cout << "Min('a', 'b') = " << Min(c1, c2) << endl;
  return 0;
}