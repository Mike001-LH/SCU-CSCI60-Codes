// A simple class (defined inline) for node and a linked lists toolkit
// Sara Krehbiel, 11/10/25-11/12/25

#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::ostream;

template <typename T>
class node {
public:
    // constructor(s)
    node(const T& d = T(), node<T>* l = nullptr): data_(d), link_(l){}

    // accessors
    T data() const { return data_; }
    node<T>* link() const { return link_; }

    // mutators
    void set_data(const T& val) { data_ = val; }
    void set_link(node<T>* new_link) { link_ = new_link; }

private:
    T data_;
    node<T> *link_; // link is the ADDRESS of the next node
};

// linked list toolkit functions

// pre: n points to first node of a linked list
// post: in-order list data have been output and list is unchanged
template <typename T>
ostream& operator <<(ostream& o, const node<T>* curr) {
    for ( ; curr!=nullptr; curr = curr->link()) {
        o << curr->data() << " "; // note: T should have << overloaded
    }
    return o;

}

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: t is the same, h points to a newly constructed first node
template <typename T>
void list_insert_head(node<T> *& h, node<T> *& t, const T& val) {
    h = new node<T>(val,h); // point head to a new node that points to old head
    if (t==nullptr) t = h; // update t if if list was previously empty
}

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: h is the same, t points to a newly constructed last node
template <typename T>
void list_insert_tail(node<T> *& h, node<T> *& t, const T& val) {
    if (t==nullptr) { // check if this is the first node being inserted
        h = t = new node<T>(val,nullptr); // new node is both the head and tail
    } else { // t points to an existing node in the usual case
        t->set_link(new node<T>(val,nullptr)); // point old last node to new one
        t = t->link(); // increment the tail pointer
    }

}

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: the list is unchanged, the #nodes in list is returned
template <typename T>
size_t list_size(const node<T>* h, const node<T>* t) {
    size_t count = 0;
    node<T> *curr = h;
    while (curr!=nullptr) {
        count++;
        curr = curr->link();
    }
    return count;
}

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: the list is unchanged, return true iff val is in the list
template <typename T>
bool list_search(const node<T>* h, const node<T>* t, const T& val){
    for ( ; h!=nullptr; h=h->link()) {
        if (h->data()==val) return true; // == must be overloaded for T
    }
    return false;
}

#endif // NODE_H
