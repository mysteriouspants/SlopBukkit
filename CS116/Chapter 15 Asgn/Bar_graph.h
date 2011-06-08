/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091116, Chapter 15 Assignment
 */

#ifndef __BAR_GRAPH_H_
#define __BAR_GRAPH_H_

#include "Graph.h"

namespace fsdev {
	class Bar_graph : public Graph_lib::Shape {
	protected:
		size_t baseline;
	public:
		Bar_graph(size_t _baseline);
		void add(Point p) { Shape::add(p); }
		void draw_lines() const;
	};
}

#endif