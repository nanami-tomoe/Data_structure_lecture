#include <iostream>
using namespace std;
const int LENGTH = 8;

class WinnerTree{
  int data[2 * LENGTH];
  int Winner(int left, int right){
    return max(left, right);
  }
public: 
  WinnerTree(int a[]){
    for(int i = 0; i < LENGTH; i++)
      data[LENGTH + i] = a[i];
    for(int i = LENGTH - 1; i >= 1; i--)
      data[i] = Winner(data[i*2], data[i*2+1]);
  }
  int GetWinner(){return data[1];}
  void Replace(int j, int d){
    int i = LENGTH + j;
    data[i] = d;
    while(i > 1){
      i /= 2;
      data[i] = Winner(data[i*2], data[i*2+1]);
    }
  }
};

int main(){
  int a[LENGTH] = {4, 3, 6, 1, 8, 5, 2, 7};
  WinnerTree w(a);
  cout << "Winner = " << w.GetWinner();
  w.Replace(3, 9);
  cout << "; Winner = " << w.GetWinner();
  return 0;
}