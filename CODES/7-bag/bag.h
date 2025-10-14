// Complete interface for static array implementation of a container called Bag,
// which should holds up to CAPACITY ints, possibly with repetition. 
//
// Sara Krehbiel, via Natalie Linnell and Nicholas Tran, 10/6/25

#ifndef BAG_H
#define BAG_H

#include <cstdlib>//for size_t
using std::size_t; 

#include <iostream>//for console input and output
using std::ostream; // allows you to use ostream instead of std::ostream
// Note: using namespace std in class defns results in namespace pollution
// Note: using std::size_t instead of size_t is more portable

class Bag {
public:
  static const size_t CAPACITY = 1000; // static = NOT a member variable

  // constructors (post-conditions guarantee well-structured bags)
  Bag() : size_(0) { }
  Bag(int a[], size_t n);

  // accessors (pre- and post-conditions are the same well-structured bags)
  size_t size() const { return size_; }
  int operator [](size_t index) const { return data_[index]; }
 

  size_t count(int val) const; // returns #times target appears in data_

  // mutators (pre-conditions are well-structured bags, post-conditions differ)

  // Post: if the bag has excess capacity, val is inserted into the next
  //       available spot in data_ and size_ is incremented; no change otherwise
  void insert(int val) { if (size_<CAPACITY) data_[size_++] = val; } // TODO: give inline definition

  // Post: if data_ initially contained val, first copy is removed (overwritten)
  //       with size_ decremented and true returned; otherwise false is returned
  bool erase_one(int val);

  // Post: all copies of val are removed with # removed returned
  size_t erase(int val);

  // TODO: Decide on function signature for +=
  // Post: rhs contents are inserted in order to calling object, rhs unchanged
 
private:
	int data_[CAPACITY];
	size_t size_;
  // INVARIANT: data_[0],...,data_[size_-1] contain previously-inserted ints,
  //            and size_<=CAPACITY
};

// Post: bag with lhs and rhs contents in order returned, lhs and rhs unchanged
Bag operator +(const Bag& lhs, const Bag& rhs);

// TODO: discuss function signature for alternate non-member += implementation

// Post: in-order true contents of b.data_ are inserted into ostream o
ostream& operator <<(ostream& o, const Bag& b);


#endif
