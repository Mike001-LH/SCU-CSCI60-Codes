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
  GArray(const GArray& other);// copy constructor //构造函数前面 没有返回类型
  ~GArray();
  GArray& operator =(const GArray& rhs); //赋值运算符：返回 GArray&（引用）

  // mutator
  void insert(int val); // insert in new, slightly larger array

  // accessors 
  size_t length() const { return size_; }
  int operator [](size_t i) const { return data_[i]; }//下标运算符：返回 int（数组元素）

  // iterator
  typedef GA_Iterator iterator;
  // TODO: declare and define begin and end functions

private:
  size_t size_;
  int *data_;
};

ostream& operator <<(ostream& out, const GArray& a);

#endif