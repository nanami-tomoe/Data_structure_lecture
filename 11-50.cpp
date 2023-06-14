#include <iostream>
#include <cstdlib>
#include "StackTemplate.h"
using namespace std;
#define GRAPH_SIZE 20
const char NONE = '.';

class PathFinding{
  char label[GRAPH_SIZE];
  bool adjacent[GRAPH_SIZE][GRAPH_SIZE];
  int degree[GRAPH_SIZE];
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
  }

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
  }
public:
  PathFinding(){
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
  void DeleteEdge(int n, int m){
    CheckIndex(n); CheckIndex(m);
    adjacent[n][m] = adjacent[m][n] = false;
    degree[n]--; degree[m]--;
  }

  void FindPath(int source, int dest){
    cout << "Path from " << label[source] << " to " << label[dest] << ": ";
    destination = dest; found = false;
    ResetVisited();
    DepthFirstSearch(source);
    if(found == false) cout << "Not found";
    while(s.IsEmpty() == false)
      cout << label[s.Pop()] << " ";
    cout << endl;
  }
};

int main(){
  PathFinding g;
  g.InsertVertex(0, 'S');
  g.InsertVertex(1, 'A');
  g.InsertVertex(2, 'B');
  g.InsertVertex(3, 'C');
  g.InsertVertex(4, 'D');
  g.InsertEdge(0, 1);
  g.InsertEdge(0, 2);
  g.InsertEdge(1, 2);
  g.InsertEdge(2, 3);
  g.InsertEdge(3, 4);
  g.FindPath(0, 4);
  g.DeleteEdge(2, 3);
  g.FindPath(0, 4);
  return 0;
}