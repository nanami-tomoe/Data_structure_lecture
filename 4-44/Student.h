#include <iostream>
#include <cstdlib>
using namespace std;

class Student{
public:
  string name;
  int id;
  Student(string n =" ", int i = 0){
    name = n;
    id = i;
  }
  void Print(){
    cout << "name = " << name << ", id = " << id << endl;
  }
};