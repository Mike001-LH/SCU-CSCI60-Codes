// Parity interface file for CSCI 60 Homework 9; due Thursday 12/4/25

#ifndef PARITY_H
#define PARITY_H

#include <iostream>
#include <climits>
using std::ostream;

#include "node.h"
#include "p_iterator.h"

class Parity {
public:
  // constructors and functions to override for dynamic memory management
  Parity() : h_e(nullptr),t_e(nullptr),h_o(nullptr),t_o(nullptr),n_e(0),n_o(0){}//n_e和n_o是even和odd链表插入的元素个数
  Parity(const Parity& other); // deep copy other's contents into new object
  ~Parity(); // deallocate calling object's memory and reset member vars
  Parity& operator=(const Parity& rhs); // free memory, deep copy rhs contents

  // mutator
  void insert(int val); // insert val in appropriate list in sorted order

  // accessors
  int min() const; // return smallest val in either list
  int max() const; // return largest val in either list
  friend ostream& operator <<(ostream& out, const Parity& lists); // print lists

  // iterators
  typedef P_iterator iterator;
  P_iterator begin() const; // return iterator pointing to start of both lists
  P_iterator end() const; // return iterator with nullptrs

private:
  node * h_e;
  node * t_e;
  size_t n_e;
  node * h_o;
  node * t_o;
  size_t n_o;
  // INVARIANTS: h_e/t_e address the first/last dynamic nodes in a SORTED
  //             linked list of the n_e even ints that have been inserted;
  //             h_o/t_o address the first/last dynamic nodes in a SORTED
  //             linked list of the n_o odd ints that have been inserted.
};

#endif
