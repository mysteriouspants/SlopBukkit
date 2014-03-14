/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140313, Chapter 14 Programming Challenge 7
 */

#include <string>
#include <map>
#include <iostream>
#include <cstddef>
using namespace std;

class month {
	string name;
	uint16_t number;
	static map<uint16_t,string> numbers_to_months;
	static map<string,uint16_t> months_to_numbers;
public:
	month();
	month(string);
	month(uint16_t);

	string getName() const;
	uint16_t getNumber() const;

	void setName(string&);
	void setNumber(uint16_t);

	month operator++(); // prefix
	month operator++(int); // postfix

	month operator--(); // prefix
	month operator--(int); // postfix
};

ostream& operator<<(ostream&,const month&);
istream& operator>>(istream&,month&);