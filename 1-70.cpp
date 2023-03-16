#include <iostream>
using namespace std;

int main(){
  int s[10] = {1, 2, 3, 4, 5, 3, 4, 5, 6, 1};
  int n;
  cout << "n = ";
  cin >> n;
  int cnt = 0;
  for(int i = 0; i < 10; i++){
    if(n == s[i]){
      cnt += 1;
      cout << i << " ";
    }
  }
  if(cnt == 0){
    cout << "Search Failed" << endl;
  }
  return 0;
}