#include <iostream>
#include <cstdlib>
using namespace std;
#define GRAPH_SIZE 20
const char NONE = '.';
void Error(string s){cerr << s; exit(-1);}
class DirectedGraph{
protected:
  char label[GRAPH_SIZE];
  bool adjacent[GRAPH_SIZE][GRAPH_SIZE];
  int inDegree[GRAPH_SIZE];
  int outDegree[GRAPH_SIZE]; // directed graph 라서 추가됨
  bool visited[GRAPH_SIZE];
  int graphSize;
  void CheckIndex(int n){
    if(n < 0 || n >= GRAPH_SIZE)
      Error("Illegal index");
  }
  void VisitVertex(int n){
    visited[n] = true;
    cout << label[n] << " ";
  }
  void DepthFirstSearchRecursion(int n){
    if(visited[n]) return;
    VisitVertex(n);
    for(int i = 0; i < GRAPH_SIZE; i++){
      if(adjacent[n][i]){
        DepthFirstSearchRecursion(i);
      }
    }
  }
public:
  DirectedGraph(){
    for(int i = 0; i < GRAPH_SIZE; i++){
      label[i] = NONE;
      outDegree[i] = inDegree[i] = 0;
      visited[i] = false;
      for(int j = 0; j < GRAPH_SIZE; j++){
        adjacent[i][j] = false;
      }
    }
  }
  void InsertVertex(int n, char c){
    CheckIndex(n);
    if(label[n] != NONE) Error("Occupied");
    label[n] = c; graphSize++;
  }
  void InsertEdge(int n, int m){
    CheckIndex(n); CheckIndex(m);
    adjacent[n][m] = true;
    outDegree[n]++; inDegree[m]++;
  }
  void PrintGraph(){
    for(int n = 0; n < GRAPH_SIZE; n++){
      if(label[n] == NONE) continue;
      cout << "Vertex " << label[n] << " has neighbor";
      for(int i = 0; i < GRAPH_SIZE; i++){
        if(adjacent[n][i]) cout << label[i] << " ";
      }
      cout << endl;
    }
  }
  void DepthFirstSearch(int n){
    ResetVisited();
    DepthFirstSearchRecursion(n);
  }
  void ResetVisited(){
    for(int i = 0; i < GRAPH_SIZE; i++){
      visited[i] = false;
    }
  }
};

int main(){
  DirectedGraph g;
  g.InsertVertex(0, 'A');
  g.InsertVertex(1, 'B');
  g.InsertVertex(2, 'C');
  g.InsertVertex(3, 'D');
  g.InsertVertex(4, 'E');
  g.InsertVertex(5, 'F');
  g.InsertVertex(6, 'G');
  g.InsertEdge(0, 1);
  g.InsertEdge(0, 2);
  g.InsertEdge(1, 3);
  g.InsertEdge(1, 4);
  g.InsertEdge(2, 5);
  g.InsertEdge(2, 6);
  cout << "Depth First Search: ";
  g.DepthFirstSearch(0);
  return 0;
}