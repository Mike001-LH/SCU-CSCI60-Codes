// Interface and implementation of templatized linked list bag
// Sara Krehbiel, 11/14/25

#ifndef BAG_H
#define BAG_H

#include "node.h"
#include <iostream>
using std::ostream;

template <typename T>
class Bag {
public:
  // 0-arg constructor 
  Bag() : head(nullptr), tail(nullptr) {}

  // TODO: implement copy constructor, overloaded assignment, and destructor

  // accessors
  size_t size() const { return list_size(head, tail); } 
  // TODO: implement to return # elements in bag
  // TODO: accessor to count the # entries with a particular value

  // mutators
  void insert(const T& val); // TODO: implement to add to FRONT
  // TODO: mutators to erase_one or erase all copies of a particular value

  // TODO: understand function signature and why it must be a friend
  template <typename T2>
  friend ostream& operator <<(ostream& o, const Bag<T2>& b);

private:
    T data_;
    node<T>* link_; // link is the ADDRESS of the next node
  // invariants: head and tail point to the first and last nodes, respectively,
  //             in a dynamic linked list, or they are null if the list is empty
};


// TODO: implement additional bag functionality here

#endif
