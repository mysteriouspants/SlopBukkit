/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091014, Chapter 13 Drill
 */

#include "Grid.h"

namespace fsdev {
	Grid::Grid() : _origin(Point(0,0)),
				   _dimensions(Point(10,10)),
				   _cuts(Point(5,5)) {
		
	}
	Grid::Grid(Point origin,
			   Point dimensions,
			   Point cuts) : _origin(origin),
							 _dimensions(dimensions),
							 _cuts(cuts) {
		
	}
	void Grid::set_origin(Point origin) {
		_origin = origin;
	}
	void Grid::set_dimensions(Point dimensions) {
		_dimensions = dimensions;
	}
	void Grid::set_cuts(Point cuts) {
		_cuts = cuts;
	}
	void Grid::draw_lines() const {
		if (color().visibility()) {
			size_t temp;
			for(size_t i=0; i <= _cuts.y; ++i) {
				temp = _origin.y + ( _dimensions.y / _cuts.x ) * i;
				fl_line(_origin.x, temp,
						_origin.x + _dimensions.x, temp);
			}
			for(size_t i=0; i <= _cuts.x; ++i) {
				temp = _origin.x + (  _dimensions.x / _cuts.y ) * i;
				fl_line(temp, _origin.y,
						temp, _origin.y + _dimensions.y);
			}
		}
	}
}
