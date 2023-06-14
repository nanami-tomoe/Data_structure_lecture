#include <iostream>
#include <cstdlib>
#include "StackTemplate.h"
#define GRAPH_SIZE 20
const char NONE = '.';

class PathFinding{
  char label[GRAPH_SIZE];
  bool adjacent[GRAPH_SIZE][GRAPH_SIZE];
  int inDegree[GRAPH_SIZE];
  int outDegree[GRAPH_SIZE]; // directed graph 라서 추가됨
  bool visited[GRAPH_SIZE];
  int graphSize; 
  void ResetVisited(){
    for(int i = 0; i < GRAPH_SIZE; i++){
      visited[i] = false;
    }
  }
  void CheckIndex(int n){
    if(n < 0 || n >= GRAPH_SIZE)
      Error("Illegal index");
  } // directedgraph 코드 추가

  int destination;
  bool found;
  StackTemplate <int> s;
  void DepthFirstSearch(int n){
    if(found || visited[n]) return;
    visited[n] = true;
    if(n == destination) found = true;
    for(int i = 0; i < GRAPH_SIZE; i++){
      if(adjacent[n][i]) DepthFirstSearch(i);
    }
    if(found) s.Push(n);
  } // 교안 코드
public:
  PathFinding(){ // 생성자
    for(int i = 0; i < GRAPH_SIZE; i++){
      label[i] = NONE; // occupied 방지
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
  }// directedgraph 내용 추가

  void FindPath(int source, int dest){
    cout << "Path from " << label[source] << " to " << label[dest] << ": ";
    destination = dest; found = false;
    ResetVisited();
    DepthFirstSearch(source);
    if(found == false) cout << "Not found";
    while(s.IsEmpty() == false)
      cout << label[s.Pop()] << " ";
    cout << endl;
  } // 교안 코드
};

int main(){
  PathFinding g;
  g.InsertVertex(0, 'A');
  g.InsertVertex(1, 'B');
  g.InsertVertex(2, 'C');
  g.InsertVertex(3, 'D');
  g.InsertVertex(4, 'E');
  g.InsertVertex(5, 'F');
  g.InsertEdge(0, 1);
  g.InsertEdge(1, 2);
  g.InsertEdge(2, 0);
  g.InsertEdge(2, 3);
  g.InsertEdge(3, 4);
  g.InsertEdge(4, 5);
  g.InsertEdge(5, 3);
  g.FindPath(0, 5);
  g.FindPath(5, 0); // 거꾸로는 탐색 불가
  return 0;
}