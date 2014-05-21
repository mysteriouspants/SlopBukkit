/* Chris Miller (imperator@pax-imperia.com), CS124
 * Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 * Academic endorsement.  This code is not licensed for commercial use.
 * 20140521, Final
 */

/* NOTE THAT THE ASSIGNMENT CALLED FOR A BINARY TREE WITHOUT
 * SEARCH-IMPLIED ORDERING
 */

#include "binary_tree.hpp"
#include <iostream>
using namespace std;

struct amorphous_node {
  int data;
  amorphous_node * left, * right;
  amorphous_node(int data, amorphous_node * left = NULL, amorphous_node * right = NULL) : data(data), left(left), right(right) { }
  ~amorphous_node() {
    if (left) {
      if (left->right == this) { left->right = NULL; } // ll case
      delete left; left = NULL;
    }
    if (right) {
      if (right->left == this) { right->left = NULL; } // ll case
      delete right; right = NULL;
    }
  }
  amorphous_node(amorphous_node& n) : data(n.data) {
    if (n.left) { left = new amorphous_node(*n.left); }
    if (n.right) { right = new amorphous_node(*n.right); }
  }
  
  amorphous_node * leftmost() {
    if (left) { return left->leftmost(); }
    else { return this; }
  }
  amorphous_node * rightmost() {
    if (right) { return right->rightmost(); }
    else { return this; }
  }
  
  bool is_leaf() { return !left && !right; }
  
  amorphous_node * flatten() {
    if (left && left->is_leaf()) {
      left->right = this;
    }
    else if (left) {
      left = left->flatten();
      left = left->rightmost();
      left->right = this;
    }
    
    
    if (right && right->is_leaf()) {
      right->left = this;
    }
    else if (right) {
      right = right->flatten();
      right = right->leftmost();
      right->left = this;
    }
    
    return this;
  }
};



struct linked_list {
  amorphous_node * head;
  ~linked_list() { if (head) { delete head; } }
  void pretty_print() {
    cout << "{ ";
    amorphous_node * n = head;
    while (n) {
      cout << n->data << ", ";
      n = n->right;
    }
    cout << "}" << endl;
  }
};

struct binary_tree1 {
  amorphous_node * root;
  ~binary_tree1() { if (root) { delete root; } }
  void flatten_into_linked_list(linked_list& ll) {
    if (!root) { return; }
    amorphous_node * n = new amorphous_node(*root); // copy dat shit
    n->flatten();
    while (n->left) { n = n->left; }
    ll.head = n;
  }
  void pretty_print() {
    cout << "{ ";
    pretty_print_r(root);
    cout << "}" << endl;
  }
  void pretty_print_r( amorphous_node * n ) {
    if (!n) { return; }
    pretty_print_r(n->left);
    cout << n->data << ", ";
    pretty_print_r(n->right);
  }
};

int main(int args, const char* argv[]) {
  // 1: create this binary tree
  cout << "binary_tree1: ";
  binary_tree1 bt; // this is the one defined in this file
  bt.root = new amorphous_node(10,
                               new amorphous_node(12,
                                                  new amorphous_node(25),
                                                  new amorphous_node(30)
                                                  ),
                               new amorphous_node(15,
                                                  new amorphous_node(36))
                               );
  bt.pretty_print();
  
  // 2: convert the tree to a doubly-linked list
  cout << "linked_list: ";
  linked_list ll;
  bt.flatten_into_linked_list(ll);
  ll.pretty_print();
  
  // 3: fart that into a binary search tree
  // my previous binary search tree was used because I didn't feel like making
  // a new one. suffice it to say, the process for converting a list or binary tree
  // to a binary search tree involves iterating through all nodes and adding them one-by-one,
  // anyway
  
  cout << "binary search tree: ";
  binary_tree<int> bt0;
  amorphous_node * n = ll.head;
  do {
    bt0.insert(n->data);
    n = n->right;
  } while (n);
  bt0.pretty_print(cout);
  
  // printing all the while
  
  return 0;
}
