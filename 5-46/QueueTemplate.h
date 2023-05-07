#include <iostream>
#include <cstdlib>
using namespace std;
void Error(string s){cerr << s; exit(-1);}
const int QUEUE_SIZE = 100;
template <typename Data>

class QueueTemplate{
protected:
  Data data[QUEUE_SIZE];
  int front, rear, length;
public:
  QueueTemplate() {front = 0; rear = -1; length = 0;}
  void Insert(Data d){
    if(IsFull()) Error("Queue is full");
    rear = (rear + 1) % QUEUE_SIZE;
    data[rear] = d; length++;
  }
  Data Delete(){
    if(IsEmpty()) Error("Queue is empty");
    Data out = data[front];
    front = (front + 1) % QUEUE_SIZE;
    length--; return out;
  }
  Data Peek(){
    if(IsEmpty()) Error("Queue is empty");
    return data[front];
  }
  bool IsEmpty() {return length == 0;}
  bool IsFull() {return length == QUEUE_SIZE;}
};