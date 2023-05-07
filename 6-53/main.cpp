#include "ArrayList.h"

void ArrayList::DeleteAll(int key){
  for(int j = 0; j < length; j++){
    if(data[j] == key){
      for(int i = j; i < length; i++){
      data[i] = data[i+1];
      }
      length--;
      }
  }
}

int main(){
  ArrayList a; 
  a.InsertPos(0, 1);
  a.InsertPos(0, 2);
  a.InsertPos(0, 1);
  a.InsertPos(0, 2);
  a.InsertPos(0, 1);
  a.InsertPos(0, 2);
  a.InsertPos(0, 1);
  a.PrintList();
  a.DeleteAll(1);
  a.PrintList();
}