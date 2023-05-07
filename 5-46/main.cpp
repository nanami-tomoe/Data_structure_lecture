#include "QueueTemplate.h"
void BreathFirstSearch(int n){
  QueueTemplate <int> q;
  bool visited[10] = {false};
  q.Insert(n);
  while(q.IsEmpty() == false){
    n = q.Delete();
    if(n < 1 || n > 9 || visited[n]) continue;
    visited[n] = true; cout << n << " ";
    q.Insert(n-1); q.Insert(n+1);
  }
}

int main(){
  BreathFirstSearch(5);
  return 0;
}