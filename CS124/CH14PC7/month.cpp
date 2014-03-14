/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140313, Chapter 14 Programming Challenge 7
 */

#include "month.hpp"
#include <algorithm>
#include <exception>

map<uint16_t,string> month::numbers_to_months = {
	{1,"January"},
	{2,"February"},
	{3,"March"},
	{4,"April"},
	{5,"May"},
	{6,"June"},
	{7,"July"},
	{8,"August"},
	{9,"September"},
	{10,"October"},
	{11,"November"},
	{12,"December"}
};

map<string,uint16_t> month::months_to_numbers = {
	{"January",1},
	{"February",2},
	{"March",3},
	{"April",4},
	{"May",5},
	{"June",6},
	{"July",7},
	{"August",8},
	{"September",9},
	{"October",10},
	{"November",11},
	{"December",12}
};

month::month() : name(numbers_to_months[1]), number(1) {}
month::month(string _name_) {
	setName(_name_);
}
month::month(uint16_t _number_) {
	setNumber(_number_);
}

string month::getName() const {
	return name;
}
uint16_t month::getNumber() const {
	return number;
}

void month::setName(string& _name_) {
	auto result = months_to_numbers.find(_name_);
	if (result != months_to_numbers.end()) {
		name = _name_;
		number = result->second;
	} else {
		throw invalid_argument("month is not a valid");
	}
}
void month::setNumber(uint16_t _number_) {
	if (_number_ > 12) {
		throw invalid_argument("number is not a valid");
	}
	number = _number_;
	name = numbers_to_months.find(_number_)->second;
}

month month::operator++() { // prefix
	setNumber(number==12?1:1+number);
	return *this;
}
month month::operator++(int) { // postfix
	month t(number);
	operator++();
	return t;
}

month month::operator--() { // prefix
	setNumber(number==1?12:number-1);
	return *this;
}
month month::operator--(int) { // postfix
	month t(number);
	operator--();
	return t;
}

ostream& operator<<(ostream& os,const month& _month_) {
	os << _month_.getName();
	return os;
}
istream& operator>>(istream& is,month& _month_) {
	uint16_t i;
	is >> i;
	_month_ = month(i);
	return is;
}