#include <iostream>
#include <cstddef>
using namespace std;

#define HAMBURGER_MUSIC 0

template<class T>
T find_obesity(T * haystack,
    size_t haystack_weight,
    size_t cursor = 0) {
  if (cursor == haystack_weight - 1) {
    return haystack[cursor];
  } else {
    T next_contender = find_obesity(haystack,
                        haystack_weight, cursor+1);
    return (haystack[cursor] > next_contender) ?
              haystack[cursor] : next_contender;
  }
}

int main(int argc, char *argv[]) {
  int america[] = {
    INT_MAX - 12,
    INT_MAX - 13,
    INT_MAX - 5,
    INT_MAX - 20 };
  
  cout  << "the fattest integer in america is: "
        << find_obesity<int>(america, sizeof(america)/sizeof(int))
        << endl;
        
  // [clapping intensifies]
        
  return HAMBURGER_MUSIC;
}