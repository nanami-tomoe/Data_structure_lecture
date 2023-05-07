#include "Queue.h"

int main(){
  Queue q;
  q.Insert(10);
  q.Insert(20);
  q.Insert(30);
  q.Insert(40);
  q.Insert(50);
  q.Insert(60);
  q.PrintQueue();
  q.Delete();
  q.Delete();
  q.Delete();
  q.PrintQueue();
  q.Delete();
  q.Delete();
  q.Delete();
  q.PrintQueue();
  return 0;
}