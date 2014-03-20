/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140319, Chapter 15 Programming Challenge 1
 */

#include "employee.hpp"

Employee::Employee() : name(""), number(0), hire_date(time(NULL)) { }

Employee::Employee(string _name, size_t _number, time_t _hire_date) :
 name(_name), number(_number), hire_date(_hire_date) { }

string Employee::get_name() const {
	return name;
}

size_t Employee::get_number() const {
	return number;
}

time_t Employee::get_hire_date() const {
	return hire_date;
}

void Employee::set_name(string& _name) {
	name = _name;
}

void Employee::set_number(size_t _number) {
	number = _number;
}

void Employee::set_hire_date(time_t _hire_date) {
	hire_date = _hire_date;
}