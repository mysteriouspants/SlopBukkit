/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140319, Chapter 15 Programming Challenge 2
 */

#include "shift_supervisor.hpp"

ShiftSupervisor::ShiftSupervisor() : Employee(), annual_salary(0.0f), annual_production_bonus(0.0f) { }

ShiftSupervisor::ShiftSupervisor(
	string name,
	size_t number,
	time_t hire_date,
	double annual_salary,
	double annual_production_bonus) 
	: 	Employee(name,number,hire_date),
		annual_salary(annual_salary),
		annual_production_bonus(annual_production_bonus) { }

double ShiftSupervisor::get_annual_salary() const {
	return annual_salary;
}

double ShiftSupervisor::get_annual_production_bonus() const {
	return annual_production_bonus;
}

void ShiftSupervisor::set_annual_salary(double annual_salary) {
	this->annual_salary = annual_salary;
}

void ShiftSupervisor::set_annual_production_bonus(double annual_production_bonus) {
	this->annual_production_bonus = annual_production_bonus;
}