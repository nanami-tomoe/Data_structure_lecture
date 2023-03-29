#include <iostream>
using namespace std;
void PrintArray(int a[], int size){
  for(int i = 0; i < size; i++) cout << a[i] << " ";
  cout << endl;
}

int main(){
  const int SIZE2 = 5, SIZE3 = 5; // size of b, c
  const int SIZE1 = SIZE2 + SIZE3; // size of a
  int b[] = {9, 6, 4, 1, 0};
  int c[] = {8, 7, 5, 3, 2};
  int a[SIZE1]; // 병합된 배열

  int i, j, k; // i for a[], j for b[], k for c[]
  for(i = j = k = 0; i < SIZE1; i++){
    if(j == SIZE2) a[i] = c[k++]; // end of b
    else if (k == SIZE3) a[i] = b[j++]; // end of c
    else a[i] = (b[j] < c[k]) ? c[k++] : b[j++];
  }
  cout << "a = "; PrintArray(a, i);
  return 0;
}