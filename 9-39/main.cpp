#include "ArrayTree.h"

int main(){
  ArrayTree a;
  a.InsertPos(1, 10);
  a.InsertPos(2, 20);
  a.InsertPos(3, 30);
  a.InsertPos(4, 40);
  a.InsertPos(5, 50);
  a.InsertPos(6, 60);
  a.InsertPos(7, 60);

  cout << "# of nodes = " << a.NumNode();
  cout << "; # of leaf nodes = " << a.NumLeaf();
  cout << endl << "Height of the tree = " << a.Height();
  return 0;
}