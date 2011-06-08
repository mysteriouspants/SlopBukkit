/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091019, Chapter 13 Asgn
 */

#ifndef __BOX_H_
#define __BOX_H_

#include "Graph.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include <string>
#include "Point.h"
#include "std_lib_facilities.h"

#include "RoundedRect.h"

namespace Graph_lib {
	class Box : public RoundedRect {
	protected:
		std::string t;
	public:
		Box(Point origin, int width, int height, std::string text) : RoundedRect(origin,height,width), t(text) {
//			super(origin,width,height);
//			RoundedRect::RoundedRect(origin, width, height);
		}
		void draw_lines() const;
	};
}

#endif
