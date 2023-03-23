#include <iostream>
using namespace std;

class Complex{
  double real, imag; // real, imaginary numbers
public:
  Complex(double r, double i){real = r; imag = i;}

  // Operator overloading 연산자 오버로딩, 자료형들간의 연산 
  Complex operator* (const Complex &c){ // Complex 타입 반환
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
  } // (a+bi)(c+di) = (ac - bd) + (ad + bc)i

  void Print(){
    cout << "(" << real << "," << imag << ")" << endl;
  }
};

int main(){
  Complex a(1.0, 2.0), b(3.0, 4.0);
  a.Print();
  b.Print();
  a = a * b;
  a.Print();
  return 0;
}
