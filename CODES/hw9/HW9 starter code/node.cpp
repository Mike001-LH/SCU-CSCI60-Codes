// Node implementation starter file for CSCI 60 Homework 9; due Thursday 12/4/25
// List any collaborators and write your name here

#include "node.h" // Don't add any additional libraries/namespaces!

// overloaded << to print entire list
ostream& operator <<(ostream& out, const node * head) {
  if (head==nullptr) return out;
  return out << head->data() << ", " << head->link();
}

// traverses through list, keeping track of and then returning # nodes
size_t list_size(const node* head) {
  if (head==nullptr) return 0;
  return 1+list_size(head->link());
}

// traverses through list, returning true if given val is found, false otherwise
bool list_search(const node* head, int val) {
  if (head==nullptr) return false;
  if (head->data()==val) return true;
  return list_search(head->link(),val);
}

// deletes all nodes associated with a list and sets head and tail to nullptr
void list_clear(node*& head, node*& tail) {
  node* next;
  while (head!=nullptr) {
    next=head->link();
    delete head;
    head=next;
  }
  tail=nullptr;
}

// inserts a node with specified value at the head (beginning/front) of a list
void list_insert_head(node*& head, node*& tail, int val) {
  head = new node(val,head);
  if (tail==nullptr) tail = head;
}

// inserts a node with specified value at the tail (end/back) of a list
void list_insert_tail(node*& head, node*& tail, int val) {
  node *temp = new node(val,nullptr);
  if (tail==nullptr) {
    head = tail = temp;
  } else {
    tail->set_link(temp);
    tail = tail->link();
  }
}

// MILESTONE 1: implement list_insert_sorted
