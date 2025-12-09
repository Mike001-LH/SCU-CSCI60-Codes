// Implementation file for CSCI 60 Homework 8; due due Wednesday 11/19/25
// Write your name and list collaborators here

#include "node.h"

// overloaded << for debugging (plus a bonus example of recursion!)
ostream& operator <<(ostream& out, const node * head) {
  if (head==nullptr) return out; // base case: empty list
  out << head->data() << " "; // non-recursively output the data of the head
  return (out << head->link()); // recursively output everything else
}

// stubs for HW8 functions
// write a function comment for each, plus more comments as appropriate

int f1(int n) { return -1; }
  
void f2(int * a, int first, int last) {}

void f3(node *& head, node *& tail, int * a, int n) {}

void f4(node *& head, node *& tail) {}
