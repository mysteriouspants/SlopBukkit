/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#ifndef __SIMPLE_CONTROLLER_H_
#define __SIMPLE_CONTROLLER_H_

#include "Controller.h"

namespace fsdev {
	class Simple_Controller : public Controller {
	public:
		void on();
		void off();
		void set_level(int);
		void show();
	};
}

#endif
