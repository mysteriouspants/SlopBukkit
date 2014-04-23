/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140422, Chapter 18 Programming Challenge 1 - 5, 7
 */

#include "stack.hpp"
#include <exception>
using namespace std;

#ifndef __STACK_CALC_HPP__
#define __STACK_CALC_HPP__

#define INSUFFICIENT_ELEMENTS "stack requires at least two elements to perform operation"

template<class T>
class static_stack_calc : public static_stack<T> {
private:
  typedef static_stack<T> sooper;
  bool __has_at_least_two_elements__() {
    return sooper::top_idx <= sooper::size - 2;
  }
public:
  static_stack_calc(size_t size) : static_stack<T>(size) { }
  void mult() {
    if (!__has_at_least_two_elements__()) { throw logic_error(INSUFFICIENT_ELEMENTS); }
    sooper::data[sooper::top_idx+1] = sooper::data[sooper::top_idx] * sooper::data[sooper::top_idx+1];
    sooper::pop();
  }
  void div() {
    if (!__has_at_least_two_elements__()) { throw logic_error(INSUFFICIENT_ELEMENTS); }
    sooper::data[sooper::top_idx+1] = sooper::data[sooper::top_idx] / sooper::data[sooper::top_idx+1];
    sooper::pop();
  }
  void add() {
    if (!__has_at_least_two_elements__()) { throw logic_error(INSUFFICIENT_ELEMENTS); }
    sooper::data[sooper::top_idx+1] = sooper::data[sooper::top_idx] + sooper::data[sooper::top_idx+1];
    sooper::pop();
  }
  void sub() {
    if (!__has_at_least_two_elements__()) { throw logic_error(INSUFFICIENT_ELEMENTS); }
    sooper::data[sooper::top_idx+1] = sooper::data[sooper::top_idx] - sooper::data[sooper::top_idx+1];
    sooper::pop();
  }
  void add_all() {
    while (__has_at_least_two_elements__()) { add(); }
  }
  void mult_all() {
    while (__has_at_least_two_elements__()) { mult(); }
  }
};

template<class T>
class dynamic_stack_calc : public dynamic_stack<T> {
  typedef dynamic_stack<T> sooper;
  bool __has_at_least_two_elements__() {
    return sooper::top_ptr != NULL && sooper::top_ptr->next != NULL;
  }
public:
  void mult() {
    if (!__has_at_least_two_elements__()) { throw logic_error(INSUFFICIENT_ELEMENTS); }
    sooper::top_ptr->next->data = sooper::top_ptr->data * sooper::top_ptr->next->data;
    sooper::pop();
  }
  void div() {
    if (!__has_at_least_two_elements__()) { throw logic_error(INSUFFICIENT_ELEMENTS); }
    sooper::top_ptr->next->data = sooper::top_ptr->data / sooper::top_ptr->next->data;
    sooper::pop();
  }
  void add() {
    if (!__has_at_least_two_elements__()) { throw logic_error(INSUFFICIENT_ELEMENTS); }
    sooper::top_ptr->next->data = sooper::top_ptr->data + sooper::top_ptr->next->data;
    sooper::pop();
  }
  void sub() {
    if (!__has_at_least_two_elements__()) { throw logic_error(INSUFFICIENT_ELEMENTS); }
    sooper::top_ptr->next->data = sooper::top_ptr->data - sooper::top_ptr->next->data;
    sooper::pop();
  }
  void add_all() {
    while (__has_at_least_two_elements__()) { add(); }
  }
  void mult_all() {
    while (__has_at_least_two_elements__()) { mult(); }
  }
};

#endif
