// Node interface file for CSCI 60 Homework 9; due Thursday 12/4/25

#ifndef NODE_H
#define NODE_H
#include <iostream>
using std::ostream;

class node {
public:
  // creates a new node with given or default data and link values
  node(int data = 0, node* link = nullptr) : data_(data), link_(link) {}
  
  // const accessors
  int data() const { return data_; }
  node * link() const { return link_; }

  // mutators
  void set_data(int newdata) { data_ = newdata; }
  void set_link(node* newlink) { link_ = newlink; }

private:
  int data_;
  node * link_;
  // INVARIANTS: data_ is the node value and link_ points to next node
};

// non-member functions defined in node.cpp for additional list functionality
ostream& operator <<(ostream& out, const node * head);
void list_insert_head(node*& head, node*& tail, int val);
void list_insert_tail(node*& head, node*& tail, int val);
size_t list_size(const node* head);
bool list_search(const node* head, int val);
void list_clear(node*& head, node*& tail);


// MILESTONE 1: implement this in node.cpp

// pre: head and tail address the first and last nodes of a sorted parity object
// post: val has been added to the correct list in sorted order
void list_insert_sorted(node*& head, node*& tail, int val);

#endif // NODE_H
