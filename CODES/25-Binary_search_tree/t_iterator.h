// Sara Krehbiel, 12/5/25

// NOTE: This iterator uses a data structure called a stack to keep track of
// its state; we didn't discuss stacks as data structures, although if you
// look into it you will find that they work very much the same as a program
// stack frame, which we've been discussing a lot drawing memory diagrams!
// The functions are all implemented inline, which is not best practice, but 
// makes it easier to see everything that's going on at once.

#ifndef T_ITERATOR_H
#define T_ITERATOR_H

#include <cstdlib>
#include <ostream>
#include <vector>
#include <stack>
#include "node.h"

// iterator for in-order traversal of node-based binary tree
template <typename T>
class T_iterator {
public:
  T_iterator(node<T>* root = nullptr) {
    while (root != nullptr) { // stack up leftmost path from root to smallest
      s.push(root);
      root = root->left();
    }
  }

  T operator *() const {
    return s.top()->data();
  }

  bool operator ==(const T_iterator<T>& rhs) const { return (s==rhs.s); }
  bool operator !=(const T_iterator<T>& rhs) const { return !(s==rhs.s); }

  // to respect left->self->right order, pop self and get ready for right
  T_iterator<T>& operator ++() {
    // move past the node at the top
    node<T>* top = s.top();
    s.pop();
    // if there's a right subtree, stack up leftmost path to its smallest node
    if (top->right()!=nullptr) {
      top = top->right();
      while (top != nullptr) {
        s.push(top);
        top = top->left();
      }
    }
    return (*this); // return reference to my updated self
  }

  T_iterator<T> operator ++(int) {
    T_iterator<T> initialConfig(*this); // default copy constructor -- copies stack (deep copy overloaded)
    ++(*this);
    return initialConfig;
  }

private:
  std::stack<node<T>*> s;
  // invariant: represents snapshot of in-order traversal recursive callstack
  // important stack member functions are push, pop, and top
};

#endif // T_ITERATOR_H
