/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#include "Shape_Controller.h"

namespace fsdev {
	Shape_Controller::Shape_Controller(Simple_window& _win) : win(_win) {
		Controller::Controller();
	}
	void Shape_Controller::addShape(Graph_lib::Shape& s) {
		shapes.push_back(s);
		s.set_color(Graph_lib::Color(level,level,level));
		if(Controller::state)
			win.attach(s);
	}
	void Shape_Controller::addShape(Graph_lib::Shape * s) {
		shapes.push_back(s);
		s->set_color(Graph_lib::Color(level,level,level));
		if(Controller::state)
			win.attach(*s);
	}
	Graph_lib::Shape& Shape_Controller::shapeAt(size_t idx) {
		return shapes[idx];
	}
	void Shape_Controller::on() {
		Controller::on();
		for(size_t i=0; i<shapes.size(); ++i) {
			win.detach(shapes[i]);
			win.attach(shapes[i]);
		}
	}
	void Shape_Controller::off() {
		Controller::off();
		for(size_t i=0; i<shapes.size(); ++i)
			win.detach(shapes[i]);
	}
	void Shape_Controller::set_level(int l) {
		Controller::set_level(l);
		for(size_t i=0; i<shapes.size(); ++i)
			shapes[i].set_color(Graph_lib::Color(level,level,level));
	}
	void Shape_Controller::show() {
		Controller::show();
	}
}
