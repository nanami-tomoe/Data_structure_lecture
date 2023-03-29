#include "SearchAlgorithm.h"
using namespace std;

class BinarySearch: public SearchAlgorithm{
public:  
  int Search(int a[], int key, int length){ // O(log n)
    int low = 0, mid, high = length - 1;
    while(low <= high){
      mid = (low + high)/2;
      cout << "key in [" << a[low] << " " << a[high] << "]: a[mid] = " << a[mid] << "\n";
      if(key == a[mid]) return mid; // found
      if(key < a[mid]) high = mid - 1; // left
      else low = mid + 1; // right
    }
  return SEARCH_FAILED;
  }
};

int main(){
  const int SIZE = 10;
  int a[SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int key = 5; // ket to find
  BinarySearch s;
  s.PrintLocation(s.Search(a, key, SIZE));
  return 0;
}