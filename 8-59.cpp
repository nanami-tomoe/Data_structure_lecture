#include <iostream>
using namespace std;
typedef int Data;
const int SEARCH_FAILED = -1000000;
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

class BinarySearchTree : public BinaryTree{ // public만 접근 가능
  Node* Insert(Node* n, Data d){
    if(n == NULL) return new Node(d);
    if(d < n->data) n->left = Insert(n->left, d);
    else n->right = Insert(n->right, d);
    return n;
  }
  Data Search(Node* n, int key){
    if(n == NULL) return SEARCH_FAILED;
    if(key == n->data) return n->data; // 찾으면 return
    else if(key < n->data)
      return Search(n->left, key);
    else 
      return Search(n->right, key);
  }
public:
  void Insert(Data d){
    root = Insert(root, d); // root 설정
  }
  Data Search(int key){
    return Search(root, key); // root 부터 search
  }
};

int main(){
  BinarySearchTree b;
  const int SIZE = 10;
  int a[SIZE] = {50, 27, 60, 15, 35, 55, 10, 19, 33, 42};
  for(int i = 0; i < SIZE; i++){
    b.Insert(a[i]);
  }
  b.PrintInorder();
  cout << endl;
  cout << b.Search(33);
  return 0;
}