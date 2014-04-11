/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140411, Chapter 17 Class Work 1
 */

#include <cstddef>
#include <memory>
#include <iostream>
#include <exception>
using namespace std;

#ifndef __CLINKED_LIST_HPP__
#define __CLINKED_LIST_HPP__

template<class T>
class clinked_list {
private:
  struct node {
    T data;
    node * next;
    node * prev;
    node() : next(NULL), prev(NULL) { }
    node(T data, node * prev,node * next) : data(data), next(next), prev(prev) { }
  };
  node * head;
public:
  clinked_list() : head(NULL) { }
  ~clinked_list() {
    clear();
  }

  void append(T t) {
    insert(t, SIZE_MAX);
  }
  void insert(T t, size_t pos=0) {
    if (head == NULL) {
      head = new node(t, NULL, NULL);
      link(head,head);
      return;
    }
    if (pos == 0) {
      head = new node(t, NULL, head);
      link(head->next->prev, head);
      link(head, head->next);
      return;
    }
    node * curr = head; size_t loc = 0;
    for (;curr->next != head && loc < pos; curr = curr->next, loc++) { }
    node * inserted = new node(t, NULL, NULL);
    link(inserted, curr->next);
    link(curr, inserted);
  }
  void remove(T t) {
    if (head == NULL) { return; }
    node * curr = head;
    while (curr->next != head && curr->data != t) { curr = curr-> next; }
    if (curr->data == t) {
      if (curr == head) {
        if (head->next == head) {
          delete head;
          head = NULL;
        } else {
          node * old_head = head;
          head = head->next;
          link(old_head->prev, head);
          delete old_head;
        }
      } else {
        link(curr->prev,curr->next);
        delete curr;
      }
    }
  }
  void clear() {
    if (head == NULL) { return; }
    node * curr = head->prev;
    while (curr != head) {
      curr = curr->prev;
      delete curr->next;
    }
    delete head;
    head = NULL;
  }
  void print() {
    cout << "{ ";
    if (head != NULL) {
      node * curr = head;
      do {
        cout << curr->data;
        if (curr->next != head) { cout << ", "; }
        else { cout << " "; }
        curr = curr->next;
      } while (curr != head);
    }
    cout << "}" << endl;
  }
  T operator[](size_t idx) {
    if (head == NULL) { throw invalid_argument("index out of bounds"); }
    node * curr; size_t i;
    for (i = 0, curr = head; curr->next != head && i < idx; curr = curr->next, i++) { }
    if (i != idx) { throw invalid_argument("index out of bounds"); }
    return curr->data;
  }
  void link(node * n0, node * n1) {
    n0->next = n1; n1->prev = n0;
  }
};

#endif
