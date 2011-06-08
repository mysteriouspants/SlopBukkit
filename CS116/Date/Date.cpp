/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090927, ch 9 drill #1
 */

#include "Date.h"

namespace fsdev {
	Date::Date(Year _y,
			   Month _m,
			   int _d)
			   : y(_y),
			   m(_m),
			   d(_d) {
		
	}
	void Date::add_day(int _n) {
		d+=_n;
		if(d>32) {
			int o=d/32,nm;
			d-=32*o;
			nm=(int)m+o;
			if(nm>12) {
				o=nm/12;
				nm=(int)m-12*o;
				y=Year(y.year()+o);
			}
			m=(Date::Month)nm;
		}
	}
}

