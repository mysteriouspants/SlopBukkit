/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140319, Chapter 15 Programming Challenge 1
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <cstddef>
#include "employee.hpp"
#include "production_worker.hpp"
using namespace std;

int main(int args, const char* argv[]) {
	string name = "Homer Simpson";
	size_t number = 342345;
	time_t hire_date = time(NULL);
	uint8_t shift = 2;
	double hourly_pay_rate = 7.50f;

	ProductionWorker pw = ProductionWorker(name, number, hire_date, shift, hourly_pay_rate);

	assert(pw.get_name() == name);
	assert(pw.get_number() == number);
	assert(pw.get_hire_date() == hire_date);
	assert(pw.get_shift() == shift);
	assert(pw.get_hourly_pay_rate() == hourly_pay_rate);

	return 0;
}