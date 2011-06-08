/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091019, Chapter 13 Asgn
 */

#include "Simple_window.h"
#include "Graph.h"

#include "RoundedRect.h"
#include "Box.h"
#include "Arrow.h"

int main (int argc, char * const argv[]) {

	using namespace Graph_lib;
	
	Point t1(100,100);
	
	Simple_window win(t1,800,600,"File Diagram 2");
	
	Vector_ref<Box> boxes;
	boxes.push_back(new Box(Point(118,30),135,40,"window"));
	boxes.push_back(new Box(Point(74,148),215,40,"Simple_window"));
	boxes.push_back(new Box(Point(286,31),135,40,"Line_style"));
	boxes.push_back(new Box(Point(472,32),95,40,"Color"));
	boxes.push_back(new Box(Point(520,148),90,40,"Point"));
	boxes.push_back(new Box(Point(350,120),100,40,"Shape"));
	boxes.push_back(new Box(Point(41,308),75,40,"Line"));
	boxes.push_back(new Box(Point(130,308),90,40,"Lines"));
	boxes.push_back(new Box(Point(228,308),120,40,"Polygon"));
	boxes.push_back(new Box(Point(362,308),75,40,"Axis"));
	boxes.push_back(new Box(Point(447,308),145,40,"Rectangle"));
	boxes.push_back(new Box(Point(602,308),75,40,"Text"));
	boxes.push_back(new Box(Point(686,308),100,40,"Image"));
	
	for(size_t i=0; i<boxes.size(); ++i) {
		boxes[i].set_color(Color::black);
		boxes[i].set_fill_color(Color::dark_yellow);
		
		win.attach(boxes[i]);
	}
	
	win.wait_for_button();
	
	Vector_ref<Arrow> arrows;
	arrows.push_back(new Arrow(Point(182,148),Point(182, 70)));
	arrows.push_back(new Arrow(Point( 82,308),Point(356,158)));
	arrows.push_back(new Arrow(Point(176,308),Point(375,159)));
	arrows.push_back(new Arrow(Point(520,308),Point(412,159)));
	arrows.push_back(new Arrow(Point(294,308),Point(388,159)));
	arrows.push_back(new Arrow(Point(400,308),Point(400,159)));
	arrows.push_back(new Arrow(Point(638,308),Point(425,159)));
	arrows.push_back(new Arrow(Point(733,308),Point(442,159)));
	
	for(size_t i=0; i<arrows.size(); ++i) {
		arrows[i].set_color(Color::black);
		
		win.attach(arrows[i]);
	}
	
	win.wait_for_button();
	
    return 0;
}
