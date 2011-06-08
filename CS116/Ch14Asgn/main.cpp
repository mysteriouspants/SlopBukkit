/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#include "Simple_window.h"
#include "Graph.h"

#include "Simple_Controller.h"
#include "Shape_Controller.h"
#include "Colour_controller.h"

int main (int argc, char * const argv[]) {

	using namespace Graph_lib;
	
	fsdev::Simple_Controller ctlr0;
	
	ctlr0.show();
	
	Point t1(100,100);
	
	Simple_window win(t1,600,400,"Canvas");
	
	Polygon poly;
	
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(400,200));
	
	poly.set_color(Color::red);
	
	
	fsdev::Shape_Controller ctlr1(win);
	
	for(int i=0; i<255; i+=50) {
		ctlr1.set_level(i);
		win.wait_for_button();
	}
	
	fsdev::Colour_controller ctlr2;
	ctlr2.addShape(poly);
	
	ctlr2.set_red(255);
	ctlr2.set_green(255);
	ctlr2.set_blue(0);

	win.wait_for_button();
	
	ctlr2.set_red(255);
	ctlr2.set_green(0);
	ctlr2.set_blue(255);
	
	win.wait_for_button();
	
	ctlr2.set_red(0);
	ctlr2.set_green(255);
	ctlr2.set_blue(255);
	
	win.wait_for_button();
	
    return 0;
}
