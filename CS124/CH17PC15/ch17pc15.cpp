/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140417, Chapter 17 Programming Challenge 15
 */

#include "linked_list.hpp"
#include <iostream>
using namespace std;

int main(int args, const char* argv[]) {
  linked_list<int> foo;

  cout << "empty list: ";
  foo.print();

  foo.push_back(1);
  foo.push_back(2);
  cout << "2-element list: ";
  foo.print();

  foo.push_front(3);
  cout << "3-element list: ";
  foo.print();

  cout << "reverse!: ";
  foo.reverse();
  foo.print();

  cout << "last element is: " << foo.pop_back() << endl;
  cout << "first element is: " << foo.pop_front() << endl;
  cout << "destructively manipulated list is: ";
  foo.print();

  return 0;
}
