/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091014, Chapter 13 Drill
 */

#ifndef __FSDEV_GRID_H_
#define __FSDEV_GRID_H_

#include "Graph.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Point.h"

namespace fsdev {
	class Grid : public Graph_lib::Shape {
	private:
		Point _origin;
		Point _dimensions;
		Point _cuts;
	public:
		Grid();
		Grid(Point origin,
			 Point dimensions,
			 Point cuts);
		Point origin() const { return _origin; };
		Point dimensions() const { return _dimensions; };
		Point cuts() const { return _cuts; };
		void set_origin(Point origin);
		void set_dimensions(Point dimensions);
		void set_cuts(Point cuts);
		void draw_lines() const;
	};
}

#endif