// Interface for GArray, a growable dynamic arrays, now enhanced with an iterator
// Sara Krehbiel, modified 12/3/25

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>
#include "ga_iterator.h"

using std::ostream;
using std::cout;

class GArray {
public:
  // constructor and dynamic memory management functions
  GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor
  GArray(const GArray& other);
  ~GArray();
  GArray& operator =(const GArray& rhs);

  // mutator
  void insert(int val); // insert in new, slightly larger array

  // accessors 
  size_t length() const { return size_; }
  int operator [](size_t i) const { return data_[i]; }

  // iterator
  typedef GA_Iterator iterator;
  // TODO: declare and define begin and end functions
  // begin should return an iterator to the first element
  iterator begin() const {
	  return iterator(data_, data_ + size_);//调用迭代器的构造函数，
  }
  // current = data_（第一个元素），end = data_ + size_（越界位置）
  // end should return an iterator "one past" the last element
  iterator end() const {
	  return iterator(data_ + size_, data_ + size_);
  }
  // current = end pointer, end = end pointer

private:
  size_t size_;
  int *data_;
};

ostream& operator <<(ostream& out, const GArray& a);

#endif