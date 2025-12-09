// Interface and implementation for BST nodes and associated functionality.
// Sara Krehbiel, 12/5/25

#ifndef NODE_H
#define NODE_H
#include <iostream>

template<typename T>
class node {
public:
  // constructors
  node(const T& d, node<T>* l, node<T>* r) : data_(d), left_(l), right_(r) {}
  node(const T& d = T()) : node(d,nullptr,nullptr) {}

  // accessors
  T data() const { return data_; }
  node<T>* left() const { return left_; }
  node<T>* right() const { return right_; }

  // mutators
  void set_data(const T& newdata) { data_ = newdata; }
  void set_left(node<T>* newlink) { left_ = newlink; }
  void set_right(node<T>* newlink) { right_ = newlink; }
private:
  T data_;
  node<T> *left_, *right_; // nodes in binary trees have up to two children each
};

// output all nodes in the subtree with specified root
template<typename T>
std::ostream& operator <<(std::ostream& out, const node<T>* root) {
  if (root==nullptr) return out;
  out << root->left(); // recursive call
  out << root->data() << " "; // insert a T value into the ostream
  out << root->right(); // recursive call
  return out;
  //return out << root->left() << root->data() << " " << root->right(); // all at once
}

// return the number of nodes in the subtree with specified root
template<typename T>
std::size_t tree_size(const node<T>* root) {
  if (root==nullptr) return 0; // empty subtree has size zero
  return tree_size(root->left())+1+tree_size(root->right()); // nonempty subtree consists of its root and two subtrees
}

// return whether the value is in the subtree with specified root
template<typename T>
bool bst_search(const T& val, const node<T>* root) {
  if (root==nullptr) return false; // identify that there is no subtree to search
  if (val<root->data()) return bst_search(val,root->left()); // search left subtree
  if (val>root->data()) return bst_search(val,root->right()); // search right subtree
  return true; // found the value at the root of the current subtree
}

// insert the value in the subtree with specified root (and return the root)
template<typename T>
node<T>* bst_insert(const T& val, node<T>* root) {
  if (root==nullptr) return new node<T>(val);
  if (val<root->data()) {
    node<T>* rootOfModifiedLeftSubtree = bst_insert(val,root->left()); // find where the new node should go in the left subtree, add it (or do nothing if already there), return rootOf
    root->set_left(rootOfModifiedLeftSubtree); // reset the link of the calling subtree to reflect maybe modified left subtree
  }
  if (val>root->data()) root->set_right(bst_insert(val,root->right()));
  return root; // return the root of the unmodified tree after locating the value already present
}

#endif // NODE_H
