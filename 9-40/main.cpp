#include "ArrayTree.h"
#define YES(pos) ((pos)*2)
#define No(pos) ((pos)*2 + 1)

int main(){
  ArrayTree a;
  char branch;
  int p1, p2, p3, p4, p5, p6 ,p7, p8, p9;
  a.InsertPos(p1 = ROOT, "시험 기간인가요?");
  a.InsertPos(p2 = YES(p1), "지금 공부하는 과목이 전공 과목인가요?");
  a.InsertPos(p3 = No(p1), "일단 보류하세요");
  a.InsertPos(p4 = YES(p2), "중간을 망쳤나요?");
  a.InsertPos(p5 = No(p2), "일단 보류하세요");
  a.InsertPos(p6 = YES(p4), "출석이 안좋나요?");
  a.InsertPos(p7 = No(p4), "일단 보류하세요");
  a.InsertPos(p8 = YES(p6), "1순위로 공부하세요");
  a.InsertPos(p9 = No(p6), "일단 보류하세요");
  a.PrintLevelOrder();
  int pos = ROOT;
  while(a.IsNone(pos) == false){
    cout << a.PeekPos(pos);
    if(a.IsLeaf(pos)) break;
    cout << "(Y/N): ";
    cin >> branch;
    if(branch == 'Y') pos = YES(pos);
    else if(branch == 'N') pos = No(pos);
  }
  return 0;
}
