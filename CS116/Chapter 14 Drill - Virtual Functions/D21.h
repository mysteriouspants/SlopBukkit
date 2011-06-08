/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091030, Chapter 14 Drill
 */

#ifndef __D21_H_
#define __D21_H_

#include "B2.h"
#include <string>

namespace fsdev {
	class D21 : public B2 {
	protected:
		std::string sz;
	public:
		void pvf();
	};
}

#endif