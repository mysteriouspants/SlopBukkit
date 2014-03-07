/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140307, Chapter 14 Programming Challenge 6
 */

#include "num_days.hpp"

NumDays::NumDays(size_t hours) : _hours(hours) { }

size_t NumDays::getHours() const {
  return _hours;
}

void NumDays::setHours(const size_t hours) {
  _hours = hours;
}

float NumDays::getDays() const {
  return ((float)_hours) / 8.0f;
}

NumDays  operator+(const NumDays& l, const NumDays& r) {
  return NumDays(l.getHours() + r.getHours());
}

NumDays  operator-(const NumDays& l, const NumDays& r) {
  return NumDays(l.getHours() - r.getHours());
}

NumDays&  NumDays::operator++() { // prefix
  _hours++;
  return *this;
}

NumDays   NumDays::operator++(int) { // postfix
  NumDays whut(_hours);
  ++(*this);
  return whut;
}

NumDays&  NumDays::operator--() { // prefix
  _hours--;
  return *this;
}

NumDays   NumDays::operator--(int) { // postfix
  NumDays whut(_hours);
  --(*this);
  return whut;
}
