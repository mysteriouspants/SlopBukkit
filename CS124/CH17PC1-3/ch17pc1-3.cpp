/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140404, Chapter 17 Programming Challenge 1 - 3
 */

#include "linked_list.hpp"

int main(int args, const char* argv[]) {
  linked_list<int> foo;

  foo.print();
  foo.append(1);
  foo.append(2);
  foo.print();
  foo.insert(3);
  foo.print();

  foo.remove(2);
  foo.print();

  linked_list<int> bar(foo);

  bar.print();

  return 0;
}
