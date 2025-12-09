// Node interface (untemplatized) for CSCI 60 Homework 8; due Wednesday 11/19/25
// Sara Krehbiel, modified code from Natalie Linnell and Nicholas Tran

#ifndef NODE_H
#define NODE_H
#include <iostream>
using std::ostream;

class node {
public:
    // constructor(s)
    node (int d = 0, node *l = nullptr) : data_(d), link_(l) {}

    // accessors
    int data() const { return data_; }
    node* link() const { return link_; }

    // mutators
    void set_data(int newdata) { data_ = newdata; }
    void set_link(node * newlink) { link_ = newlink; }

private:
    int data_;
    node * link_;
};

// for debugging (already implemented in node.cpp)
ostream& operator <<(ostream& out, const node* head); 

// declarations for HW8 functions (TODO: implement in node.cpp)
int f1(int n);
void f2(int* a, int first, int last);
void f3(node*& head, node*& tail, int* a, int n);
void f4(node*& head, node*& tail);

#endif // NODE_H
