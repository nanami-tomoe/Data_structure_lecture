#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Data;
const int LIST_SIZE = 10000;
const int SEARCH_FAILED = -100000;
void Error(string s){cerr << s; exit(-1);}

void CheckPos(int pos, int maxPos){
  if(pos < 0 || pos > maxPos)
    Error("Illegal position");
}

class ArrayList{
protected:
  Data data[LIST_SIZE];
  int length;
  virtual int Key(Data d){return d;}
public:   
  ArrayList(){length = 0;}
  void InsertPos(int pos, Data d){
    CheckPos(pos, length);
    if(IsFull())Error("List is full");
    for(int i = length; i > pos; i--){
      data[i] = data[i - 1];
    }
    data[pos] = d; length++;
  }
  Data DeletePos(int pos){
    CheckPos(pos, length);
    Data d = data[pos];
    for(int i = pos; i < length; i++){
      data[i] = data[i + 1];
    }
    length--; return d;
  }
  Data PeekPos(int pos){
    CheckPos(pos, length-1);
    return data[pos];
  }
  Data Search(int key){
    for(int i = 0; i < length; i++){
      if(Key(data[i]) == key) return data[i];
    }
    cout << key << "is not found" << endl;
    return SEARCH_FAILED;
  }
  void PrintList(){
    for(int i = 0; i < length; i++){
      cout << data[i] << " ";
    }
    cout << endl;
  }
  bool IsEmpty(){return length == 0;}
  bool IsFull(){return length == LIST_SIZE;}
  int Length(){return length;}
  void DeleteAll(int key); // key값을 가지는 모든 원소를 삭제하는 함수 추가
};