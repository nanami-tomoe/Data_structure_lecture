#include <iostream>
using namespace std;
typedef int Data;
struct Node{
  Data data;
  Node* left; Node* right;
  Node(Data d, Node* l = NULL, Node* r = NULL) 
    { data = d; left = l; right = r; }
};
class BinaryTree{
protected:
  Node* root;
  void PrintInorder(Node* n){
    if(n == NULL) return;
    PrintInorder(n->left);
    cout << n->data << " ";
    PrintInorder(n->right);
  }
public: 
  BinaryTree(Node* n = NULL) { root = n; }
  void PrintInorder() { PrintInorder(root); }
};

int main(){
  Node* n7 = new Node(30);
  Node* n6 = new Node(10);
  Node* n5 = new Node(50);
  Node* n4 = new Node(20, n6, n7);
  Node* n3 = new Node(70);
  Node* n2 = new Node(40, n4, n5);
  Node* n1 = new Node(60, n2, n3);
  BinaryTree b(n1);
  cout << "Inorder: ";
  b.PrintInorder();
  return 0;
}