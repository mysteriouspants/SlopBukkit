/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091030, Chapter 14 Drill
 */

#ifndef __B2_H_
#define __B2_H_

#include "B1.h"

namespace fsdev {
	class B2 : public B1 {
	public:
		virtual void pvf() = 0;
	};
}

#endif