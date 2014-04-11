/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140411, Chapter 17 Class Work 0
 */

#include "linked_list.hpp"
#include <iostream>
using namespace std;

int main(int args, const char* argv[]) {
  linked_list<int> foo;

  for (int i = 9; i > 0; i -= 2) {
    foo.insert(i);
  }
  foo.print();

  foo.clear();

  for (int i = 2; i < 11; i += 2) {
    foo.insert(i);
  }
  foo.print();

  return 0;
}
