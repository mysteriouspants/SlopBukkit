/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091019, Chapter 13 Asgn
 */

#include "Graph.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Point.h"
#include "std_lib_facilities.h"

#ifndef __ROUNDEDRECT_H_
#define __ROUNDEDRECT_H_

namespace Graph_lib {
	class RoundedRect : public Shape {
	protected:
		RoundedRect() {
			
		}
		Point origin;
		int h;
		int w;
	public:
		RoundedRect(Point o, int hh, int ww) : origin(o), h(hh), w(ww) {
			add(origin);
		}
		void draw_lines() const;
	};
}

#endif
