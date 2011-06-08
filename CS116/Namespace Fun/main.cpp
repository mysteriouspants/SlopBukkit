/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090920, Ch 8 Lab 3
 */

#include <iostream>

namespace X {
	int var;
	void print();
}

namespace Y {
	int var;
	void print();
}

namespace Z {
	int var;
	void print();
}

int main (int argc, char * const argv[]) {
	X::var = 7;
	X::print();		// print X's var
	using namespace Y;
	var = 9;
	print();		// print Y's var
	{	using Z::var;
		using Z::print;
		var = 11;
		print();	// print Z's var
	}
	print();		// print Y's var
	X::print();		// print X's var
    return 0;
}

void X::print() {
	std::cout << var << std::endl;
}

void Y::print() {
	std::cout << var << std::endl;
}

void Z::print() {
	std::cout << var << std::endl;
}
