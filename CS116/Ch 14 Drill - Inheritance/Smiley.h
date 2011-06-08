/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091026, Chapter 14 Drill - Inheritance
 */

#ifndef __SMILEY_H_
#define __SMILEY_H_

#include "Graph.h"
#include "Point.h"

namespace Graph_lib {
	
	class Foo {
	public: 
		virtual void bar();
		virtual ~Foo();
	protected:
		Foo();
		Foo(int bar);
	};

	class Face : public Circle {
	public:
		Face(Point p, int rr) : Circle::Circle(p, rr) {
			
		}
		void draw_lines() const;
	};
	
	class Smiley : public Face {
	public:
		Smiley(Point p, int rr) : Face::Face(p, rr) {
			
		}
		void draw_lines() const;
	};
	
	class Frowny : public Face {
	public:
		Frowny(Point p, int rr) : Face::Face(p, rr) {
			
		}
		void draw_lines() const;
	};
	
	class SmileyHat : public Smiley {
	public:
		SmileyHat(Point p, int rr) : Smiley::Smiley(p, rr) {
			
		}
		void draw_lines() const;
	};
	
	class FrownyHat : public Frowny {
	public:
		FrownyHat(Point p, int rr) : Frowny::Frowny(p, rr) {
			
		}
		void draw_lines() const;
	};
	
	class Hat : public Shape {
	public:
		Hat(Point origin, Point dd);
		void draw_lines() const;
	protected:
		Point dimensions;
	};
	
}

#endif
