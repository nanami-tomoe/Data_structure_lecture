#include "ArrayList.h"

class Polynomial : private ArrayList{
public:
  Polynomial(int a[], int size){ // construct
    for(int i = 0; i < size; i ++){
      InsertPos(i, a[i]);
    }
  } // build polynomial
  Polynomial operator-(const Polynomial& p){
    Polynomial result = p; // copy p to result
    for(int i = 0; i < p.length; i++){
      result.data[i] = data[i] - result.data[i]; // subtract
    }
    for(int i = p.length; i < length; i++){
      result.InsertPos(i, data[i]);
    }
    return result;
  } // operator overloading
  void Print(){ //print polynomial
    for(int i = length-1; i >= 0; i--){
      if(data[i] == 0) continue;
      if(i != length-1) cout << " + ";
      cout << data[i];
      if(i != 0) cout << "x^" << i;
    }
  }
};

int main(){
  int a[] = {3, 0, 2, 5}, b[] = {5, 2, 1};
  Polynomial p1(a, sizeof(a)/sizeof(a[0]));
  Polynomial p2(b, sizeof(b)/sizeof(b[0]));
  Polynomial p3 = p1 - p2; // subtract Polynomial
  cout << "p1 = "; p1.Print();
  cout << endl << "p2 = "; p2.Print();
  cout << endl << "p3 = "; p3.Print();
  return 0;
}