/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140306, Chapter 14 Programming Challenge 3
 */

#include <map>
#include <utility> // for std::pair
#include <string>

class DayOfYear {
	size_t _day_of_year;
	static std::map<size_t,std::pair<std::string,size_t>> months_en;
public:
	DayOfYear(size_t);
	DayOfYear(std::string,size_t);
	void print();
	void operator--();
	void operator++();
};