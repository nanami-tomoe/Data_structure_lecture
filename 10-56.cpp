#include <iostream>
#include <cstdlib>
using namespace std;
typedef string Data;

class Node{
public:
  Data data;
  Node* left; Node* right;
  Node(Data d, Node* l = NULL, Node* r = NULL){
    data = d; left = l; right = r;
  }
};

class StudentTree{
protected:
  Node* root;
  void PrintInorder(Node* n){
    if(n == NULL) return;
    PrintInorder(n->left);
    cout << "name: " << n->data << endl;
    PrintInorder(n->right);
  }
public:
  StudentTree(Node* n = NULL){root = n;}
  void PrintInorder(){PrintInorder(root);}
};

int main(){
  Data s1 = "Lee";
  Data s2 = "Kim";
  Data s3 = "Park";
  Node* n3 = new Node(s3);
  Node* n2 = new Node(s2);
  Node* n1 = new Node(s1, n2, n3);
  StudentTree b(n1);
  cout << "Inorder: " << endl;
  b.PrintInorder();
  return 0;
}