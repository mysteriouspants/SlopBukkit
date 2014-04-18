/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140418, Chapter 18 Programming Challenge 1 - 5
 */

#include <iostream>
#include "stack.hpp"
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

  return 0;
}
