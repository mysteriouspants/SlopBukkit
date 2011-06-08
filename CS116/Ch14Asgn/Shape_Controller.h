/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091109, Chapter 14 Assignment
 */

#ifndef __SHAPE_CONTROLLER_H_
#define __SHAPE_CONTROLLER_H_

#include "Graph.h"
#include "Simple_window.h"

#include "Controller.h"

namespace fsdev {
	/*! Uses level to control the RGB of the shape's color, effectively giving you shades of gray.
	 *! Turning the controller on attaches all the shapes to the window; turning it off removes all
	 *! of the shapes from the window.
	 */
	class Shape_Controller : public Controller {
	private:
	protected:
		Simple_window &win;
		Vector_ref<Graph_lib::Shape> shapes;
	public:
		Shape_Controller(Simple_window& _win);
		void addShape(Graph_lib::Shape& s);
		void addShape(Graph_lib::Shape * s);
		Graph_lib::Shape& shapeAt(size_t idx);
		void on();
		void off();
		void set_level(int l);
		void show();
	};
}

#endif
