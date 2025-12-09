// Implementation of GArray, a growable dynamic array class
// Sara Krehbiel, slightly modified from 10/27/25

#include "garray.h"

GArray::GArray(const GArray& other) : size_(other.size_) {
  // allocate space for a new deep copy of other's data
  data_ = new int[size_];
  // deep copy contents from other.data_
  for (size_t i=0; i<size_; i++) {
    data_[i] = other.data_[i];
  }
  cout << data_ << ")\n";
}

GArray::~GArray() {
  delete [] data_; // prevents memory from being orphaned
  data_ = nullptr;
  size_ = 0;
}

// pre: data_ points to a filled dynamic array with size_ elements
// post: size_ is incremented and data_ points to a bigger array 
void GArray::insert(int val) {
  // store a newly allocated array of size size_+1 in a temp pointer
  int *temp = new int[size_+1];
  // copy contents from data_ to temp array, add val to the last entry
  for (size_t i=0; i<size_; i++) {
    temp[i] = data_[i];
  }
  // delete old data_ to avoid orphaning old array once we repoint to new array
  delete [] data_;
  // reassign data_ to the temp pointer
  data_ = temp;
  // put val in correct spot and increment size_
  data_[size_++] = val;
}

GArray& GArray::operator =(const GArray& rhs) {
  // check if calling object and rhs are the same, return if so
  if (&rhs == this) return *this; // NEW: why should we check this?
  if (size_!=rhs.size_) { // only need new space if my size is changing
    // update size_ of calling object
    size_ = rhs.size_; // size_ is the same as (*this).size_ or this->size_
    // delete old data_ for calling object
    delete [] data_;
    // point data_ to space for a new array that deep copies rhs array
    if (size_==0) data_ = nullptr;
    else data_ = new int[size_];
  }
  // deep copy
  for (size_t i=0; i<size_; i++) {
    data_[i] = rhs.data_[i];
  }
  return *this;
}

// get the length of the array and insert contents item-by-item using []
ostream& operator <<(ostream& out, const GArray& a) {
  size_t n = a.length();
  for (size_t i=0; i<n; i++) {
    out << a[i] << " ";
  }
  return out;
}
