/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091212, Chapter 19 Assignment
 */

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <cstddef> /* for NULL */
#include <stdexcept>

#include "Node.h"
#include "ListIterator.h"

#ifndef __weak
#define __weak
#endif

#ifndef __strong
#define __strong
#endif

namespace fsdev {
	
	template<typename T>
	class LinkedList {
	private:
		__strong Node<T> * root;
		int current_size;
	public:
		LinkedList()
		: root(NULL), current_size(0) {
		}

		~LinkedList() {
			delete root;
		}

		void add(const T& o) {
			if(root==NULL) {
				root = new Node<T>();
				root->o = o;
			} else {
				Node<T> * n;
				if(o < root->o) {
					// replace root
					n = new Node<T>();
					n->o = o;
					n->n = root;
					root->p = n;
					root = n;
				} else {
					n = root;
					while(n->n!=NULL&&o >= n->o)
						n = n->n;
					Node<T> * m = new Node<T>();
					m->o = o;
					m->p = n;
					m->n = n->n;
					if(n->n!=NULL)
						n->n->p = m;
					n->n = m;
				}
			}
			++current_size;
		}

		int find(const T& o) const {
			if(root==NULL)
				return -1;
			Node<T> * n = root;
			for(int i=0; n!=NULL; ++i, n=n->n)
				if(n->o == o)
					return i;
			return -1;
		}

		void del(const T& o) {
			int i = find(o);
			if(i==-1)
				return;
			else
				del(find(o)); // lol
		}

		void del(const int i) {
			if(i>=current_size) {
				throw new std::out_of_range("Supplied index is not within the boundaries of the receiver.");
				return;
			}
			Node<T> * n = root;
			for(int j=0; j!=i; ++j)
				n = n->n;
			if(n==root) {
				root=n->n;
				n->n=NULL;
				delete n;
			} else {
				if(n->n==NULL) {
					n->p->n=NULL;
					delete n;
				} else {
					n->p->n=n->n;
					n->n->p=n->p;
					n->n=NULL;
					delete n;
				}
			}
			--current_size;
		}

		int size() const {
			return current_size;
		}

		bool empty() const {
			return current_size==0;
		}
		
		ListIterator<T>& begin() const {
			return *new ListIterator<T>(root);
		}
		
		ListIterator<T>& end() const {
			return *new ListIterator<T>(NULL);
		}
		
		T& operator[](const int i) const {
			if(i>=current_size) {
				throw new std::out_of_range("Supplied index is not within the boundaries of the receiver.");
				return NULL;
			}
			Node<T> * n = root;
			for(int j=0; j!=i; ++j)
				n = n->n;
			return n->o;
		}
	};
		
}

#endif
