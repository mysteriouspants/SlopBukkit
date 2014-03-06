/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140304, Chapter 14 Programming Challenge 1
 */

#include "numbers.hpp"

#include <iostream>

std::map<size_t, std::string> Numbers::cardinal_types_en = {
	{1, 		"one"},
	{2, 		"two"},
	{3, 		"three"},
	{4, 		"four"},
	{5, 		"five"},
	{6, 		"six"},
	{7, 		"seven"},
	{8, 		"eight"},
	{9, 		"nine"},
	{10, 		"ten"},
	{11, 		"eleven"},
	{12, 		"twelve"},
	{13, 		"thirteen"},
	{14, 		"fourteen"},
	{15, 		"fifteen"},
	{16, 		"sixteen"},
	{17, 		"seventeen"},
	{18, 		"eighteen"},
	{19, 		"nineteen"},
	{20, 		"twenty"},
	{30, 		"thirty"},
	{40, 		"forty"},
	{50, 		"fifty"},
	{60, 		"sixty"},
	{70, 		"seventy"},
	{80, 		"eighty"},
	{90, 		"ninety"}
};

std::vector<std::string> Numbers::major_ordinal_types_en = {
	"",
	"thousand",
	"million",
	"billion",
	"trillion"
};

Numbers::Numbers(unsigned int the_value) : _the_value(the_value) { }

void Numbers::print() {
	// split into major ordinal delineations
	std::vector<size_t> major_ordinal_delineations;
	std::string anglicized_number = "";

	for (size_t value = _the_value; value != 0; value = value / 1000) {
		major_ordinal_delineations.push_back(value % 1000);
	}

	for (size_t i = major_ordinal_delineations.size() -1; i != -1; --i) {
		anglicized_number += anglicize_minor_ordinal(major_ordinal_delineations[i]);
		if (i > 0) {
			anglicized_number += " ";
			anglicized_number += major_ordinal_types_en[i];
			anglicized_number += " ";
		}
	}

	std::cout << "number is:  " << _the_value << std::endl;
	std::cout << "anglicized: " << anglicized_number << std::endl;
}

std::string Numbers::anglicize_minor_ordinal(size_t minor_ordinal) {
	std::string anglicized_number = "";
	size_t hundreds = minor_ordinal / 100;
	if (hundreds > 0) {
		anglicized_number += anglicize_minor_ordinal(hundreds);
		anglicized_number += " hundred ";
	}
	size_t tens = minor_ordinal % 100;
	if (tens > 20) {
		if (tens % 10 == 0 && hundreds > 0) {
			anglicized_number += "and ";
		}
		anglicized_number += cardinal_types_en[tens - (tens % 10)];
		if (tens % 10 != 0) {
			anglicized_number += "-";
			anglicized_number += cardinal_types_en[tens % 10];
		}
	} else {
		anglicized_number += cardinal_types_en[tens];
	}
	return anglicized_number;
}