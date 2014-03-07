/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140307, Chapter 14 Programming Challenge 6
 */

#include <string>
#include <cstddef>
#include "num_days.hpp"
using namespace std;

#ifndef TIMEOFF_HPP
#define TIMEOFF_HPP

class TimeOff {
	size_t  _id;
	string  _name;
	NumDays _maxSickDays;
	NumDays _sickTaken;
	NumDays _maxVacation; // always always eq 240
	NumDays _vacTaken;
	NumDays _maxUnpaid;
	NumDays _unpaidTaken;
public:
	TimeOff(size_t,string,size_t,size_t,size_t,size_t,size_t,size_t);

	size_t getId() const;
	string getName() const;
	NumDays getMaxSickDays() const;
	NumDays getSickTaken() const;
	NumDays getMaxVacation() const;
	NumDays getVacTaken() const;
	NumDays getMaxUnpaid() const;
	NumDays getUnpaidTaken() const;

	void setId(size_t);
	void setName(string&);
	void setMaxSickDays(NumDays&);
	void setSickTaken(NumDays&);
	void setMaxVacation(NumDays&);
	void setVacTaken(NumDays&);
	void setMaxUnpaid(NumDays&);
	void setUnpaidTaken(NumDays&);
};

#endif