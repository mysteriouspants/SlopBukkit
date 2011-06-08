/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091116, Chapter 15 Assignment
 */

#include "Bar_graph.h"

namespace fsdev {
	Bar_graph::Bar_graph(size_t _baseline) : baseline(_baseline) {
//		Shape::Shape();
	}
	void Bar_graph::draw_lines() const {
		if (fill_color().visibility()) {
			fl_color(fill_color().as_int());
			for(int i=0; i<number_of_points(); ++i){
				// draw a coloured rectangle
				fl_rectf(point(i).x, point(i).y, 20, baseline-point(i).y);
				//fl_vertex(point(i).x, point(i).y);
			}
			fl_color(color().as_int());    // reset color
		}
		
		if (color().visibility()) {
			fl_color(color().as_int());
			for(size_t i=0; i<number_of_points(); ++i) {
				fl_rect(point(i).x, point(i).y, 20, baseline-point(i).y);
			}
			fl_color(color().as_int());
		}
	}
}
