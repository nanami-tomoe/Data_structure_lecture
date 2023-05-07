#include "QueueStudent.h"

int main(){
  Queue q;
  Element e;
  e.name = "Kim";
  e.id = 1234;
  q.Insert(e);
  q.PrintQueue();
  q.Delete();
  q.PrintQueue();
  return 0;
}