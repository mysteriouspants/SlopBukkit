/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140319, Chapter 15 Programming Challenge 2
 */

#include "employee.hpp"
#include <cstddef>
#include <string>
#include <ctime>
using namespace std;

#ifndef __PRODUCTION_WORKER_HPP__
#define __PRODUCTION_WORKER_HPP__

class ProductionWorker : public Employee {
	uint8_t shift;
	double hourly_pay_rate;
public:
	ProductionWorker();
	ProductionWorker(string,size_t,time_t,uint8_t,double);

	uint8_t get_shift() const;
	double get_hourly_pay_rate() const;

	void set_shift(uint8_t);
	void set_hourly_pay_rate(double);
};

#endif