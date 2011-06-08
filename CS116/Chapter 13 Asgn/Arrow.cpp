/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091019, Chapter 13 Asgn
 */

#include "Arrow.h"

namespace Graph_lib {
	
	Arrow::Arrow(Point origin, Point end) : p0(origin), p1(end) {
		add(origin);
		add(end);
	}
	
	void Arrow::draw_lines() const {
		// thanks to Doolitel Cabanlas' algorithm for finding the points for an arrowhead
		
		Point origin = p0;
		Point end    = p1;
		Point arrowhead1;
		Point arrowhead2;
		
		double alpha = atan2((double)origin.y - (double)end.y, (double)end.x - (double)origin.x);
		
		double L = 8.0;
		double delta = 0.436332313; // degrees
		
		double alpha1 = alpha + delta;
		double alpha2 = alpha - delta;
		
		arrowhead1.x = end.x - L * cos(alpha1);
		arrowhead1.y = end.y + L * sin(alpha1);
		arrowhead2.x = end.x - L * cos(alpha2);
		arrowhead2.y = end.y + L * sin(alpha2);
		
		if (color().visibility()) {    // lines on top of fill
			fl_color(color().as_int());
			
			fl_line(origin.x, origin.y, end.x, end.y);
			fl_line(end.x, end.y, arrowhead1.x, arrowhead1.y);
//			fl_line(arrowhead1.x, arrowhead1.y, arrowhead2.x, arrowhead2.y); // kind of silly without a fill
			fl_line(arrowhead2.x, arrowhead2.y, end.x, end.y);
			
		}
		
	}
	
}
