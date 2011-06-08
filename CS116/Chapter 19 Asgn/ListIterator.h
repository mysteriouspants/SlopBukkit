/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091212, Chapter 19 Assignment
 */

#ifndef __LISTITERATOR_H__
#define __LISTITERATOR_H__

#include <iterator>

#include "Node.h"

#ifndef __weak
#define __weak
#endif

#ifndef __strong
#define __strong
#endif

namespace fsdev {
	
	template<typename T>
	class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
		Node<T> * n;
	public:
		ListIterator(Node<T> * nn)
		: n(nn) {
		}
		
		ListIterator(const ListIterator<T>& li)
		: n(li.n) {
		}
		
		ListIterator<T>& operator++() {
			n = n->n;
			return *this;
		}
		
		ListIterator<T>& operator++(int) {
			Node<T> * nn = n;
			n = n->n;
			return *new ListIterator<T>(nn);
		}
		
		bool operator==(const ListIterator<T>& rhs) {
			return n == rhs.n;
		}
		
		bool operator!=(const ListIterator<T>& rhs) {
			return n != rhs.n;
		}
		
		T& operator*() {
			return n->o;
		}
		
	};
	
}

#endif
