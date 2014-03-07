/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140307, Chapter 14 Programming Challenge 6
 */

#include <cstddef>

#ifndef NUMDAYS_HPP
#define NUMDAYS_HPP

class NumDays {
  size_t _hours;
public:
  NumDays(size_t);

  size_t getHours() const;
  void setHours(const size_t);

  float getDays() const;

  friend NumDays  operator+(const NumDays&, const NumDays&);
  friend NumDays  operator-(const NumDays&, const NumDays&);
  NumDays& operator++();  // prefix
  NumDays  operator++(int); // postfix
  NumDays& operator--(); // prefix
  NumDays  operator--(int); // postfix
};

#endif