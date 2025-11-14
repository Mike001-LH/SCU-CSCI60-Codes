// Interface file for CSCI 60 Homework 6; due Wednesday 11/5/25

#ifndef PARITY_H
#define PARITY_H

#include <iostream>
#include <climits>

using std::cout;
using std::endl;
using std::ostream;

class Parity {
public:
  // constructors and functions to override for dynamic memory management
  Parity() : nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr) { };
  Parity(int * a, size_t n);

  // NEW memory management functions
  Parity(const Parity& rhs);
  ~Parity();
  Parity& operator =(const Parity& rhs);

  // NEW and revised mutators (must meet specifications from assignment HO)
  void insert(int val); // adds a single copy of val, maintaining order
  size_t remove(int val); // removes ALL copies of val and returns # removed

  // accessors
  int min() const;
  int max() const;
  bool odd() const;
  friend ostream& operator <<(ostream& out, const Parity& p);

private:
  size_t nEven_;
  size_t nOdd_;
  int *evens_;
  int *odds_;
  static const size_t CAP = 5;
  // INVARIANTS: evens_ points to a dynamic array of the nEven_ even ints;
  //             odds_ points to a dynamic array of the nOdd_ odd ints.
  //             *** Both should store values in ASCENDING ORDER, regardless 
  //                 of the order in which they were provided through either 
  //                 the array-based constructor or insert calls.            ***
  //             The space allocated for each should be the smallest multiple of 
  //             CAP that is at least the number of elements in the array. 
};


#endif
