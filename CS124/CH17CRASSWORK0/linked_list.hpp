/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140411, Chapter 17 Class Work 0
 */

#include <cstddef>
#include <memory>
#include <iostream>
using namespace std;

#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

template<class T>
class linked_list {
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
  linked_list() : head(NULL) { }
  linked_list(const linked_list& linked_list) {
    if (linked_list.head == NULL) { head = NULL; return; }
    head = new node();
    node * my_curr = head;
    node * their_curr = linked_list.head;
    while (their_curr != NULL) {
      my_curr->data = their_curr->data;

      if (their_curr->next != NULL) {
        my_curr->next = new node(their_curr->next->data, my_curr, NULL);
        my_curr->next->prev = my_curr;
        my_curr = my_curr->next;
      }
      their_curr = their_curr->next;
    }
  }
  ~linked_list() {
    clear();
  }

  void append(T t) {
    if (head == NULL) {
      head = new node(t, NULL, NULL);
    } else {
      node * curr = head;
      while (curr->next != NULL) { curr = curr->next; }
      curr->next = new node(t, curr, NULL);
    }
  }
  void insert(T t, size_t pos=0) {
    if (head == NULL) { head = new node(t, NULL, NULL); return; }
    if (pos == 0) { head = new node(t, NULL, head); head->next->prev = head; return; }
    node * curr = head; size_t loc = 0;
    for (;curr->next != NULL && loc < pos; curr = curr->next, loc++) { }
    curr->next = new node(t, curr, curr->next);
    if (curr->next->next != NULL) {
      curr->next->prev = curr->next;
    }
  }
  void remove(T t) {
    if (head == NULL) { return; }
    node * curr = head;
    while (curr->next != NULL && curr->data != t) { curr = curr-> next; }
    if (curr->data == t) {
      if (curr == head) {
        head = curr->next;
        head->prev = NULL;
        delete curr;
      } else {
        curr->prev->next = curr->next;
        if (curr->next != NULL) { curr->next->prev = curr->prev; }
        delete curr; /* lawl */
      }
    }
  }
  void clear() {
    node * curr = head;
    if (curr == NULL) { return; }
    while (curr->next != NULL) { curr = curr->next; }
    while (curr != NULL) {
      curr = curr-> prev;
      delete curr;
    }
    head = NULL;
  }
  void print() {
    cout << "{ ";
    if (head != NULL) {
      node * curr = head;
      while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL) { cout << ", "; }
        else { cout << " "; }
        curr = curr->next;
      }
    }
    cout << "}" << endl;
  }
  void reverse() {
    if (head == NULL) { return; }
    node * curr = head;
    while (curr->next != NULL) { curr = curr->next; }
    head = curr;
    do {
      swap(curr->next, curr->prev);
      curr = curr->next;
    } while (curr != NULL);
  }
  size_t search(T t) {
    node * curr = head;
    size_t pos;
    for (curr = head, pos = 0; curr->data != t && curr->next != NULL; curr = curr->next, pos++) { }
    if (curr->data == t) { return pos; }
    else { return SIZE_MAX; }
  }
};

#endif
