/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091207, Chapter 17 Assignment
 */

#ifndef __LINK_H__
#define __LINK_H__

#include "GenericStruct.h"
#include <iostream>

namespace fsdev {
	class Link {
	protected:
		void print_all_helper();
	public:
		GenericStruct data;
		Link* prev;
		Link* next;
		Link(GenericStruct _data,
			 Link * _prev = NULL,
			 Link * _next = NULL)
		: data(_data), prev(_prev), next(_next) {
			
		}
		void link_next(GenericStruct _data);
		void link_prev(GenericStruct _data);
		void add_ordered(GenericStruct _data);
		Link* rewind();
		void print_all();
	};
}

#endif
