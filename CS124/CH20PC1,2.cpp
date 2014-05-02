/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140502, Chapter 20 Programming Challenges 1, 2
 */

#include <iostream>
#include <utility>
#include <array>
using namespace std;

template<class T>
class binary_tree {
  struct node {
    T data;
    node * left, * right;
    node(T t, node * l = NULL, node * r = NULL) : data(t), left(l), right(r) { }
    ~node() { delete left; delete right; }
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
public:
  binary_tree() : root(NULL) { }
  ~binary_tree() { if (root) { delete root; } }
  void insert(T t) {
    node * n = new node(t);
    insert_r(root, n);
  }
  size_t count() {
    return count_r(root);
  }
  void pretty_print(ostream& os) {
    os << "{ ";
    if (root) { pretty_print_r(os, root); }
    os << "}" << endl;
  }
};

int main(int argc, char *argv[]) {
  array<int, 11> kebabs{ {12, 7, 9, 10, 22, 24, 30, 18, 3, 14, 20} };
  binary_tree<int> t;
  cout << "empty tree: "; t.pretty_print(cout);
  for (auto& kebab: kebabs) {
    t.insert(kebab);
  }
  cout << "filled tree of " << t.count() << " elements: "; t.pretty_print(cout);
  return 0;
}