#include <iostream>
#include <cstdlib> // for exit()
using namespace std;
const int STACK_SIZE = 100; // max size of stack
typedef int Data; // Data can be ant type
void Error(string s){cerr << s; exit(-1);}

class Stack{ // array implementation of stack
  Data data[STACK_SIZE]; // stack array
  int top; // top position of stack
public:
  Stack() {top = -1;} // default constructor
  void Push(Data d); // insert a new element
  Data Pop(); // delete latest element
  Data Peek();
  bool IsEmpty() {return top == -1;} // is stack empty?
  bool IsFull() {return top == STACK_SIZE - 1;} // is stck full?
  void PrintStack(); // print stack elements
  int Length() {return top + 1;} // # of lelment om stack
  void Replace(Data d); // 함수 추가
};

void Stack::Push(Data d){ //O(1)
  if(IsFull()) Error("Stack is full");
  data[++top] = d;
}

Data Stack::Pop(){ //O(1)
  if(IsEmpty()) Error("Stack is empty");
  return data[top--];
}

Data Stack::Peek(){ //O(1)
  if(IsEmpty()) Error("Stack is empty");
  return data[top];
}

void Stack::PrintStack(){ //O(n)
  cout << "Stack: ";
  for(int i = 0; i <= top; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}

void Stack::Replace(Data d){
  data[top] = d; // top에 있는 element 바꾸기
}