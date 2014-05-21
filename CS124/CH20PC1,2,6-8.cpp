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

struct employee {
  int id;
  string name;
  employee(int,string);
};

bool operator< (const employee&,const employee&);
bool operator> (const employee&,const employee&);
bool operator==(const employee&,const employee&);
ostream& operator<<(ostream&,employee&);

int main(int argc, char *argv[]) {
  {
    array<int, 11> kebabs{ {12, 7, 9, 10, 22, 24, 30, 18, 3, 14, 20} };
    binary_tree<int> t0;
    cout << "empty tree: "; t0.pretty_print(cout);
    for (auto& kebab: kebabs) {
      t0.insert(kebab);
    }
    cout << "filled tree of " << t0.count() << " elements: "; t0.pretty_print(cout);
    
    binary_tree<int> t1 = t0;
    cout << "assigned t1=t0: "; t1.pretty_print(cout);
    
    binary_tree<int> t2(t0);
    cout << "copied t2(t0): "; t2.pretty_print(cout);
    
    queue<int> q;
    t2.enqueue_in(q);
    
    cout << "queued things: { ";
    while (!q.empty()) {
      cout << q.front() << ", ";
      q.pop();
    }
    cout << "};" << endl;
  }
  
  {
    array<employee, 8> employees{ {
      { 1021, "John Williams" },
      { 1057, "Bill Witherspoon" },
      { 2487, "Jennifer Twain" },
      { 3769, "Sophia Lancaster" },
      { 1017, "Debbie Reece" },
      { 1275, "George McMullen" },
      { 1899, "Ashley Smith" },
      { 4218, "Josh Plemmons" }
    } };
    binary_tree<employee> t3;
    for (auto& kebab: employees) {
      t3.insert(kebab);
    }
    do {
      cout << "Be of entering an employee id, or -1 to escape: ";
      int id;
      cin >> id;
      if (id == -1) { break; }
      employee e(id, "");
      if (t3.has(e)) {
        cout << t3.find(e) << endl;
      } else {
        cout << "no such employee id in database" << endl;
      }
    } while (true);
  }
  return 0;
}

employee::employee(int id, string name) : id(id), name(name) { }
bool operator< (const employee& l,const employee& r) { return l.id < r.id; }
bool operator> (const employee& l,const employee& r) { return l.id > r.id; }
bool operator==(const employee& l,const employee& r) { return l.id == r.id; }
ostream& operator<<(ostream& o,employee& e) { o << "(" << e.id << ", " << e.name << ")"; return o; }