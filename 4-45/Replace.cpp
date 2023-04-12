#include "Stack.h"

int main(){
  Stack s;
  s.Push(1);
  s.Push(2);
  s.Push(3);
  s.Push(4);
  s.Replace(5);
  s.PrintStack();
  return 0;
}