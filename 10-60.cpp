#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Data;
const int SEARCH_FAILED = -1000000;

class Node{
public:
  Data data;
  Node* left; Node* right;
  Node(Data d, Node* l = NULL, Node* r = NULL){
    data = d; left = l; right = r;
  }
};

class BinarySearchTree{
protected:
  Node* root;
  int Key(Data d){return d;}
  Node* Insert(Node* n, Data d){
    if(n == NULL) return new Node(d);
    if(Key(d) < Key(n->data)) n->left = Insert(n->left, d);
    else n->right = Insert(n->right, d);
    return n;
  }
  Data Search(Node* n, int key){
    if(n == NULL) return SEARCH_FAILED;
    if(key == Key(n->data)) return n->data;
    else if (key < Key(n->data)) return Search(n->left, key);
    else return Search(n->right, key);
  }
public:
  void Insert(Data d){root = Insert(root, d);}
  Data Search(int key){return Search(root, key);}
  void PrintData(Data d){
    if(Key(d) == SEARCH_FAILED) cout << "Search failed" << endl;
    else cout << Key(d) << " is found" << endl;
  }
};

int main(){
  BinarySearchTree b;
  const int SIZE = 10;
  int a[SIZE] = {40, 20, 60, 10, 30, 50, 70, 5, 15, 25};
  for(int i = 0; i < SIZE; i++){
    b.Insert(a[i]);
  }
  b.PrintData(b.Search(50));
  b.PrintData(b.Search(51));
  return 0;
}