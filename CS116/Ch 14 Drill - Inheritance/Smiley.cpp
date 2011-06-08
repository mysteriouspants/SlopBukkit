/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091026, Chapter 14 Drill - Inheritance
 */

#include "Smiley.h"

namespace Graph_lib {
	Foo::Foo(int bar) {
		// do nothing
	}
	void Face::draw_lines() const {
		Circle::draw_lines();
		Point leye, reye;
		leye.x = (point(0).x + Circle::r) - Circle::r / 2;
		reye.x = (point(0).x + Circle::r) + Circle::r / 2;
		leye.y = point(0).y + Circle::r / 1.5;
		reye.y = point(0).y + Circle::r / 1.5;
		Circle l(leye, Circle::r / 5);
		Circle r(reye, Circle::r / 5);
		l.set_color(color());
		r.set_color(color());
		l.draw_lines();
		r.draw_lines();
	}
	void Smiley::draw_lines() const {
		Face::draw_lines();
		Point origin(point(0).x + Circle::r, point(0).y + Circle::r);
		fl_arc(origin.x - Circle::r / 4,
			   origin.y + Circle::r / 2,
			   Circle::r / 2,
			   Circle::r / 3,
			   180.0,
			   360.0);
	}
	void Frowny::draw_lines() const {
		Face::draw_lines();
		Point origin(point(0).x + Circle::r, point(0).y + Circle::r);
		fl_arc(origin.x - Circle::r / 4,
			   origin.y + Circle::r / 2,
			   Circle::r / 2,
			   Circle::r / 3,
			     0.0,
			   180.0);
	}
	void SmileyHat::draw_lines() const {
		Smiley::draw_lines();
		Hat h(Point(point(0).x + Circle::r,
					point(0).y),
			  Point(Circle::r,
					Circle::r / 2));
		h.set_color(color());
		h.draw_lines();
	}
	void FrownyHat::draw_lines() const {
		Frowny::draw_lines();
		Hat h(Point(point(0).x + Circle::r,
					point(0).y),
			  Point(Circle::r,
					Circle::r / 2));
		h.set_color(color());
		h.draw_lines();
	}
	Hat::Hat(Point origin, Point dd) {
		add(origin);
		dimensions = dd;
	}
	void Hat::draw_lines() const {
		if (color().visibility()) {
			fl_line(point(0).x - dimensions.x / 2,
					point(0).y,
					point(0).x + dimensions.x / 2,
					point(0).y);
			fl_line(point(0).x - dimensions.x / 3,
					point(0).y,
					point(0).x - dimensions.x / 3,
					point(0).y - dimensions.y);
			fl_line(point(0).x - dimensions.x / 3,
					point(0).y - dimensions.y,
					point(0).x + dimensions.x / 3,
					point(0).y - dimensions.y);
			fl_line(point(0).x + dimensions.x / 3,
					point(0).y - dimensions.y,
					point(0).x + dimensions.x / 3,
					point(0).y);
		}
	}
}
