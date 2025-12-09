// Driver program for CSCI 60 Homework 9; due Thursday 12/4/25
//
// MILESTONE 0: Implement stub functions in the other .cpp files to make sure
// this compiles. Once you do, add test code as you work through Milestones 1-4
// to make sure each function is implemented correctly before moving on.
// This file is just for you; do not turn it in.

#include <iostream>
#include "parity.h"

using namespace std;

int main() {
  Parity lists;
  lists.insert(0);
  lists.insert(1);
  lists.insert(8);
  lists.insert(-2);
  lists.insert (7);
  for (auto e : lists) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}

