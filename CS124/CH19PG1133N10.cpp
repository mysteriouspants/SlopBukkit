#include <iostream>
#include <cstddef>
using namespace std;

// roughly inspired by strtok_r
template<class T>
size_t arr_count_r(T * haystack, T needle, size_t haystack_size, size_t search_start = 0) {
  if (search_start == haystack_size - 1) {
    return haystack[search_start] == needle;
  } else {
    return (haystack[search_start] == needle) + arr_count_r(haystack, needle, haystack_size, search_start+1);
  }
}

int main(int argc, char *argv[]) {
  int toxic_farts[] = { 1, 2, 3, 2, 4, 7, 9 };
  
  int needle = 3;
  cout << "number of times " << needle << " appears in toxic_farts: "
       << arr_count_r<int>(toxic_farts, needle, sizeof(toxic_farts)/sizeof(int))
       << endl;
  
  return 0;
}