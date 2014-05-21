/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140513, Chapter 20 Programming Challenges 1, 2, 6 - 8
 */

#include <iostream>
#include <utility>
#include <array>
#include <string>
#include <queue>
using namespace std;

template<class T>
class binary_tree {
  struct node {
    T data;
    node * left, * right;
    node(T t, node * l = NULL, node * r = NULL) : data(t), left(l), right(r) { }
    node(node& n) : data(n.data) {
      if (n.left) { left = new node(*n.left); }
      if (n.right) { right = new node(*n.right); }
    }
    ~node() { if (left) { delete left; } if (right) { delete right; } }
  };
  node * root;
  void insert_r(node * &clay, node * &kebab) {
    if (!clay) {
      clay = kebab;
    } else if (kebab->data < clay->data) {
      insert_r(clay->left, kebab);
    } else {
      insert_r(clay->right, kebab);
    }
  }
  void pretty_print_r(ostream& os, node * clay) {
    if (clay->left) { pretty_print_r(os, clay->left); }
    os << clay->data << ", ";
    if (clay->right) { pretty_print_r(os, clay->right); }
  }
  size_t count_r(node * clay) {
    if (clay) {
      return 1 + count_r(clay->left) + count_r(clay->right);
    } else {
      return 0;
    }
  }
  bool has_r(node * clay, T& t) {
    if (!clay) { return false; }
    if (clay->data == t) { return true; }
    if (t < clay->data) {
      return has_r(clay->left, t);
    } else {
      return has_r(clay->right, t);
    }
  }
  T& find_r(node*& clay, T& t) {
    if (!clay) {
      clay = new node(t);
      return clay->data;
    }
    if (clay->data == t) {
      return clay->data;
    }
    if (t < clay->data) {
      return find_r(clay->left, t);
    } else {
      return find_r(clay->right, t);
    }
  }
  void enqueue_in_r(node * clay, queue<T>& q) {
    if (!clay) { return; }
    enqueue_in_r(clay->left, q);
    q.push(clay->data);
    enqueue_in_r(clay->right, q);
  }
public:
  binary_tree() : root(NULL) { }
  binary_tree(binary_tree& t) :root(new node(*t.root)) { }
  ~binary_tree() { if (root) { delete root; } }
  void insert(T t) {
    node * n = new node(t);
    insert_r(root, n);
  }
  size_t count() {
    return count_r(root);
  }
  bool has(T& t) {
    return has_r(root, t);
  }
  T& find(T& t) {
    return find_r(root, t);
  }
  void pretty_print(ostream& os) {
    os << "{ ";
    if (root) { pretty_print_r(os, root); }
    os << "}" << endl;
  }
  void enqueue_in(queue<T>& q) {
    enqueue_in_r(root, q);
  }
  binary_tree& operator=(const binary_tree& rhs) {
    if (this == &rhs) { return *this; }
    binary_tree t(rhs);
    return t;
  }
};
