// This is a test file used while developing a linked list toolkit.
// Sara Krehbiel, 11/10/25-11/12/25

#include <iostream>
#include "node.h" 
using namespace std;


void oldNodeCode();
void newNodeCode();
//void printList(node* head);
//void printListRec(node* head);
void wedTestCode();

int main() {
  //oldNodeCode();
  //newNodeCode();
  wedTestCode();
	return 0;
}

void wedTestCode() {
  node<string> *h = nullptr, *t = nullptr;
  string str1 = "hello";
  string str2 = "hello";
  list_insert_head(h,t,str1);
  list_insert_head(h,t,str2);
  cout << h << endl;

}

// untemplatized code no longer matches the node class
/*
void newNodeCode() {
  // week 7 functionality using list_insert_head, list_insert_tail, and << 
  node *head = nullptr, *tail = nullptr;
  list_insert_head(head,tail,2);
  list_insert_head(head,tail,4);
  list_insert_head(head,tail,6);

  //printList(head);

  node *h = nullptr, *t = nullptr;
  list_insert_tail(h,t,6);
  list_insert_tail(h,t,4);
  list_insert_tail(h,t,2);
  list_insert_tail(h,t,0);
  list_insert_tail(h,t,-2);

  cout << h << endl;

  // WEDNESDAY TODO: 
  //   1. implement and test list_size and list_search
  //   2. reimplement << recursively  
  //   3. reimplement list_size and list_search recursively
  //   4. discuss memory issues

  delete head; // what does this do?

}

// Week 7 code with new syntax and common strategies for linked lists
void oldNodeCode() {
  // build a list 6->4->2 from the back to the front
	node *head = new node(2,nullptr); // head points to a single node with data 2
  node *tail = head; // head and tail are the same for a 1-elem list
  head = new node(4,head); // NOTE: rhs is evaluated first, assigned second
  head = new node(6,head);

  // build a list 6->4->2 from front to back
  node *h = new node(6,nullptr), *t = h;

  // first explore with new syntax and different ways to order commands:

  // update tail to point to new node, then find old tail and relink it
  t = new node(4,nullptr); // set tail to point to the next node
  // NEW SYNTAX: ptr->fn() dereferences and applies dot operator in one step
  //             (*ptr).fn() is what we'd have to do without ->
  h->set_link(t); // same as (*h).set_link(t) -- update first node link to next

  // do this again for the third node
  t = new node(2,nullptr); 
  // NOW: have to find the old tail to link it to the new tail
  h->link()->set_link(t);//same as (*(*h).link()).set_link(t); YUCK!

  // how does this look if we keep going to add a fourth node?
  t = new node(0,nullptr);
  h->link()->link()->set_link(t); // traverse multiple nodes to find old tail

  // OR use a temp variable so we can remember old tail in order to relink it
  node *newTail = new node(-2,nullptr); // 1. construct new node
  t->set_link(newTail); // 2. link old tail node to it
  t = newTail; // 3. update t pointer to point to new last node

  // settle on clean code: avoids extra variables and traversing multiple nodes

  // link the old tail to a new node, then update t to point to the new one
  t->set_link(new node(-4,nullptr)); // 1. make new node, 2. relink old tail node
  t = t->link(); // 3. update t pointer to point to new last node

  // do it again!
  t->set_link(new node(-6,nullptr)); 
  t = t->link(); 

  cout << "The contents of the first list, printed multiple ways:\n";
  cout << "With explicit main code: ";
  // use accessors to get the three pieces of data starting with the head
  cout << head->data() << " "; // data of first node (addressed by head)
  cout << head->link()->data() << " "; // data of second node 
  cout << head->link()->link()->data() << endl; // OR use tail->data() 

  cout << "With a printList function: ";
  printList(head); // iterative implementation (while loop or for loop)

  cout << "Now recursively! ";
  printListRec(head); // recursive implementation

  // TODO: learn about const pointers and add const wherever appropriate!

  // TODO: declare linked list toolkit functions in node.h, define in node.cpp

  cout << "NEXT: overload << for node*\n"; // TODO: overload << in node.cpp
  cout << head << endl; // TODO: implement with a loop, then recursively
}

// an iterative function that prints each piece of data (in order) in the list
void printList(node* curr) { // TODO: see what breaks if we declare node *const
  //curr->set_link(nullptr); // TODO: see how this breaks if we use const
  for ( ; curr!=nullptr; curr = curr->link()) {
    cout << curr->data() << " ";
  }
  cout << endl;
}

// a recursive function that prints each piece of data (in order) in the list
void printListRec(node* curr) {
  if (curr==nullptr) { // base case is the stopping condition for recursion
    cout << endl; // advance curser once list is printed and recursion stops
    return;
  }
  cout << curr->data() << " "; // one piece of work (on the way up the stack!)
  printListRec(curr->link()); // recursively print list starting from next node
}
*/