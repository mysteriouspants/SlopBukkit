/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091123, Chapter 16 Assignment
 */

#include <iostream>

#include "Simple_window.h"
#include "Graph.h"
#include "Raster_button.h"

static
fsdev::Raster_button* rb;

void hit_panic_button(Address,Address);

int main (int argc, char * const argv[]) {

	using namespace Graph_lib;
	
	Point t1(100,100);
	
	Simple_window win(t1,600,400,"Canvas");
	
	fsdev::Raster_button _rb(Point(0,0),
							 200,200,
							 "panic!",
							 hit_panic_button,
#ifdef __MACH__ || __APPLE__
							 "../../panic_button.jpg"
#else
							 "panic_button.jpg"
#endif
							 );

	rb = &_rb;
	
	rb->attach_to_window(win);
	rb->show();
	
	win.wait_for_button();
	
    return 0;
}

void hit_panic_button(Address a0,Address a1) {
	// move the panic button rb
	int x,y;
	x = rand()%(400);
	y = rand()%(200);
	rb->move(x, y);
}

