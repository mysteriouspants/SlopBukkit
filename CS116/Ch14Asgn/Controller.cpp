/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#include "Controller.h"

namespace fsdev {
	Controller::Controller() : state(CONTROLLER_ON), level(0) {
		
	}
	void Controller::on() {
		state = CONTROLLER_ON;
	}
	void Controller::off() {
		state = CONTROLLER_OFF;
	}
	void Controller::set_level(int l) {
		level = l; // hooray for primitive atomicity!
	}
	void Controller::show() {
		std::cout << "controller is " << (state==CONTROLLER_ON?"ON":"OFF") << " and the current level is " << level;
	}
}
