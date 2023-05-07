#include "ArrayList.h"

int main(){
  ArrayList a;
  a.InsertPos(0, 'A');
  a.InsertPos(0, 'B');
  a.InsertPos(1, 'C');
  a.PrintList();
  a.DeletePos(0);
  a.DeletePos(0);
  a.DeletePos(0);
  a.PrintList();
  return 0;
}