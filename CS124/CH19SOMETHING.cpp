/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140501, Chapter 19 "Something Prof Fang Thought Up"
 *
 * Exact prompt:
 * 2. write recursive ADD and REMOVE, and REVERSE member functions ON 
 * LINKED LIST with excutable results; (three files: pseudo-code, .cpp, and 
 * screen-shot);
 */

#include <iostream>
#include <utility>
using namespace std;

template<class T>
class linked_list {
  struct node {
    T data;
    node * next_ptr;
    node(T t, node * next = NULL) : data(t), next_ptr(next) { }
    void purge() {
      if (next_ptr) { next_ptr->purge(); }
      delete next_ptr;
    }
    node * append(T t) {
      if (next_ptr) {
        return next_ptr->append(t);
      } else {
        next_ptr = new node(t);
        return next_ptr;
      }
    }
    pair<node *, node *> remove_next_if_eq(T t) {
      if (next_ptr) {
        if (next_ptr->data == t) {
          node * n = next_ptr;
          next_ptr = n->next_ptr;
          return pair<node *, node *>(this, n);
        } else {
          return next_ptr->remove_next_if_eq(t);
        }
      } else {
        return pair<node *, node *>(this, NULL);
      }
    }
    void exchange_next(node * next) {
      if (next_ptr) { next_ptr->exchange_next(this); }
      next_ptr = next;
    }
  };
  node * head_ptr;
  node * tail_ptr;
public:
  linked_list() : head_ptr(NULL), tail_ptr(NULL) { }
  ~linked_list() {
    if (head_ptr) {
      head_ptr->purge();
      delete head_ptr;
    }
  }
  void append(T t) {
    if (tail_ptr) {
      tail_ptr = tail_ptr->next_ptr = new node(t);
    } else {
      head_ptr = tail_ptr = new node(t);
    }
  }
  void remove(T t) {
    if (head_ptr) {
      if (head_ptr->data == t) {
        node * n = head_ptr;
        head_ptr = n->next_ptr;
        if (head_ptr == tail_ptr) { tail_ptr = NULL; }
        delete n;
      } else {
        pair<node *, node *> result = head_ptr->remove_next_if_eq(t);
        if (result.second == tail_ptr) { tail_ptr = result.first; }
        if (result.second) { delete result.second; }
      }
    }
  }
  void reverse() {
    head_ptr->exchange_next(NULL);
    swap(head_ptr, tail_ptr);
  }
  void pretty_print() {
    cout << "{ ";
    for (node * n = head_ptr; n != NULL; n = n->next_ptr) {
      cout << n->data;
      if (n->next_ptr != NULL) { cout << ", "; }
    }
    cout << " }" << endl;;
  }
};

int main(int argc, char *argv[]) {
  linked_list<int> l;
  cout << "list with no elements: "; l.pretty_print();
  for (int i = 1; i < 11; i++) { l.append(i); }
  cout << "list with ten elements: "; l.pretty_print();
  l.remove(5);
  cout << "remove 5: "; l.pretty_print();
  l.reverse();
  cout << "reversed list: "; l.pretty_print();
  
  return 0;
}