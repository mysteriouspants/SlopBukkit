/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140306, Chapter 14 Programming Challenge 3
 */

#include "day_of_year.hpp"

#include <iostream>
#include <exception>

std::map<size_t,std::pair<std::string,size_t>> DayOfYear::months_en = {
	{ 0, 	{ "January", 	31 } },
	{ 1, 	{ "February", 	28 } },
	{ 2, 	{ "March", 		31 } },
	{ 3, 	{ "April", 		30 } },
	{ 4, 	{ "May", 		31 } },
	{ 5, 	{ "June", 		30 } },
	{ 6, 	{ "July", 		31 } },
	{ 7, 	{ "August",		31 } },
	{ 8, 	{ "September",	30 } },
	{ 9, 	{ "October", 	31 } },
	{ 10, 	{ "November", 	30 } },
	{ 11, 	{ "December", 	31 } }
};

DayOfYear::DayOfYear(size_t day_of_year) : _day_of_year(day_of_year) { }
DayOfYear::DayOfYear(std::string month, size_t day) {
	size_t elapsed_days = 0;
	size_t represented_month = 9001;

	for (auto iter = months_en.begin(); iter != months_en.end(); iter++) {
		if (iter->second.first == month) {
			represented_month = iter->first;
			break;
		} else {
			elapsed_days += iter->second.second;
		}
	}

	if (represented_month == 9001) {
		throw std::invalid_argument("invlaid month given");
	}

	_day_of_year = elapsed_days + day;
}

void DayOfYear::print() {
	size_t unelapsed_days = _day_of_year;
	size_t month = 9001;

	for (auto iter = months_en.begin(); iter != months_en.end(); iter++) {
		if (iter->second.second < unelapsed_days) {
			unelapsed_days -= iter->second.second;
		} else {
			month = iter->first;
			break;
		}
	}

	std::cout << months_en[month].first << " " << unelapsed_days << std::endl;
}
