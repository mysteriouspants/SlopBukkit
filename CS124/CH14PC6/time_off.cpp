/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140307, Chapter 14 Programming Challenge 6
 */

#include <exception>
#include "time_off.hpp"

 TimeOff::TimeOff(size_t id,string name,
 	size_t maxSickDays,size_t sickTaken,
 	size_t maxVacation,size_t vacTaken,
 	size_t maxUnpaid,size_t unpaidTaken) :
 _id(id), _name(name),
 _maxSickDays(maxSickDays), _sickTaken(sickTaken),
 _maxVacation(maxVacation), _vacTaken(vacTaken),
 _maxUnpaid(maxUnpaid), _unpaidTaken(unpaidTaken) {
 	if (_maxVacation.getHours() > 270) {
 		throw invalid_argument("cannot have more than max vacation");
 	}
 }

size_t TimeOff::getId() const {
	return _id;
}

string TimeOff::getName() const {
	return _name;
}

NumDays TimeOff::getMaxSickDays() const {
	return _maxSickDays;
}

NumDays TimeOff::getSickTaken() const {
	return _sickTaken;
}

NumDays TimeOff::getMaxVacation() const {
	return _maxVacation;
}

NumDays TimeOff::getVacTaken() const {
	return _vacTaken;
}

NumDays TimeOff::getMaxUnpaid() const {
	return _maxUnpaid;
}

NumDays TimeOff::getUnpaidTaken() const {
	return _unpaidTaken;
}


void TimeOff::setId(size_t id) {
	_id = id;
}

void TimeOff::setName(string& name) {
	_name = name;
}

void TimeOff::setMaxSickDays(NumDays& maxSickDays) {
	_maxSickDays = maxSickDays;
}

void TimeOff::setSickTaken(NumDays& sickTaken) {
	_sickTaken = sickTaken;
}

void TimeOff::setMaxVacation(NumDays& maxVacation) {
	if (maxVacation.getHours() > 270) {
		throw invalid_argument("cannot have more than max vacation");
	}
	_maxVacation = maxVacation;
}

void TimeOff::setVacTaken(NumDays& vacTaken) {
	_vacTaken = vacTaken;
}

void TimeOff::setMaxUnpaid(NumDays& maxUnpaid) {
	_maxUnpaid = maxUnpaid;
}

void TimeOff::setUnpaidTaken(NumDays& unpaidTaken) {
	_unpaidTaken = unpaidTaken;
}