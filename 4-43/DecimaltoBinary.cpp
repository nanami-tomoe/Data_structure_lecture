#include "Stack.h"

int main(){
  Stack s;
  char str[] = "12a34b56";
  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] >= '0' && str[i] <= '9'){
      s.Push(str[i]-'0');
    }
    else;
  }
  while(s.IsEmpty() == false){
    cout << s.Pop();
  }
  cout << endl;
  return 0;
}