/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090920, Pg 334 # 2
 */

#include "NamePair.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

fsdev::Name_pairs::Name_pairs() {
	
}

std::vector<std::string> fsdev::Name_pairs::getNames() { return names; }
std::vector<double> fsdev::Name_pairs::getAges() { return ages; }

void fsdev::Name_pairs::setNames(std::vector<std::string> _names) { names = _names; }
void fsdev::Name_pairs::setAges(std::vector<double> _ages) { ages = _ages; }

void fsdev::Name_pairs::read_names() {
	do {
		std::string in;
		std::cin >> in;
		if(in == "done")
			break;
		else
			names.push_back(in);
	} while ( true ) ;
}
void fsdev::Name_pairs::read_ages() {
	double d;
	for(size_t i=0; i<names.size(); ++i) {
		std::cout << names[i] << "(" << i << "): ";
		std::cin >> d;
		ages.push_back(d);
	}
}

void fsdev::Name_pairs::print() {
	for(size_t i=0; i<names.size(); ++i)
		std::cout << "name: " << names[i] << " age: " << ages[i] << std::endl;
}
void fsdev::Name_pairs::sort() {
	std::vector<std::string> oldNames(names.begin(), names.end());
	std::vector<double> oldAges(ages.begin(), ages.end());
	
	std::sort(names.begin(),names.end());
	
	for(size_t i=0; i<names.size(); ++i)
		ages[i]=oldAges[
						std::distance(oldNames.begin(),std::find(
																  oldNames.begin(),
																  oldNames.end(),
																  names[i])
									  )
						];
}
