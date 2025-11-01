// Interface file for CSCI 60 Homework 5; due Wednesday 10/29/25

#ifndef PARITY_H
#define PARITY_H

#include <iostream>
#include <climits>

using std::cout;
using std::endl;
using std::ostream;

class Parity {
public:
  // constructors 
  Parity() : nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr) { };
  Parity(int * a, size_t n);

  // memory management functions for HW6
  //Parity(const Parity& rhs);
  //~Parity();
  //Parity& operator =(const Parity& rhs);

  // mutator
  void insert(int val); 
  //size_t remove(int val); // for HW6


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
  //             The space allocated for each should be the smallest multiple of 
  //             CAP that is at least the number of elements in the array. 
};


#endif
