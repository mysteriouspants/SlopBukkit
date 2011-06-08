/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091207, Chapter 17 Extra-Credit Assignment
 */

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>

namespace fsdev {
	
	template<class T>
	struct Node {
		T value;
		Node<T> * next;
		Node() : next(0), value() {
		}
	};
	
	template<class T>
	class LinkedList {
	private:
		Node<T> * root;
	public:
		LinkedList() : root(0) {
		}
		void add(const T& t) {
			if(root==0) {
				root=new Node<T>();
				root->value = t;
				root->next = 0;
			} else {
				if(t<root->value) {
					//replace root
					Node<T> * n = new Node<T>();
					n->value = t;
					n->next = root;
					root = n;
				} else {
					Node<T> * n = root;
					while(n->next!=0&&n->value<=t)
						n = n->next;
					Node<T> * i = new Node<T>();
					i->value = t;
					i->next = n->next;
					n->next = i;
				}
			}
		}		
		int find(const T& t) {
			Node<T> * n = root;
			int i=0;
			while(n!=0) {
				if(n->value==t)
					return i;
				else {
					++i;
					n = n->next;
				}
			}
			return -1;
		}
		void remove(const int& i) {
			int j=0;
			Node<T> * n = root;
			for(;
				j<i-1 && n!=0;
				++j, n = n->next) { }
			if(j==i-1) {
				Node<T> * d = n->next;
				n->next = n->next->next;
				delete d;
			}
			
		}
		void print_all() const {
			Node<T> * n = root;
			while(n!=0) {
				std::cout << n->value << std::endl;
				n = n->next;
			}
		}
	};
	
}

#endif
