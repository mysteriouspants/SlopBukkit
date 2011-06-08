/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091130, Chapter 16 Extra Credit
 */

#ifndef __ANALOG_CLOCK_H_
#define __ANALOG_CLOCK_H_

#include "Graph.h"
#include <cmath>
#include <cstdio>
#include <iostream>

namespace fsdev {
	Point point_for_minute(int minute, int r, int a, int b);
	
	class AnalogClock : public Graph_lib::Shape {
	protected:
		Point origin;
		Point dimensions;
		int minute;
		int second;
		int hour;
	public:
		AnalogClock(Point _origin,
					Point _dimensions);
		AnalogClock(int origin_x,
					int origin_y,
					int dimensions_x,
					int dimensions_y);
		void draw_lines() const;
		
		void set_minute(int m);
		void set_second(int s);
		void set_hour(int h);
		
		int get_minute() const;
		int get_second() const;
		int get_hour() const;
	};
}

#endif
