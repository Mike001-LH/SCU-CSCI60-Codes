// A simple class (defined inline) for node: the building block of linked lists
// Sara Krehbiel, 11/10/25

#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::ostream;

class node {
public:
    // constructors
    node(): data_(0), link_(nullptr){}
    node (int initdata, node *initlink) : data_(initdata), link_(initlink) {}

    // accessors
    int data() const { return data_; }
    node* link() const { return link_; }

    // mutators
    void set_data(int val) { data_ = val; }
    void set_link(node* new_link) { link_ = new_link; }

private:
    int data_;
    node *link_; // link is the ADDRESS of the next node
};

// declarations of linked list toolkit functions

ostream& operator <<(ostream& o, const node* n);

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: t is the same, h points to a newly constructed first node
void list_insert_head(node *& h, node *& t, int val);

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: h is the same, t points to a newly constructed last node
void list_insert_tail(node *& h, node *& t, int val);

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: the list is unchanged, the #nodes in list is returned
size_t list_size(const node* h, const node* t);

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: the list is unchanged, return true iff val is in the list
bool list_search(const node* h, const node* t, int val);


#endif // NODE_H
