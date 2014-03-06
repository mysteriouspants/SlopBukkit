/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140304, Chapter 14 Programming Challenge 1
 */

 #include <iostream>
 #include <vector>
 #include <string>

 #include "numbers.hpp"

 int main(int args, const char* argv[]) {

 	std::vector<size_t> numbers = {
 		7, 28, 342, 2398, 98239, 327890
 	};

 	for (auto iter = numbers.begin();
 		 iter != numbers.end();
 		 iter++) {
 		Numbers n(*iter);
 		n.print();
 	}

 	return 0;
 }
