/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091123, Chapter 16 Assignment
 */

#ifndef __RASTER_BUTTON_H_
#define __RASTER_BUTTON_H_

#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>

#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

namespace fsdev {
	
	using namespace Graph_lib;
	
	/*! Uses the controller pattern to control both an image
	 *! and a button.
	 */
	class Raster_button {
	protected:
		Image ii;
		std::string raster;
		Point xy;
		int w;
		int h;
		std::string label;
		Window* win;
		Callback cb;
		
		Button button;
	public:
		Raster_button(Point _xy,
					  int _w,
					  int _h,
					  const std::string& _label,
					  Callback _cb,
					  const std::string& _raster);
		void hide();
        void show();
		void attach_to_window(Window& win);
		void detach_from_window();
		void move(int x, int y);
	};
}

#endif