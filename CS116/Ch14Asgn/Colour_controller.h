/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#ifndef __COLOUR_CONTROLLER_H_
#define __COLOUR_CONTROLLER_H_

#include "Graph.h"
#include "Simple_window.h"
#include "Controller.h"

namespace fsdev {
	class Colour_controller : public Controller {
	private:
		int red;
		int green;
		int blue;
	protected:
		Vector_ref<Graph_lib::Shape> shapes;
		void update();
	public:
		Colour_controller();
		void addShape(Graph_lib::Shape& shape);
		void addShape(Graph_lib::Shape * shape);
		void set_red(int r);
		void set_green(int g);
		void set_blue(int b);
	};
}

#endif
