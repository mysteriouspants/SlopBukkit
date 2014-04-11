/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140410, Chapter 17 Programming Challenge 3 - 7
 */

#include "linked_list.hpp"
#include <iostream>
using namespace std;

int main(int args, const char* argv[]) {
  linked_list<int> foo;

  cout << "empty list: ";
  foo.print();
  foo.append(1);
  foo.append(2);
  cout << "2-element list: ";
  foo.print();
  foo.prepend(3);
  cout << "3-element list: ";
  foo.print();

  cout << "reverse!: ";
  foo.reverse();
  foo.print();

  cout << "location of 2: " << foo.search(2) << endl;
  cout << "location of 3: " << foo.search(3) << endl;
  cout << "location of 1: " << foo.search(1) << endl;
  cout << "location of 100: " << foo.search(100) << endl;

  cout << "result after inserting 42 at position 3: ";
  foo.insert(42, 3); foo.print();
  cout << "result after inserting 69 at position 2: ";
  foo.insert(69, 2); foo.print();

  cout << "4-element list: ";
  foo.remove(2);
  foo.print();

  linked_list<int> bar(foo);

  cout << "copy of 2-element list: ";
  bar.print();

  return 0;
}
