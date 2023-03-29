#include <iostream>
using namespace std;
const int SIZE = 10; // 배열 크기
void PrintArray(int a[], int size){
  for(int i = 0; i < size; i++) cout << a[i] << " ";
  cout << endl;
}

int main(){
  int a[SIZE] = {1, 2, 2, 3, 4, 5, 2, 7, 3, 9};
  int size = SIZE;
  int i, j, num1 = 2, num2 = 3;
  cout << "before: ";
  PrintArray(a, size);

  for(i = 0, j = 0; i < size; i++){
    if(a[i] != num1 && a[i] != num2) a[j++] = a[i];
  }
  size = j;
  cout << "after: ";
  PrintArray(a, size);
  return 0;
}