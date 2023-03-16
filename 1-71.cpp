#include <iostream>
using namespace std;
#define SIZE 5

int power(int r){ // 2의 제곱수 함수
  int squ = 1;
  for(int i = 0; i < r; i++){
    squ *= 2;
  }
  return squ;
}

int main(){
  char str[] = "10011";
  int num = 0; 
  for(int i = 0; i < SIZE; i++){
    num += power(4 - i)*(str[i] - '0');
  }

  cout << num;

  return 0;
}