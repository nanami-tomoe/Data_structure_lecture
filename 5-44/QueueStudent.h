#include <iostream>
#include <cstdlib>
using namespace std;
const int QUEUE_SIZE = 5;

struct Element { // data 배열을 Element 구조체 배열로 변경
    string name;
    int id;
};

void Error(string s) {cerr << s; exit(-1);}

class Queue{
protected:
  Element data[QUEUE_SIZE];
  int front, rear;
  int length;
public:
  Queue() {front = 0; rear = -1; length = 0;}
  void Insert(Element d);
  void Delete();
  void Peek();
  bool IsEmpty() {return length == 0;}
  bool IsFull() {return length == QUEUE_SIZE;}
  void PrintQueue();
  void PrintBuffer();
  int Length() {return length;}
};

void Queue::Insert(Element e){ //O(1)
  if(IsFull()) Error("Queue is full");
  rear = (rear + 1) % QUEUE_SIZE;
  data[rear] = e; length++;
}

void Queue::Delete(){ //O(1)
  if(IsEmpty()) Error("Queue is empty");
  Element out = data[front];
  cout << "name = " << data[front].name << ", id = " << data[front].id << endl;
  front = (front + 1) % QUEUE_SIZE; length--;
}

void Queue::Peek(){ //O(1)
  if(IsEmpty()) Error("Queue is empty");
  cout << "name = " << data[front].name << ", id = " << data[front].id << endl;
}

void Queue::PrintQueue(){ //O(n)
  cout << "Queue: ";
  for(int i = 0; i < length; i++){
    cout << data[front + i % QUEUE_SIZE].name << ", " << data[front + i % QUEUE_SIZE].id;
    cout << " ";
  }
  cout << endl;
}

void Queue::PrintBuffer(){ // O(n)
  cout << "Buffer: front = " << front;
  cout << "; rear = " << rear << "; ";
  for(int i = 0; i < QUEUE_SIZE; i++){
    if((front <= i && i <= front + length - 1) || (rear - length + 1 <= i && i <= rear))
      cout << data[i].name << ", " << data[i].id << " ";
    else 
      cout << "__";
    }
  cout << endl;
}