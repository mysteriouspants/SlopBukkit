/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#include "Simple_Controller.h"

namespace fsdev {
	void Simple_Controller::on() {
		Controller::on();
	}
	void Simple_Controller::off() {
		Controller::off();
	}
	void Simple_Controller::set_level(int l) {
		Controller::set_level(l);
	}
	void Simple_Controller::show() {
		Controller::show();
	}
}
