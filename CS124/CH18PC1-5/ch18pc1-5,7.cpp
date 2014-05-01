/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140422, Chapter 18 Programming Challenge 1 - 5, 7
 */

#include <iostream>
#include "stack.hpp"
#include "stack_calc.hpp"
#include "queue.hpp"
using namespace std;

int main(int args, const char* argv[]) {
  { cout << "\tSTATIC STACK BOLLOCKS" << endl;
    static_stack<int> foo(5);
    cout << "empty stack: ";
    foo.__pretty_print__();
    for (int i = 1; i < 6; ++i) { foo.push(i); }
    cout << "filled stack: ";
    foo.__pretty_print__();
    foo.pop();
    cout << "slightly less filled stack: ";
    foo.__pretty_print__();
  }

  { cout << "\tDYNAMIC STACK BOLLOCKS" << endl;
    dynamic_stack<int> foo;
    cout << "empty stack: ";
    foo.__pretty_print__();
    for (int i = 1; i < 6; ++i) { foo.push(i); }
    cout << "filled stack: ";
    foo.__pretty_print__();
    foo.pop();
    cout << "slightly less filled stack: ";
    foo.__pretty_print__();
  }

  { cout << "\tSTATIC QUEUE BOLLOCKS" << endl;
    static_queue<int> q(5);
    cout << "empty queue: ";
    q.__pretty_print__();
    for (int i = 1; i < 6; ++i) { q.enq(i); }
    cout << "filled queue: ";
    q.__pretty_print__();
    q.deq();
    cout << "slightly less filled queue: ";
    q.__pretty_print__();
  }

  { cout << "\tDYNAMIC QUEUE BOLLOCKS" << endl;
    dynamic_queue<int> q;
    cout << "empty queue: ";
    q.__pretty_print__();
    for (int i = 1; i < 6; ++i) { q.enq(i); }
    cout << "filled queue: ";
    q.__pretty_print__();
    q.deq();
    cout << "slightly less filled queue: ";
    q.__pretty_print__();
  }

  { cout << "\tSTATIC STACK CALC BOLLOCKS" << endl;
    static_stack_calc<int> c(5);
    cout << "empty stack: ";
    c.__pretty_print__();
    for (int i = 1; i < 6; ++i) { c.push(i); }
    cout << "filled stack: ";
    c.__pretty_print__();
    c.mult();
    cout << "multiplied topmost two elements: ";
    c.__pretty_print__();
    c.div();
    cout << "divided topmost two elements: ";
    c.__pretty_print__();
    c.add_all();
    cout << "added remaining elements: ";
    c.__pretty_print__();
    for (int i = 1; i < 5; ++i) { c.push(i); }
    cout << "repopulated: ";
    c.__pretty_print__();
    c.mult_all();
    cout << "multiplied remaining elements: ";
    c.__pretty_print__();
  }

  { cout << "\tDYNAMIC STACK CALC BOLLOCKS" << endl;
    dynamic_stack_calc<int> c;
    cout << "empty stack: ";
    c.__pretty_print__();
    for (int i = 1; i < 6; ++i) { c.push(i); }
    cout << "filled stack: ";
    c.__pretty_print__();
    c.mult();
    cout << "multiplied topmost two elements: ";
    c.__pretty_print__();
    c.div();
    cout << "divided topmost two elements: ";
    c.__pretty_print__();
    c.add_all();
    cout << "added remaining elements: ";
    c.__pretty_print__();
    for (int i = 1; i < 5; ++i) { c.push(i); }
    cout << "repopulated: ";
    c.__pretty_print__();
    c.mult_all();
    cout << "multiplied remaining elements: ";
    c.__pretty_print__();
  }

  return 0;
}
