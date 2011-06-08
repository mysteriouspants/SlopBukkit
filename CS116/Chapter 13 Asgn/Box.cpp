/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091019, Chapter 13 Asgn
 */

#include "Box.h"

namespace Graph_lib {
	
	void Box::draw_lines() const {
		RoundedRect::draw_lines();
		//int c = fl_color
		fl_color(Color(Color::black).as_int());
		int th, tw;
		fl_measure(t.c_str(),
				   tw,
				   th);
		fl_draw(t.c_str(),
				RoundedRect::origin.x+RoundedRect::w/2-tw/2,
				RoundedRect::origin.y+RoundedRect::h/2+th/2);
	}
	
}