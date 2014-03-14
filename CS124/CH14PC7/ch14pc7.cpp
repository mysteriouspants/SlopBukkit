/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140313, Chapter 14 Programming Challenge 7
 */

#include <iostream>
#include <string>
#include "month.hpp"
using namespace std;

int main(int args, const char* argv[]) {
	month m(1);

	cout << "1 = " << m << endl;
	cout << "1++ = " << m++ << endl;
	cout << "2 = " << m << endl;
	cout << "--2 = " << --m << endl;

	cout << "Please emit a number between 1 and 12: ";
	cin >> m;
	cout << m.getNumber() << " = " << m << endl;

	return 0;	
}