/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091019, Chapter 13 Asgn
 */

#ifndef __ARROW_H_
#define __ARROW_H_

#include "Graph.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Point.h"
#include "std_lib_facilities.h"
#include <math.h>

namespace Graph_lib {
	class Arrow : public Shape {
	protected:
		Point p0;
		Point p1;
	public:
		Arrow(Point origin, Point end);
		void draw_lines() const;
	};
}

#endif
