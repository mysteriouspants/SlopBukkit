/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091010, Ch. 12 Asgn
 */

#include "Simple_window.h"
#include "Graph.h"

int main (int argc, char * const argv[]) {

	using namespace Graph_lib;
	int d,x;
	fl_measure("foo",d,x);
	
	Point t1(100,100);
	
	Simple_window win(t1,780,620,"File Diagram");
	
	// cheap hack
	Image ii(Point(50,50),"../../filegraph.jpg");
	win.attach(ii);
	
	win.wait_for_button();
	
	//																Point.h
	// title text origin: (74,49) +50 = (124,99)
	// box origin: (73,54) +50 = (123,104)
	// box dimensions: (138,29)
	// internal text origin: (80,74) +50 = (130,124)
	Text point_h_title(Point(124,85),"Point.h:");
	point_h_title.set_color(Color::black);
	win.attach(point_h_title);
	Rectangle point_h_box(Point(123,104),138,29);
	point_h_box.set_fill_color(Color::dark_yellow);
	win.attach(point_h_box);
	Text point_h_content(Point(130,110), "struct Point { ... };");
	point_h_content.set_color(Color::black);
	win.attach(point_h_content);
	
	//																FLTK Headers
	// box1 origin: (305,10) +50 = (355,60)
	// box2 origin: (310,15) +50 = (360,65)
	// box3 origin: (315,20) +50 = (365,70)
	// box dimensions: (100,35)
	// FLTK Headers label origin: (325,25) +50 = (375,75)
	Rectangle fltk_headers_box1(Point(355,60),100,35);	Rectangle fltk_headers_box2(Point(360,65),100,35);
	Rectangle fltk_headers_box3(Point(365,70),100,35);	fltk_headers_box1.set_fill_color(Color::dark_yellow);
	fltk_headers_box2.set_fill_color(Color::dark_yellow);	fltk_headers_box3.set_fill_color(Color::dark_yellow);
	win.attach(fltk_headers_box1);	win.attach(fltk_headers_box2);	win.attach(fltk_headers_box3);
	Text fltk_headers_label1(Point(369,75),"FLTK Headers");	fltk_headers_label1.set_color(Color::black);
	win.attach(fltk_headers_label1);
	
	//																FLTK Code
	// box1 origin: (468,55) +50 = (518,105)
	// box2 origin: (472,60) +50 = (522,110)
	// box3 origin: (477,65) +50 = (527,115)
	// box dimensions: (81,37)
	// FLTK Code label origin: (484,71) +50 = (534,121)
	// arrow1 origin: (465,76) +50 = (515,126)
	// arrow1 terminus: (414,40) +50 = (464,90)
	// arrow1 point1: (418,45) +50 = (468,95)
	// arrow1 point2: (420,40) +50 = (469,90)
	Rectangle fltk_code_box1(Point(518,105),81,37);		Rectangle fltk_code_box2(Point(522,110),81,37);
	Rectangle fltk_code_box3(Point(527,115),81,37);		fltk_code_box1.set_fill_color(Color::dark_yellow);
	fltk_code_box2.set_fill_color(Color::dark_yellow);	fltk_code_box3.set_fill_color(Color::dark_yellow);
	win.attach(fltk_code_box1);	win.attach(fltk_code_box2);	win.attach(fltk_code_box3);
	Text fltk_code_label1(Point(532,121),"FLTK Code");	fltk_code_label1.set_color(Color::black);
	win.attach(fltk_code_label1);
	Open_polyline arrow1;
	arrow1.set_color(Color::black);
	arrow1.add(Point(518,126));	arrow1.add(Point(464,90));	arrow1.add(Point(468,97));
	arrow1.add(Point(469,90));	arrow1.add(Point(464,90));	win.attach(arrow1);
	
	//																Window.h
	// box origin: (284,126) +50 = (334,176)
	// box dimensions: (143,61)
	// title label origin: (282,106) +50 = (332,156)
	// window interface label origin: (292,132) +50 = (342,182)
	// class window label origin: (292,148) +50 = (342,198)
	// em dash label origin: (292,166) +50 = (342,216)
	// arrow2 origin: (300,126) +50 = (350,176)
	// arrow2 terminus: (185,82) +50 = (235,132)
	// arrow2 point1: (190,88) +50 = (240,138)
	// arrow2 point2: (192,82) +50 = (242,132)
	// arrow3 origin: (362,126) +50 = (412,176)
	// arrow3 terminus: (361,58) +50 = (412,108)
	// arrow3 point1: (359,64) +50 = (409,114)
	// arrow3 point2: (364,64) +50 = (414,114)
	Rectangle window_h_box(Point(334,176),143,61);
	window_h_box.set_fill_color(Color::dark_yellow);		win.attach(window_h_box);
	Text window_h_title(Point(332,156),"Window.h:");
	window_h_title.set_color(Color::black);					win.attach(window_h_title);
	Text window_h_label1(Point(342,182),"// window interface:");
	window_h_label1.set_color(Color::black);				win.attach(window_h_label1);
	Text window_h_label2(Point(342,198),"class Window {...};");
	window_h_label2.set_color(Color::black);				win.attach(window_h_label2);
	Text window_h_label3(Point(342,214),"...");
	window_h_label3.set_color(Color::black);				win.attach(window_h_label3);
	Open_polyline arrow2;
	arrow2.set_color(Color::black);
	arrow2.add(Point(350,176));	arrow2.add(Point(235,132));	arrow2.add(Point(240,138));
	arrow2.add(Point(242,132));	arrow2.add(Point(235,132));	win.attach(arrow2);
	Open_polyline arrow3;
	arrow3.set_color(Color::black);
	arrow3.add(Point(412,176));	arrow3.add(Point(412,108));	arrow3.add(Point(409,114));
	arrow3.add(Point(414,114));	arrow3.add(Point(412,108));	win.attach(arrow3);
	
	//																Graph.h
	// title '(Graph.h:) origin: (70,148) +50 = (120,198)
	// box origin: (72,168) +50 = (122,218)
	// box dimensions: (150,60)
	// label1 '(// graphing interface:) origin: (80,174) +50 = (130,224)
	// label2 '(struct Shape {...};) origin: (80,190) +50 = (130,240)
	// label3 '(...) origin: (80,206) +50 = (130,256)
	// arrow4 origin: (145,168) +50 = (195,218)
	// arrow4 terminus: (145,84) +50 = (195,134)
	// arrow4 point1: (142,89) +50 = (192,139)
	// arrow4 point2: (148,90) +50 = (198,140)
	// arrow5 origin: (145,168) +50 = (195,218)
	// arrow5 terminus: (322,58) +50 = (372,108)
	// arrow5 point1: (314,60) +50 = (364,110)
	// arrow5 point2: (318,64) +50 = (368,114)
	Text graph_h_title(Point(120,198),"Graph.h:");	graph_h_title.set_color(Color::black);
	win.attach(graph_h_title);
	Rectangle graph_h_box(Point(122,218),150,60);	graph_h_box.set_fill_color(Color::dark_yellow);
	win.attach(graph_h_box);
	Text graph_h_label1(Point(130,224),"// graphing interface:");	graph_h_label1.set_color(Color::black);
	win.attach(graph_h_label1);
	Text graph_h_label2(Point(130,240),"struct Shape {...};");	graph_h_label2.set_color(Color::black);
	win.attach(graph_h_label2);
	Text graph_h_label3(Point(130,256),"...");	graph_h_label3.set_color(Color::black);
	win.attach(graph_h_label3);
	Open_polyline arrow4;	arrow4.set_color(Color::black);
	arrow4.add(Point(195,218));	arrow4.add(Point(195,134));	arrow4.add(Point(192,139));
	arrow4.add(Point(198,140));	arrow4.add(Point(195,134));	win.attach(arrow4);
	Open_polyline arrow5;	arrow5.set_color(Color::black);
	arrow5.add(Point(195,218));	arrow5.add(Point(372,108));	arrow5.add(Point(364,110));
	arrow5.add(Point(368,114));	arrow5.add(Point(372,108));	win.attach(arrow5);
	
	//																GUI.h
	// title '(GUI.h:) origin: (405,206) +50 = (455,256)
	// box origin: (407,225) +50 = (457,275)
	// box dimensions: (145,60)
	// label1 '(// GUI interface:) origin: (414,230) +50 = (464,280)
	// label2 '(struct In_box {...};) origin: (414,246) +50 = (464,296)
	// label3 '(...) origin: (414,262) +50 = (464,312)
	// arrow6 origin: (506,225) +50 = (556,275)
	// arrow6 terminus: (422,186) +50 = (472,236)
	// arrow6 point1: (425,192) +50 = (475,242)
	// arrow6 point2: (428,188) +50 = (478,238)
	// arrow7 origin: (506,225) +50 = (556,275)
	// arrow7 terminus: (390,58) +50 = (440,108)
	// arrow7 point1: (392,65) +50 = (442,115)
	// arrow7 point2: (398,62) +50 = (448,112)
	Text gui_h_title(Point(455,256),"GUI.h:");	gui_h_title.set_color(Color::black);
	win.attach(gui_h_title);
	Rectangle gui_h_box(Point(457,275),145,60);	gui_h_box.set_fill_color(Color::dark_yellow);
	win.attach(gui_h_box);
	Text gui_h_label1(Point(464,280),"// GUI interface:");	gui_h_label1.set_color(Color::black);
	Text gui_h_label2(Point(464,296),"struct In_box {...};");	gui_h_label2.set_color(Color::black);
	Text gui_h_label3(Point(464,312),"...");	gui_h_label3.set_color(Color::black);
	win.attach(gui_h_label1);	win.attach(gui_h_label2);	win.attach(gui_h_label3);
	Open_polyline arrow6;	Open_polyline arrow7;
	arrow6.set_color(Color::black);	arrow7.set_color(Color::black);
	arrow6.add(Point(556,275));	arrow6.add(Point(472,236));	arrow6.add(Point(475,242));
	arrow6.add(Point(478,236));	arrow6.add(Point(472,236));	win.attach(arrow6);
	arrow7.add(Point(556,275));	arrow7.add(Point(440,108));	arrow7.add(Point(442,115));
	arrow7.add(Point(448,112));	arrow7.add(Point(440,108));	win.attach(arrow7);
	
	//																window.cpp
	// title '(window.cpp:) origin: (190,248) +50 = (240,298)
	// box origin: (193,266) +50 = (243,316)
	// box dimensions: (114,28)
	// label1 '(Window code) origin: (200,270) +50 = (250,320)
	// arrow8 origin: (282,266) +50 = (332,316)
	// arrow8 terminus: (337,187) +50 = (387,237)
	// arrow8 point1: (330,192) +50 = (380,242)
	// arrow8 point2: (336,194) +50 = (386,244)
	Text window_cpp_title(Point(240,298),"window.cpp:"); window_cpp_title.set_color(Color::black);
	win.attach(window_cpp_title);
	Rectangle window_cpp_box(Point(243,316),114,28);	window_cpp_box.set_fill_color(Color::dark_yellow);
	win.attach(window_cpp_box);
	Text window_cpp_label1(Point(250,320),"Window code");	window_cpp_label1.set_color(Color::black);
	win.attach(window_cpp_label1);
	Open_polyline arrow8;	arrow8.set_color(Color::black);
	arrow8.add(Point(332,316));	arrow8.add(Point(387,237));	arrow8.add(Point(380,242));
	arrow8.add(Point(386,244));	arrow8.add(Point(387,237));	win.attach(arrow8);
	
	//																Graph.cpp
	// title '(Graph.cpp:) origin: (21,313) +50 = (71,363)
	// box origin: (22,330) +50 = (72,380)
	// box dimensions: (97,27)
	// label1 '(Graph code) origin: (30,336) +50 = (80,386)
	// arrow9 origin: (102,330) +50 = (152,380)
	// arrow9 terminus: (142,230) +50 = (192,280)
	// arrow9 point1: (136,234) +50 = (186,284)
	// arrow9 point2: (142,237) +50 = (192,287)
	Text graph_cpp_title(Point(71,363),"Graph.cpp:");	graph_cpp_title.set_color(Color::black);
	win.attach(graph_cpp_title);
	Rectangle graph_cpp_box(Point(72,380),97,27);	graph_cpp_box.set_fill_color(Color::dark_yellow);
	win.attach(graph_cpp_box);
	Text graph_cpp_label1(Point(80,386),"Graph code");	graph_cpp_label1.set_color(Color::black);
	win.attach(graph_cpp_label1);
	Open_polyline arrow9;	arrow9.set_color(Color::black);
	arrow9.add(Point(152,380));	arrow9.add(Point(192,280));	arrow9.add(Point(186,284));
	arrow9.add(Point(192,287));	arrow9.add(Point(192,280));	win.attach(arrow9);
	
	//																GUI.cpp
	// title '(GUI.cpp:) origin: (432,312) +50 = (482,362)
	// box origin: (433,330) +50 = (483,380)
	// box dimensions: (85,25)
	// label1 '(GUI code) origin: (440,335) +50 = (490,385)
	// arrow10 origin: (500,330) +50 = (550,380)
	// arrow10 terminus: (483,286) +50 = (533,336)
	// arrow10 point1: (483,291) +50 = (533,341)
	// arrow10 point2: (489,291) +50 = (539,341)
	Text gui_cpp_title(Point(482,362),"GUI.cpp:");	gui_cpp_title.set_color(Color::black);
	win.attach(gui_cpp_title);
	Rectangle gui_cpp_box(Point(483,380),85,25);	gui_cpp_box.set_fill_color(Color::dark_yellow);
	win.attach(gui_cpp_box);
	Text gui_cpp_label1(Point(490,385),"GUI code");	gui_cpp_label1.set_color(Color::black);
	win.attach(gui_cpp_label1);
	Open_polyline arrow10;	arrow10.set_color(Color::black);
	arrow10.add(Point(550,380));	arrow10.add(Point(533,336));	arrow10.add(Point(533,341));
	arrow10.add(Point(539,341));	arrow10.add(Point(533,336));	win.attach(arrow10);
	
	//																Simple_window.h
	// title '(Simple_window.h:) origin: (218,321) +50 = (268,371)
	// box origin: (220,340) +50 = (270,390)
	// box dimensions: (193,60)
	// label1 '(// window interface:) origin: (227,344) +50 = (277,394)
	// label2 '(class Simple_window {...};) origin: (227,360) +50 = (277,410)
	// label3 '(...) origin: (227,376) +50 = (277,426)
	// arrow11 origin: (360,340) +50 = (410,390)
	// arrow11 terminus: (360,187) +50 = (410,237)
	// arrow11 point1: (358,193) +50 = (408,243)
	// arrow11 point2: (362,193) +50 = (412,243)
	// arrow12 origin: (360,340) +50 = (410,390)
	// arrow12 terminus: (422,286) +50 = (472,336)
	// arrow12 point1: (415,288) +50 = (465,338)
	// arrow12 point2: (419,293) +50 = (469,343)
	Text simple_window_h_title(Point(268,371),"Simple_window.h"); simple_window_h_title.set_color(Color::black);
	win.attach(simple_window_h_title);
	Rectangle simple_window_h_box(Point(270,390),193,60);	simple_window_h_box.set_fill_color(Color::dark_yellow);
	win.attach(simple_window_h_box);
	Text simple_window_h_label1(Point(277,394),"// window interface:");	simple_window_h_label1.set_color(Color::black);
	Text simple_window_h_label2(Point(277,410),"class Simple_window {...};");	simple_window_h_label2.set_color(Color::black);
	Text simple_window_h_label3(Point(277,426),"...");	simple_window_h_label3.set_color(Color::black);
	win.attach(simple_window_h_label1);	win.attach(simple_window_h_label2);	win.attach(simple_window_h_label3);
	Open_polyline arrow11;		Open_polyline arrow12;
	arrow11.set_color(Color::black);	arrow12.set_color(Color::black);
	arrow11.add(Point(410,390));	arrow11.add(Point(410,237));	arrow11.add(Point(408,243));
	arrow11.add(Point(412,243));	arrow11.add(Point(410,237));	win.attach(arrow11);
	arrow12.add(Point(410,390));	arrow12.add(Point(472,336));	arrow12.add(Point(465,338));
	arrow12.add(Point(469,343));	arrow12.add(Point(472,336));	win.attach(arrow12);
	
	//																chapter12.cpp
	// title '(chapter12.cpp:) origin: (89,426) +50 = (139,476)
	// box origin: (92,446) +50 = (142,496)
	// box dimensions: (210,60)
	// label1 '(#include "Graph.h") origin: (100,448) +50 = (150,498)
	// label2 '(#include "Simple_window.h") origin: (100,464) +50 = (150,514)
	// label3 '(int main() {...}) origin: (100,480) +50 = (150,530)
	// arrow13 origin: (200,446) +50 = (250,496)
	// arrow13 terminus: (148,230) +50 = (198,280)
	// arrow13 point1: (148,236) +50 = (198,286)
	// arrow13 point2: (152,235) +50 = (202,285)
	// arrow14 origin: (200,446) +50 = (250,496)
	// arrow14 terminus: (244,402) +50 = (294,452)
	// arrow14 point1: (237,404) +50 = (287,454)
	// arrow14 point2: (240,407) +50 = (290,457)
	Text chapter12_cpp_title(Point(139,476),"chapter12.cpp:");	chapter12_cpp_title.set_color(Color::black);
	win.attach(chapter12_cpp_title);
	Rectangle chapter12_cpp_box(Point(142,496),210,60);	chapter12_cpp_box.set_fill_color(Color::dark_yellow);
	win.attach(chapter12_cpp_box);
	Text chapter12_cpp_label1(Point(150,498),"#include \"Graph.h\"");	chapter12_cpp_label1.set_color(Color::black);
	Text chapter12_cpp_label2(Point(150,514),"#include \"Simple_window.h\"");	chapter12_cpp_label2.set_color(Color::black);
	Text chapter12_cpp_label3(Point(150,530),"int main() {...}");	chapter12_cpp_label3.set_color(Color::black);
	win.attach(chapter12_cpp_label1);	win.attach(chapter12_cpp_label2);	win.attach(chapter12_cpp_label3);
	Open_polyline arrow13;		Open_polyline arrow14;
	arrow13.set_color(Color::black);	arrow14.set_color(Color::black);
	arrow13.add(Point(250,496));	arrow13.add(Point(198,280));	arrow13.add(Point(198,286));
	arrow13.add(Point(202,285));	arrow13.add(Point(198,280));	win.attach(arrow13);
	arrow14.add(Point(250,496));	arrow14.add(Point(294,452));	arrow14.add(Point(287,454));
	arrow14.add(Point(290,457));	arrow14.add(Point(294,452));	win.attach(arrow14);
	
	win.wait_for_button();
	
	win.detach(ii);
	
	win.wait_for_button();
	
    return 0;
}
