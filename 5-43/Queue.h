#include <iostream>
#include <cstdlib>
using namespace std;
const int QUEUE_SIZE = 5;
typedef int Data;
void Error(string s) {cerr << s; exit(-1);}

class Queue{
protected:
  Data data[QUEUE_SIZE];
  int front, rear;
  int length;
public:
  Queue() {front = 0; rear = -1; length = 0;}
  void Insert(Data d);
  Data Delete();
  Data Peek();
  bool IsEmpty() {return length == 0;}
  bool IsFull() {return length == QUEUE_SIZE;}
  void PrintQueue();
  void PrintBuffer();
  int Length() {return length;}
};

void Queue::Insert(Data d){ //O(1)
  if(IsFull());
  else{
    rear = (rear + 1) % QUEUE_SIZE;
    data[rear] = d; length++;
  }
}

Data Queue::Delete(){ //O(1)
  if(IsEmpty()){
    return data[front];
  }
  else{
    Data out = data[front];
    front = (front + 1) % QUEUE_SIZE; length--;
    return out;
  }
}

Data Queue::Peek(){ //O(1)
  return data[front];
}

void Queue::PrintQueue(){ //O(n)
  cout << "Queue: ";
  for(int i = 0; i < length; i++){
    cout << data[front + i % QUEUE_SIZE];
    cout << " ";
  }
  cout << endl;
}

void Queue::PrintBuffer(){ // O(n)
  cout << "Buffer: front = " << front;
  cout << "; rear = " << rear << "; ";
  for(int i = 0; i < QUEUE_SIZE; i++){
    if((front <= i && i <= front + length - 1) || (rear - length + 1 <= i && i <= rear))
      cout << data[i] << " ";
  
    else 
      cout << "__";
  }
  cout << endl;
}