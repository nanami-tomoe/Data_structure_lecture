#include <iostream>
using namespace std;
#define SEARCH_FAILED -1

class SearchAlgorithm{
public: // Abstract class
  void PrintLocation(int location){
    if(location != SEARCH_FAILED)
      cout << "Location = " << location << endl;
    else cout << "Search failed" << endl;
  }
  virtual int Search(int a[], int key, int length) = 0;
};