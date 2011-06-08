/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#include "Colour_controller.h"

namespace fsdev {
	Colour_controller::Colour_controller() {
		Controller::Controller();
	}
	void Colour_controller::addShape(Graph_lib::Shape& shape) {
		shapes.push_back(shape);
	}
	void Colour_controller::addShape(Graph_lib::Shape * shape) {
		shapes.push_back(shape);
	}
	void Colour_controller::set_red(int r) {
		red=r;
		update();
	}
	void Colour_controller::set_green(int g) {
		green=g;
		update();
	}
	void Colour_controller::set_blue(int b) {
		blue=b;
		update();
	}
	void Colour_controller::update() {
		for(size_t i=0; i<shapes.size(); ++i)
			shapes[i].set_color(Graph_lib::Color(red,green,blue));
	}
}
