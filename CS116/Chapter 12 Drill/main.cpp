/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! ${DATE}, ${ASSIGNMENT}
 */

#include "Simple_window.h"
#include "Graph.h"

int main (int argc, char * const argv[]) {

	using namespace Graph_lib;
	
	Point t1(100,100);
	
	Simple_window win(t1,600,400,"Canvas #1");
	
	win.wait_for_button();
	
	// 12.7.3
	Axis xa(Axis::x, Point(30,300), 280,10, "x axis");
	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();
	
	Axis ya(Axis::y, Point(30,300), 280, 10, "y axis");
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button();
	
	// 12.7.4
	Function sine(sin, 0, 100, Point(30, 150), 1000, 50, 50);
	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();
	
	// 12.7.5
	sine.set_color(Color::blue);
	
	Polygon poly;
	poly.add(Point(400,200));
	poly.add(Point(450,100));
	poly.add(Point(500,200));
	
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();
	
	// 12.7.6
	Rectangle r(Point(300,200),100,50);
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();
	
	Closed_polyline poly_rect;
	poly_rect.add(Point(400,50));
	poly_rect.add(Point(500,50));
	poly_rect.add(Point(500,100));
	poly_rect.add(Point(400,100));
	win.attach(poly_rect);
	win.set_label("Canvas #6.5");
	win.wait_for_button();
	
	poly_rect.add(Point(350,75));
	win.set_label("Canvas #6.75");
	win.wait_for_button();
	
	// 12.7.7
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style::dash);
	poly_rect.set_style(Line_style::dash);
	win.set_label("Canvas #7");
	win.wait_for_button();
	
	// 12.7.8
	Text t(Point(150,250), "Hello, graphical world!");
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();
	
	////// due to font problems on Mac OS X and FLTK, it is not possible for
	////// me to manipulate the font.  This part has been omitted.
	
	// 12.7.9
	Image ii(Point(100,50),"../../image.jpg");
	win.attach(ii);
	win.set_label("Canvas #9");
	win.wait_for_button();
	
	// 12.7.10
	Circle c(Point(100,200),50);
	Ellipse e(Point(100,200), 75,25);
	e.set_color(Color::dark_red);
	Mark m(Point(100,200),'x');
	
	ostringstream oss;
	oss << "screen size: " << x_max() << "x" << y_max()
	<< "; window size: " << win.x_max() << "x" << win.y_max();
	Text sizes(Point(100,20),oss.str());
	
	Image cal(Point(225,225),"../../snow_cpp.gif");
	cal.set_mask(Point(40,40),200,150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #10");
	win.wait_for_button();
	
    return 0;
}
