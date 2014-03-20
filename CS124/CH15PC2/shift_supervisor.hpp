/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140319, Chapter 15 Programming Challenge 2
 */

#include <string>
#include <ctime>
#include <cstddef>
#include "employee.hpp"
using namespace std;

#ifndef __SHIFT_SUPERVISOR_HPP__
#define __SHIFT_SUPERVISOR_HPP__

class ShiftSupervisor : public Employee {
	double annual_salary;
	double annual_production_bonus;
public:
	ShiftSupervisor();
	ShiftSupervisor(string,size_t,time_t,double,double);

	double get_annual_salary() const;
	double get_annual_production_bonus() const;

	void set_annual_salary(double);
	void set_annual_production_bonus(double);
};

#endif