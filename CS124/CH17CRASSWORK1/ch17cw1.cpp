/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140411, Chapter 17 Class Work 1
 */

#include "clinked_list.hpp"
#include <iostream>
using namespace std;

int main(int args, const char* argv[]) {
  typedef size_t customer_id;
  clinked_list<customer_id> service_q;

  for (customer_id moron = 7; moron < 14; moron++) {
    service_q.append(moron);
  }

  cout << "customer queue: "; service_q.print();
  cout << "servicing first customer: " << service_q[0] << endl;
  service_q.remove(service_q[0]);
  cout << "adding another moron to the queue: ";
  service_q.append(69); service_q.print();

  // i could keep doing this for a long time, but i won't because
  // that'd be superfluous to proving the workability of the list.

  return 0;
}
