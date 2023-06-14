#include <iostream>
#include <cstdlib>
using namespace std;
#define GRAPH_SIZE 20
const char NONE = '.';
void Error(string s){cerr << s; exit(-1);}
class Graph{
protected:
  char label[GRAPH_SIZE];
  bool adjacent[GRAPH_SIZE][GRAPH_SIZE];
  int degree[GRAPH_SIZE];
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
  Graph(){
    graphSize = 0;
    for(int i = 0; i < GRAPH_SIZE; i++){
      label[i] = NONE;
      degree[i] = 0;
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
    adjacent[n][m] = adjacent[m][n] = true;
    degree[n]++; degree[m]++;
  }
  void DeleteVertex(int n){
    CheckIndex(n);
    if(label[n] == NONE)
      Error("No vertex to delete");
    for(int i = 0; i < GRAPH_SIZE; i++){
      if(adjacent[n][i] || adjacent[i][n]){
        cout << "Delete deges first" << endl;
        return;
      }
    }
    label[n] = NONE; graphSize--;
  }
  void DeleteEdge(int n, int m){
    CheckIndex(n); CheckIndex(m);
    adjacent[n][m] = adjacent[m][n] = false;
    degree[n]--; degree[m]--;
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
  void PrintDegree(){
    for(int n = 0; n < GRAPH_SIZE; n++){
      if(label[n] == NONE) continue;
      cout << "Vertex " << label[n] << " has degree " << degree[n] << endl;
    }
  }
};

int main(){
  Graph g;
  g.InsertVertex(0, 'S');
  g.InsertVertex(1, 'A');
  g.InsertVertex(2, 'B');
  g.InsertVertex(3, 'C');
  g.InsertVertex(4, 'D');
  g.InsertVertex(5, 'E');
  g.InsertEdge(0, 1);
  g.InsertEdge(0, 2);
  g.InsertEdge(0, 3);
  g.InsertEdge(1, 4);
  g.InsertEdge(2, 4);
  g.InsertEdge(3, 5);
  g.InsertEdge(4, 5);
  g.PrintDegree();
  return 0;
}