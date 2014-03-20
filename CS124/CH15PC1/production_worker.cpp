/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140319, Chapter 15 Programming Challenge 1
 */

#include "production_worker.hpp"

ProductionWorker::ProductionWorker() : 
	Employee(), shift(1), hourly_pay_rate(0) { }

ProductionWorker::ProductionWorker(
	string name,
	size_t number,
	time_t hire_date,
	uint8_t shift,
	double hourly_pay_rate)
	: 	Employee(name,number,hire_date),
		shift(shift),
		hourly_pay_rate(hourly_pay_rate) { }

uint8_t ProductionWorker::get_shift() const {
	return shift;
}

double ProductionWorker::get_hourly_pay_rate() const {
	return hourly_pay_rate;
}

void ProductionWorker::set_shift(uint8_t _shift) {
	shift = _shift;
}

void ProductionWorker::set_hourly_pay_rate(double _hourly_pay_rate) {
	hourly_pay_rate = _hourly_pay_rate;
}