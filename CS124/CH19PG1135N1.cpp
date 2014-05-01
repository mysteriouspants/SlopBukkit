#include <iostream>
#include <cstddef>
using namespace std;

template<class T>
T iternacci(T n) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  
  T prevPrev = 0;
  T prev = 1;
  T result = 0;
      
  for (T i = 2; i <= n; i++) {
    result = prev + prevPrev;
    prevPrev = prev;
    prev = result;
  }
  return result;
}

int main(int argc, char *argv[]) {
  for (size_t i = 0; i < 90; i++) {
    cout << "iternacci(" << i << "): " << iternacci(i) << endl;
  }
 
  return 0;
}