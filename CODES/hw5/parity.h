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
  Parity() : nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr) { };// 0-argument constructor
  Parity(int* a, size_t n);// 2-argument constructor to initialize from array a of size n

  // memory management functions for HW6
  //Parity(const Parity& rhs);
  //~Parity();
  //Parity& operator =(const Parity& rhs);

  // mutator
  void insert(int val); 
  //size_t remove(int val); // for HW6


  // accessors
  int min() const;//返回最小值
  int max() const;//返回最大值
  bool odd() const;//返回是否奇数个元素，如果是奇数个返回true，否则返回false
  friend ostream& operator <<(ostream& out, const Parity& p);

private:
  size_t nEven_;//这是偶数的数量
  size_t nOdd_;//这是奇数的数量
  int* evens_;//这是一个指向动态分配的偶数数组的指针
  int* odds_;//这是一个指向动态分配的奇数数组的指针
  static const size_t CAP = 5; //这是每次扩容的容量增量
  // INVARIANTS: evens_ points to a dynamic array of the nEven_ even ints;
  //             odds_ points to a dynamic array of the nOdd_ odd ints.
  //             The space allocated for each should be the smallest multiple of 
  //             CAP that is at least the number of elements in the array. 
};


#endif
