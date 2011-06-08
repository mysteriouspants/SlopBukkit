/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091026, Chapter 14 Drill - Inheritance
 */

#include "Simple_window.h"
#include "Graph.h"
#include "Smiley.h"

int main (int argc, char * const argv[]) {

	using namespace Graph_lib;
	
		Foo bar(10);
	
	Point t1(100,100);
	
	Simple_window win(t1,600,400,"Canvas");
	
	Smiley s(Point(100,100),50);	Frowny f(Point(300,100),50);
	s.set_color(Color::black);		f.set_color(Color::black);
	
	win.attach(s);					win.attach(f);
	
	SmileyHat sh(Point(100,300),50);FrownyHat fh(Point(300,300),50);
	sh.set_color(Color::black);		fh.set_color(Color::black);
	
	win.attach(sh);					win.attach(fh);
		
	win.wait_for_button();
	
    return 0;
}
