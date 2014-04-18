/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140418, Chapter 18 Programming Challenge 1 - 5
 */

#ifndef __STACK_HPP__
#define __STACK_HPP__

#define EMPTY_STACK_MSG "stack is empty"
#define FULL_STACK_MSG "stack is full"

#include <iostream>
#include <cstddef>
#include <exception>
using namespace std;

/* static stack template */
template<class T>
class static_stack {
private:
  size_t size;
  size_t top_idx;
  T * data;
public:
  static_stack(size_t size) : size(size), top_idx(SIZE_MAX), data(new T[size]) { }
  ~static_stack() {
    if (size > 0) { delete [] data; }
  }
  T& top() const {
    if (top_idx == SIZE_MAX) { throw logic_error(EMPTY_STACK_MSG); }
    return data[top_idx];
  }
  void pop() {
    if (top_idx == SIZE_MAX) { throw logic_error(EMPTY_STACK_MSG); }
    top_idx++; if (top_idx == size) { top_idx = SIZE_MAX; }
  }
  void push(const T& t) {
    if (top_idx == 0) { throw logic_error(FULL_STACK_MSG); }
    if (top_idx == SIZE_MAX) { top_idx = size; }
    data[--top_idx] = t;
  }
  void __pretty_print__() const {
    cout << "{ ";
    if (top_idx != SIZE_MAX) {
      for (size_t i = top_idx; i != size; ++i) {
        cout << data[i];
        if (i+1 != size) { cout << ", "; }
      }
    }
    cout << " }" << endl;
  }
};

template<class T>
class dynamic_stack {
private:
  struct node {
    T data;
    node * next;
    node(T t, node * n = NULL) : data(t), next(n) { }
  };
  node * top_ptr;
  node * bottom_ptr;
public:
  dynamic_stack() : top_ptr(NULL), bottom_ptr(NULL) { }
  ~dynamic_stack() {
    if (top_ptr == NULL) { return; }
    for (node * n0 = top_ptr, * n1 = NULL; n0->next != NULL;) {
      n1 = n0->next;
      delete n0;
      swap(n0, n1);
    }
  }
  T& top() const {
    if (top_ptr == NULL) { throw logic_error(EMPTY_STACK_MSG); }
    return top_ptr->data;
  }
  void pop() {
    node * n0 = top_ptr;
    top_ptr = n0->next;
    delete n0;
  }
  void push(const T& t) {
    if (top_ptr == NULL) {
      top_ptr = bottom_ptr = new node(t);
    } else {
      top_ptr = new node(t, top_ptr);
    }
  }
  void __pretty_print__() const {
    cout << "{ ";
    if (top_ptr != NULL) {
      for (node * n0 = top_ptr; n0 != NULL; n0 = n0->next) {
        cout << n0->data;
        if (n0->next != NULL) { cout << ", "; }
      }
    }
    cout << " }" << endl;
  }
};

#endif
