/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091207, Chapter 17 Assignment
 */

#include "Link.h"

namespace fsdev {
	
	void Link::link_next(GenericStruct _data) {
		Link * n = new Link(_data);
		n->next = next;
		n->prev = this;
		if(next!=NULL)
			next->prev = n;
		next = n;
	}
	void Link::link_prev(GenericStruct _data) {
		if(prev!=NULL)
			prev->link_next(_data);
		else {
			Link * n = new Link(_data);
			n->next = this;
			prev = n;
		}
	}
	void Link::add_ordered(GenericStruct _data) {
		if(data==_data) {
			link_next(_data);
			return;
		}
		if(data<_data) {
			if(next==NULL) {
				link_next(_data);
				return;
			} else {
				if(data<_data&&_data<next->data) {
					link_next(_data);
					return;
				} else {
					next->add_ordered(_data);
					return;
				}
			}
		} else {
			if(prev==NULL) {
				link_prev(_data);
				return;
			} else {
				prev->add_ordered(_data);
				return;
			}
		}
		std::cout << "mega error #2" << std::endl;
	}
	Link* Link::rewind() {
		Link * l = this;
		while(l->prev!=NULL)
			l = l->prev;
		return l;
	}
	void Link::print_all() {
		rewind()->print_all_helper();
	}
	void Link::print_all_helper() {
		std::cout << data << std::endl;
		if(next!=NULL)
			next->print_all_helper();
	}
}
