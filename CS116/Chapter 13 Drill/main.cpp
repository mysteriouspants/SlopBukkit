/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091014, Chapter 13 Drill
 */

#include <cstdlib>
#include "Simple_window.h"
#include "Graph.h"
#include "Grid.h"

int main (int argc, char * const argv[]) {

	using namespace Graph_lib;
	
	Point t1(100,100);
	
	Simple_window win(t1,1000,800,"Canvas");
	
	fsdev::Grid g(Point(0,200),
				  Point(800,800),
				  Point(8,8));
	g.set_color(Color::black);
	
	win.attach(g);
	
	win.wait_for_button();
	
	Rectangle r0(Point(000, 200), 101, 101);	r0.set_color(Color::red);	win.attach(r0);
	Rectangle r1(Point(100, 300), 101, 101);	r1.set_color(Color::red);	win.attach(r1);
	Rectangle r2(Point(200, 400), 101, 101);	r2.set_color(Color::red);	win.attach(r2);
	Rectangle r3(Point(300, 500), 101, 101);	r3.set_color(Color::red);	win.attach(r3);
	Rectangle r4(Point(400, 600), 101, 101);	r4.set_color(Color::red);	win.attach(r4);
	Rectangle r5(Point(500, 700), 101, 101);	r5.set_color(Color::red);	win.attach(r5);
	Rectangle r6(Point(600, 800), 101, 101);	r6.set_color(Color::red);	win.attach(r6);
	Rectangle r7(Point(700, 900), 101, 101);	r7.set_color(Color::red);	win.attach(r7);
	
	win.wait_for_button();
	
	Image i1(Point(200, 200), "../../extra-xcode.gif");						win.attach(i1);
	Image i2(Point(400, 400), "../../extra-xcode.gif");						win.attach(i2);
	Image i3(Point(600, 600), "../../extra-xcode.gif");						win.attach(i3);
	
	win.wait_for_button();
	
	vector<Point> open_tiles;
	open_tiles.push_back(Point(1, 0));	open_tiles.push_back(Point(4, 0));	open_tiles.push_back(Point(5, 0));
	open_tiles.push_back(Point(6, 0));	open_tiles.push_back(Point(7, 0));	open_tiles.push_back(Point(0, 1));
	open_tiles.push_back(Point(4, 1));	open_tiles.push_back(Point(5, 1));	open_tiles.push_back(Point(6, 1));
	open_tiles.push_back(Point(7, 1));	open_tiles.push_back(Point(0, 2));	open_tiles.push_back(Point(1, 2));
	open_tiles.push_back(Point(4, 2));	open_tiles.push_back(Point(6, 2));	open_tiles.push_back(Point(7, 2));
	open_tiles.push_back(Point(0, 3));	open_tiles.push_back(Point(1, 3));	open_tiles.push_back(Point(2, 3));
	open_tiles.push_back(Point(6, 3));	open_tiles.push_back(Point(7, 3));	open_tiles.push_back(Point(0, 4));
	open_tiles.push_back(Point(1, 4));	open_tiles.push_back(Point(2, 4));	open_tiles.push_back(Point(3, 4));
	open_tiles.push_back(Point(5, 4));	open_tiles.push_back(Point(0, 5));	open_tiles.push_back(Point(1, 5));
	open_tiles.push_back(Point(2, 5));	open_tiles.push_back(Point(3, 5));	open_tiles.push_back(Point(4, 5));
	open_tiles.push_back(Point(0, 6));	open_tiles.push_back(Point(1, 6));	open_tiles.push_back(Point(2, 6));
	open_tiles.push_back(Point(3, 6));	open_tiles.push_back(Point(4, 6));	open_tiles.push_back(Point(5, 6));
	open_tiles.push_back(Point(7, 6));	open_tiles.push_back(Point(0, 7));	open_tiles.push_back(Point(1, 7));
	open_tiles.push_back(Point(2, 7));	open_tiles.push_back(Point(3, 7));	open_tiles.push_back(Point(4, 7));
	open_tiles.push_back(Point(5, 7));	open_tiles.push_back(Point(6, 7));
	
	do {
		
		Point p = open_tiles[rand()%open_tiles.size()];
		
		Image i4(Point(p.x * 100, 200 + p.y * 100), "../../avvi.jpg");
		
		win.attach(i4);
		
		win.wait_for_button();
		
		win.detach(i4);
		
	} while ( true ) ;
	
    return 0;
}
