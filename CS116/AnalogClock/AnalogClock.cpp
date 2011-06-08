/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091130, Chapter 16 Extra Credit
 */

#include "AnalogClock.h"

namespace fsdev {
	Point point_for_minute(int minute, int r, int a, int b) {
		Point p;
		double t = ( 2.0 * 3.14159265 / 60.0 ) * (double)minute - ( 3.14159265 / 2.0 );
		p.x = (int)((double)a + (double)r * cos(t));
		p.y = (int)((double)b + (double)r * sin(t));
		return p;
	}
	AnalogClock::AnalogClock(Point _origin,
							 Point _dimensions)
	: origin(_origin), dimensions(_dimensions), hour(3), minute(35), second(50) {
		add(_origin);
		if(dimensions.x!=dimensions.y)
			error("Please, an ovular clock?  Get a life.  Use a circular clock instead.");
	}
	AnalogClock::AnalogClock(int origin_x,
							 int origin_y,
							 int dimensions_x,
							 int dimensions_y)
	: origin(origin_x, origin_y), dimensions(dimensions_x, dimensions_y), hour(3), minute(35), second(50) {
		add(Point(origin_x, origin_y));
		if(dimensions.x!=dimensions.y)
			error("Please, an ovular clock?  Get a life.  Use a circular clock instead.");
	}
	void AnalogClock::draw_lines() const {
		fl_color(color().as_int());
		Point d(dimensions.x, dimensions.y);
		Point o((origin.x+dimensions.x)/2,(origin.y+dimensions.y)/2);
		// draw sixty tick marks
		for(int m=0; m != 60; ++m) {
			Point p0 = point_for_minute(m, d.x/2, o.x, o.y);
			Point p1 = point_for_minute(m, (d.x-10)/2, o.x, o.y);
			fl_line(p0.x, p0.y, p1.x, p1.y);
		}
		// draw twelve labels
		char label[3];
		for(int m=1; m!=13; ++m) {
			Point p0 = point_for_minute(m*5, d.x/2+10, o.x, o.y);
			sprintf(label, "%d", m);
			fl_draw(label, p0.x, p0.y);
		}
		// draw the hour hand
		fl_color(Graph_lib::Color(Graph_lib::Color::red).as_int());
		int rhand_r = (int)(((double)d.x/2.0)*0.666666666);
		Point rhand_p = point_for_minute(hour*5, rhand_r, o.x, o.y);
		fl_line(o.x, o.y, rhand_p.x, rhand_p.y);
		// draw the minute hand
		fl_color(Graph_lib::Color(Graph_lib::Color::blue).as_int());
		int mhand_r = (int)(((double)d.x/2.0)*(3.0/5.0));
		Point mhand_p = point_for_minute(minute, mhand_r, o.x, o.y);
		fl_line(o.x, o.y, mhand_p.x, mhand_p.y);
		// draw the second hand
		fl_color(Graph_lib::Color(Graph_lib::Color::black).as_int());
		int shand_r = (int)(((double)d.x/2.0)*(4.0/5.0));
		Point shand_p = point_for_minute(second, shand_r, o.x, o.y);
		fl_line(o.x, o.y, shand_p.x, shand_p.y);
	}
	void AnalogClock::set_minute(int m) {
		minute = m;
	}
	void AnalogClock::set_second(int s) {
		second = s;
	}
	void AnalogClock::set_hour(int h) {
		hour = h;
	}
	
	int AnalogClock::get_minute() const {
		return minute;
	}
	int AnalogClock::get_second() const {
		return second;
	}
	int AnalogClock::get_hour() const {
		return hour;
	}
	
}
