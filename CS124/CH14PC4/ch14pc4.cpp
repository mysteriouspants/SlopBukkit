/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140307, Chapter 14 Programming Challenge 4
 */

#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include "num_days.hpp"
using namespace std;

int main(int args, const char* argv[]) {
  // test the basics
  map<size_t,float> test_guantlet = {
    { 8, 1.0f },
    { 12,1.5f },
    { 18,2.25f}
  };

  for (pair<size_t,float> elem : test_guantlet) {
    NumDays n(elem.first);
    cout << "hour(s): " << elem.first;
    cout << " day(s):  " << n.getDays() << endl;
    if (n.getDays() != elem.second) {
      cout << "ERROR: Expectation not met." << endl;
    }
  }

  // test the operators
  NumDays n4(4);
  cout << "n4h+n4h=" << (n4+n4).getDays() << "d" << endl;
  cout << "n4h-n4h=" << (n4-n4).getDays() << "d" << endl;
  cout << "n4h++  =" << (n4++).getDays() << "d" << endl;
  cout << "n4h    =" << n4.getDays() << "d" << endl;
  cout << "n4h--  =" << (n4--).getDays() << "d" << endl;
  cout << "n4h    =" << n4.getDays() << "d" << endl;

  return 0;
}
