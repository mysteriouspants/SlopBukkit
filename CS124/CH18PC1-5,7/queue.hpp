/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140422, Chapter 18 Programming Challenge 1 - 5, 7
 */

 #ifndef __QUEUE_HPP__
 #define __QUEUE_HPP__

#define EMPTY_QUEUE_MSG "queue is empty"
#define FULL_QUEUE_MSG "queue is full"

#include <iostream>
#include <cstddef>
#include <exception>
using namespace std;

/* static stack template */
template<class T>
class static_queue {
private:
  size_t capacity;
  size_t size;
  size_t front_idx;
  size_t back_idx;
  T * data;
public:
  static_queue(size_t capacity) : capacity(capacity), size(0), front_idx(-1), back_idx(-1), data(new T[capacity]) { }
  ~static_queue() {
    if (capacity > 0) { delete [] data; }
  }
  T& front() const {
    if (front_idx == SIZE_MAX) { throw logic_error(EMPTY_QUEUE_MSG); }
    return data[front_idx];
  }
  void deq() {
    if (size == 0) { throw logic_error(EMPTY_QUEUE_MSG); }
    front_idx = (front_idx + 1) % capacity;
    size--;
  }
  void enq(const T& t) {
    if (capacity == size) { throw logic_error(FULL_QUEUE_MSG); }
    back_idx = (back_idx + 1) % capacity;
    data[back_idx] = t;
    size++;
    if (front_idx == SIZE_MAX) { front_idx = 0; }
  }
  void __pretty_print__() const {
    cout << "{ ";
    if (size > 0) {
      size_t i = front_idx, end_cond = (back_idx + 1) % capacity;
      do {
        cout << data[i];
        i = (i + 1) % capacity;
        if (i != end_cond) { cout << ", "; }
      } while (i != end_cond);
    }
    cout << " }" << endl;
  }
};

template<class T>
class dynamic_queue {
private:
  struct node {
    T data;
    node * next;
    node(T t, node * n = NULL) : data(t), next(n) { }
  };
  node * front_ptr;
  node * back_ptr;
public:
  dynamic_queue() : front_ptr(NULL), back_ptr(NULL) { }
  ~dynamic_queue() {
    if (front_ptr == NULL) { return; }
    for (node * n0 = front_ptr, * n1 = NULL; n0->next != NULL;) {
      n1 = n0->next;
      delete n0;
      swap(n0, n1);
    }
  }
  T& front() const {
    if (front_ptr == NULL) { throw logic_error(EMPTY_STACK_MSG); }
    return front_ptr->data;
  }
  void deq() {
    node * n0 = front_ptr;
    front_ptr = n0->next;
    delete n0;
  }
  void enq(const T& t) {
    if (back_ptr == NULL) {
      try {
        front_ptr = back_ptr = new node(t);
      } catch (bad_alloc e) {
        /* frankly it's better to bubble this up to the calling code, */
        /* but no failure response was defined by the assignment, so  */
        /* you get nothing                                            */
      }
    } else {
      try {
        back_ptr = back_ptr->next = new node(t);
      } catch (bad_alloc e) {
        /* frankly it's better to bubble this up to the calling code, */
        /* but no failure response was defined by the assignment, so  */
        /* you get nothing                                            */
      }
    }
  }
  void __pretty_print__() const {
    cout << "{ ";
    if (front_ptr != NULL) {
      for (node * n0 = front_ptr; n0 != NULL; n0 = n0->next) {
        cout << n0->data;
        if (n0->next != NULL) { cout << ", "; }
      }
    }
    cout << " }" << endl;
  }
};


 #endif
