/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140306, Chapter 14 Programming Challenge 3
 */

#include "day_of_year.hpp"
#include <iostream>
#include <vector>

int main(int args, const char* argc[]) {
	std::vector<size_t> days_to_test = {
		3,
		43,
		87,
		244,
		300
	};

	for (auto iter = days_to_test.begin(); iter != days_to_test.end(); iter++) {
		DayOfYear day_of_year(*iter);
		day_of_year.print();
	}

	std::map<std::string,size_t> pairs_to_test = {
		{"January",3},
		{"February",12},
		{"March",28},
		{"September",1},
		{"October",27}
	};

	std::cout << std::endl;

	for (auto iter = pairs_to_test.begin(); iter != pairs_to_test.end(); iter++) {
		DayOfYear day_of_year(iter->first,iter->second);
		day_of_year.print();
	}

	return 0;
}