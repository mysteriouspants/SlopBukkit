/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140319, Chapter 15 Programming Challenge 1
 */

#include <string>
#include <ctime>
#include <cstddef>
using namespace std;

#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

class Employee {
	string name;
	size_t number;
	time_t hire_date;
public:
	Employee();
	Employee(string,size_t,time_t);

	string get_name() const;
	size_t get_number() const;
	time_t get_hire_date() const;

	void set_name(string&);
	void set_number(size_t);
	void set_hire_date(time_t);
};

#endif