#include "Student.h"
#include "StackTemplate.h"

int main(){
  StackTemplate <Student> s;
  s.Push(Student("Kim", 1234));
  while(s.IsEmpty() == false){
    s.Pop().Print();
  }
  return 0;
}