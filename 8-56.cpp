#include <iostream>
using namespace std;
typedef char Data;
class Node{
  Data data; // 데이터 타입의 data
  Node* next; // 노드의 주소를 가르키는 next노드
  Node(Data d, Node* n){data = d; next = n;}
  friend class LinkedList;
};

class LinkedList{
  Node* head; // 노드의 주소를 가르키는 head 노드
  void PrintList(Node* n){ // 노드의 주소를 가르키는 n
    if(n == NULL) return; // 리스트의 끝이면 stop
    cout << n->data << " => "; // 노드의 데이터 출력
    PrintList(n->next); // 노드 클래스에 있는 next 노드 주소 전달
  }
  Node* InsertRear(Node* n, Data d){ // 노드의 주소 타입
    if(n == NULL) // 리스트의 마지막이면 
      return new Node(d, NULL); // 새로운 노드 생성
    n->next = InsertRear(n->next, d); // 노드 클래스에 있는 next 노드 주소 = InserRear()
    return n;
  }
public:
  LinkedList() {head = NULL;}
  void PrintList(){
    cout << "[head] => ";
    PrintList(head); // head부터 출력
    cout << "[null]" << endl;
  }
  void InsertRear(Data d){
    head = InsertRear(head, d);
  }
};

int main(){
  LinkedList a;
  a.InsertRear('A');
  a.InsertRear('B');
  a.InsertRear('C');
  a.PrintList();
  return 0;
}