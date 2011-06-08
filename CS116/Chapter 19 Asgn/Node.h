/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091212, Chapter 19 Assignment
 */

#ifndef __NODE_H__
#define __NODE_H__

#include <cstddef> /* for NULL */

#ifndef __weak
#define __weak
#endif

#ifndef __strong
#define __strong
#endif

namespace fsdev {
	
	template<typename T>
	struct Node {
		T o;
		__weak Node * p;
		__strong Node * n;
		Node()
		: p(NULL), n(NULL) {
		}
		~Node() {
			// p is __weak
			delete n;
		}
	};
	
}

#endif
