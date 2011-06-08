/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091123, Chapter 16 Assignment
 */

#include "Raster_button.h"

namespace fsdev {
	
	using namespace Graph_lib;
	
	Raster_button::Raster_button(Point _xy,
								 int _w,
								 int _h,
								 const std::string& _label,
								 Graph_lib::Callback _cb,
								 const std::string& _raster)
	: raster(_raster), xy(_xy), w(_w), h(_h), cb(_cb), label(_label), button(_xy,_w,_h,_label,_cb), ii(_xy,_raster) {
	}
	void Raster_button::hide() {
		win->detach(ii);
		button.hide();
	}
	void Raster_button::show() {
		button.show();
		win->attach(ii);
	}
	void Raster_button::attach_to_window(Window& _win) {
		win = &_win;
		win->attach(button);
		win->attach(ii);
	}
	void Raster_button::detach_from_window() {
		win->detach(button);
		win->detach(ii);
	}
	void Raster_button::move(int x, int y) {
		
		Point np(x-xy.x
				 ,
				 y-xy.y
				 );
		xy = Point(x,y);
		button.move_absolute(x, y);
		ii.move(np.x, np.y);
	}
}
