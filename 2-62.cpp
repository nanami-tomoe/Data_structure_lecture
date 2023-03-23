#include <iostream>
using namespace std;

class Count{
  int n;
public:
  Count(){n = 0;} // construct
  void Increment(){n++;} // method 멤버 함수 정의
  void Decrement(){n--;}
  void Print(){cout << "Value = " << n << endl;}
};

int main(){
  Count count; // construc & initialize 클래스에 대한 객체가 만들어지고 값이 초기화
  count.Print();
  count.Increment();
  count.Print();
  count.Decrement();
  count.Print();
  return 0;
}