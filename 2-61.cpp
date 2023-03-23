#include <iostream>
using namespace std;

int main(){
  char* s1 = NULL; // 문자 배열 포인터
  int num = 12;
  s1 = new char[num]; // 메모리 할당
  string s2 = "Hello World"; // 문자열 생성 (문자 배열과 다름)
  for(int i = 0; i < num; i++){ // 할당된 메모리에 문자열 저장
    s1[i] = s2[i];
  }
  cout << s1 << endl;
  delete[] s1; // 메모리 회수
  return 0;
}
/* 문자열 포인터를 사용한 풀이
#include <iostream>
using namespace std;

int main(){
  string* s1 = NULL; // 문자형 포인터
  int num = 12;
  s1 = new string; // 메모리 할당
  *s1 = "Hello World";
  cout << *s1 << endl;
  delete s1; // 메모리 회수
  return 0;
}
*/