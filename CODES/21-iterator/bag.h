// Interface and implementation of templatized linked list bag
// Sara Krehbiel, 11/15/25-11/21/25

#ifndef BAG_H
#define BAG_H

#include "node.h"
#include "l_iterator.h" // NEW!
#include <iostream>
using std::ostream;

template <typename T>
class Bag {
public:
  // 0-arg constructor 
  Bag() : head(nullptr), tail(nullptr) {}

  // memory management functions
  Bag(const Bag<T>& other) : Bag() { list_copy(head,tail,other.head); }
  Bag<T>& operator =(const Bag<T>& rhs);
  ~Bag() { list_clear(head,tail); }
  
  // accessors
  size_t size() const { return list_size(head,tail); } // # elems in bag
  bool contains(const T& val) const { return list_search(head,tail,val); }
  size_t count(const T& val) const { return list_count(head,tail,val); } 

  // mutators
  void insert(const T& val) { list_insert_head(head,tail,val); } // add to front
  bool erase_one(const T& val) { return list_remove_one(head,tail,val); }
  size_t erase(const T& val) { return list_remove_all(head,tail,val); }

  // friend utility function(s)
  template <typename T2>
  friend ostream& operator <<(ostream& o, const Bag<T2>& b);

  // iterator code for Bag
  typedef L_iterator<T> iterator; // iterator is alias for L_iterator<T>
  // TODO: decide on member vars for L_iterator
  iterator begin() { return iterator(head); } // write/call constructors accordingly
  iterator end() { return iterator(); }
  

private:
  node<T> * head;
  node<T> * tail;
  // invariants: head and tail point to the first and last nodes, respectively,
  //             in a dynamic linked list, or they are null if the list is empty
};


/* implementations of related non-member fns/member fns not defined inline */

// overloaded assignment operator for clearing one list and deep copying another
template <typename T>
Bag<T>& Bag<T>::operator =(const Bag<T>& rhs) {
  list_clear(head,tail); // deallocate existing contents of calling object
  list_copy(head,tail,rhs.head); // deep copy from rhs into calling object
  return *this;
}

// outputs contents of bag's list
template <typename T>
ostream& operator <<(ostream& o, const Bag<T>& b) {
  return o << b.head; // prints address of head OR calls << overloaded for node*
}


#endif
