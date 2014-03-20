/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140319, Chapter 15 Programming Challenge 2
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <cstddef>
#include "employee.hpp"
#include "shift_supervisor.hpp"
using namespace std;

int main(int args, const char* argv[]) {
	string name = "Homer Simpson";
	size_t number = 342345;
	time_t hire_date = time(NULL);
	double annual_salary = 48000.00f;
	double annual_production_bonus = 4000.00f;
	
	ShiftSupervisor ss = ShiftSupervisor(name,number,hire_date,annual_salary,annual_production_bonus);

	assert(ss.get_name() == name);
	assert(ss.get_number() == number);
	assert(ss.get_hire_date() == hire_date);
	assert(ss.get_annual_salary() == annual_salary);
	assert(ss.get_annual_production_bonus() == annual_production_bonus);

	return 0;
}