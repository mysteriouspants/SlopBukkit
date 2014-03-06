/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140304, Chapter 14 Programming Challenge 1
 */

#include <map>
#include <vector>
#include <utility> // for pair
#include <string>

class Numbers {
	static std::map<size_t, std::string> cardinal_types_en;
	static std::vector<std::string> major_ordinal_types_en;
	unsigned int _the_value;

	std::string anglicize_minor_ordinal(size_t);
public:
	Numbers(unsigned int);
	void print();
};
