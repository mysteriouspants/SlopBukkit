/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091207, Chapter 17 Assignment
 */

#include "GenericStruct.h"

namespace fsdev {
	
	std::ostream& operator << (std::ostream& os,
							   const GenericStruct& data) {
		os << "str0: " << data.str0 << "  ";
		os << "str1: " << data.str1 << "  ";
		os << "str2: " << data.str2 << "  ";
		os << "str3: " << data.str3 << "  ";
		return os;
	}
	
	bool operator < (const GenericStruct& d0,
					 const GenericStruct& d1) {
		return d0.str0 < d1.str0;
	}
	
	bool operator > (const GenericStruct& d0,
					 const GenericStruct& d1) {
		return d0.str0 > d1.str0;
	}
	
	bool operator == (const GenericStruct& d0,
					  const GenericStruct& d1) {
		return d0.str0 == d1.str0;
	}
	
}
