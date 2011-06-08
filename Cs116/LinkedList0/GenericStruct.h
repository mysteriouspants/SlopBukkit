/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091207, Chapter 17 Assignment
 */

#ifndef __GENERICSTRUCT_H__
#define __GENERICSTRUCT_H__

#include <string>
#include <iostream>

namespace fsdev {
	struct GenericStruct {
		std::string str0;
		std::string str1;
		std::string str2;
		std::string str3;
		GenericStruct(std::string _str0,
					  std::string _str1,
					  std::string _str2,
					  std::string _str3)
		: str0(_str0), str1(_str1), str2(_str2), str3(_str3) {
			
		}
	};
	
	std::ostream& operator << (std::ostream& os,
							   const GenericStruct& data);
	
	bool operator < (const GenericStruct& d0,
					 const GenericStruct& d1);
	
	bool operator > (const GenericStruct& d0,
					 const GenericStruct& d1);
	
	bool operator == (const GenericStruct& d0,
					  const GenericStruct& d1);
	
	typedef GenericStruct* GenericStructRef;
}

#endif
