// Interface and implementation for BST built on modified binary tree nodes.
// Sara Krehbiel, 12/5/25

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <ostream>
#include <vector>
#include <stack>
#include "node.h"
#include "t_iterator.h"

using std::size_t;

// BST class implemented almost completely inline using new node functions
template <typename T>
class BST {
public:
  // iterators 
  typedef T_iterator<T> iterator;
  iterator begin() const { return iterator(root); }
  iterator end() const { return iterator(); }

  // constructor and dynamic memory management
  BST() : root(nullptr) {}
  BST(const BST<T> & b);
  ~BST();
  void operator =(const BST<T> & tree);

  // accessors
  size_t size() const { return tree_size(root); }
  bool contains(const T & target) const { return bst_search(target,root); }

  // mutators
  void insert(const T & target) {root = bst_insert(target,root); }

  // insertion operator overloaded as friend
  template<typename T2>
  friend std::ostream & operator <<(std::ostream & out, const BST<T2> & tree) { return (out << tree.root); }
private:
  node<T> *root;
};

// DYNAMIC MEMORY MANAGEMENT 

template<typename T>
BST<T>::~BST() {
  // will keep track of in-order deletion progress with a stack
  std::stack<node<T>*> s;

  // initialize stack with path from root to smallest
  while (root != nullptr) {
    s.push(root);
    root = root->left(); // can just use root as a temp variable at this point
  }

  // process one node at a time from the top of the stack
  node<T>* toDelete;
  while (!s.empty()) {
    toDelete = root = s.top(); // the node to process this iteration
    s.pop();
    // smallest node in current node's right subtree should be processed next
    if (root->right()!=nullptr) {
      root = root->right();
      while (root!=nullptr) {
        s.push(root);
        root = root->left();
      }
    }
    delete toDelete; // may have updated root since last pop, but not toDelete
  }
  root = nullptr;
}

template<typename T>
BST<T>::BST(const BST<T> & tree) {
  root = nullptr;
  for (auto val : tree) { // insert new copies of everything from tree
    insert(val);
  } // why is this algorithm bad for the efficiency of the new tree??
}

template<typename T>
void BST<T>::operator =(const BST<T> &rhs) {
  this->~BST<T>(); // first clear current contents
  for (auto val : rhs) { // then insert everything from rhs
    insert(val);
  } // this is not the best approach!
}

#endif // BST_H
