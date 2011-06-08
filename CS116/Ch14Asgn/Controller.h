/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#include <iostream>

#ifndef __CONTROLLER_H_
#define __CONTROLLER_H_

#define CONTROLLER_ON true
#define CONTROLLER_OFF false

namespace fsdev {
	class Controller {
	public:
		Controller();
	protected:
		bool state;
		int level;
		virtual void on();
		virtual void off();
		virtual void set_level(int);
		virtual void show();
	};
}

#endif
