/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091019, Chapter 13 Asgn
 */

#include "RoundedRect.h"

#define ARCSIZE 15

namespace Graph_lib {

void RoundedRect::draw_lines() const {
	
	if (fill_color().visibility()) {    // fill
        fl_color(fill_color().as_int());
		
		fl_pie(origin.x, origin.y, ARCSIZE, ARCSIZE, 90, 180); // top left
		fl_pie(origin.x+w-ARCSIZE, origin.y, ARCSIZE, ARCSIZE, 0, 90); // top right
		fl_pie(origin.x+w-ARCSIZE, origin.y+h-ARCSIZE, ARCSIZE, ARCSIZE, 270, 360); // bottom right
		fl_pie(origin.x, origin.y+h-ARCSIZE, ARCSIZE, ARCSIZE, 180, 180+90); // bottom left
		fl_rectf(origin.x+ARCSIZE/2-1, origin.y, w-ARCSIZE/2-5, h); // the vetical fill
		fl_rectf(origin.x, origin.y+ARCSIZE/2, w, h-ARCSIZE/2-5); // the horizontal fill
		
		fl_color(color().as_int());

    }
	
    if (color().visibility()) {    // lines on top of fill
		fl_color(color().as_int());
		
		fl_arc(origin.x, origin.y, ARCSIZE, ARCSIZE, 90, 180); // top left
		fl_line(origin.x+ARCSIZE/2-1, origin.y, origin.x+w-ARCSIZE/2-1, origin.y); // link top left to top right
		fl_arc(origin.x+w-ARCSIZE, origin.y, ARCSIZE, ARCSIZE, 0, 90); // top right
		fl_line(origin.x+w, origin.y+ARCSIZE/2-1, origin.x+w, origin.y+h-ARCSIZE/2-1); // link top right to bottom right
		fl_arc(origin.x+w-ARCSIZE, origin.y+h-ARCSIZE, ARCSIZE, ARCSIZE, 270, 360); // bottom right
		fl_line(origin.x+ARCSIZE/2-1, origin.y+h, origin.x+w-ARCSIZE/2-1, origin.y+h); // link bottom right to bottom left
		fl_arc(origin.x, origin.y+h-ARCSIZE, ARCSIZE, ARCSIZE, 180, 180+90); // bottom left
		fl_line(origin.x, origin.y+ARCSIZE/2-1, origin.x, origin.y+h-ARCSIZE/2-1); // link bottom left to top left

    }
	
}
	
}

#undef ARCSIZE
