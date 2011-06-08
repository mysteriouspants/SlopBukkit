/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091030, Chapter 14 Drill
 */

#ifndef __B1_H_
#define __B1_H_

#include <iostream>

namespace fsdev {
	class B1 {
	public:
		virtual void vf();
		void f();
		virtual void pvf() = 0;
	};
}

#endif
