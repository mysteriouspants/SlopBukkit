/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091130, Chapter 16 Extra Credit
 */

#include "Simple_window.h"
#include "Graph.h"

#include "AnalogClock.h"
#include <iostream>
#include <ctime>

fsdev::AnalogClock c(50,50,300,300);
Simple_window * win;

void callback(void*) {
	time_t rawtime;
	time ( &rawtime );
	tm * timeinfo;
	timeinfo = localtime( &rawtime );
	c.set_second(timeinfo->tm_sec);
	c.set_minute(timeinfo->tm_min);
	c.set_hour(timeinfo->tm_hour);
	std::cout << asctime(timeinfo) << std::endl;
	win->redraw();
	Fl::repeat_timeout(1.0, callback);
}

int main (int argc, char * const argv[]) {

	using namespace Graph_lib;
	
	Point t1(100,100);
	
	win = new Simple_window(t1,600,400,"Canvas");
	
	//fsdev::AnalogClock c(50,50,300,300);
	
	c.set_color(Color::black);
	
	win->attach(c);
	
	Fl::add_timeout(1.0, callback);
	
//	win.wait_for_button();
	
    return Fl::run();
}
