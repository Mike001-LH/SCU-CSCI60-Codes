// A templatized node class and a linked lists toolkit
// Sara Krehbiel, 11/17/25

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
    node<T> *link_; 
};

// linked list toolkit functions

// pre: curr points to first node of a linked list
// post: in-order list data have been output and list is unchanged
template <typename T>
ostream& operator <<(ostream& o, const node<T>* curr) {
    /*
    for ( ; curr!=nullptr; curr = curr->link()) {
        o << curr->data() << " "; // note: T should have << overloaded
    }
    return o;
    */

    /*
    if (curr==nullptr) return o; // base case
    o << curr->data() << " "; // a bit of non-recursive work
    o << curr->link(); // a recursive call to do the rest of the work
    return o; // return modified ostream object 
    */

    if (curr==nullptr) return o;
    return o << curr->data() << " " << curr->link();
}

// pre: h and t point to first and last node of a linked list
// post: t is the same, h points to a newly constructed first node
template <typename T>
void list_insert_head(node<T> *& h, node<T> *& t, const T& val) {
    h = new node<T>(val,h); // point head to a new node that points to old head
    if (t==nullptr) t = h; // update t if if list was previously empty
}

// pre: h and t point to first and last node of a linked list
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

// pre: h and t point to first and last node of a linked list
// post: the list is unchanged, the #nodes in list is returned
template <typename T>
size_t list_size(const node<T>* h, const node<T>* t) {
    if (h==nullptr) return 0; // done when the remaining list to count is empty
    return 1 + list_size(h->link(),t); // 1 for current node + size of the rest
}

// pre: h and t point to first and last node of a linked list
// post: the list is unchanged, return true iff val is in the list
template <typename T>
bool list_search(const node<T>* h, const node<T>* t, const T& val){
    if (h==nullptr) return false; // val can't be present in an empty list
    if (h->data()==val) return true; // stop if the current node's data is val
    return list_search(h->link(),t,val); // check the rest of the list otherwise
}

// pre: h and t point to first and last node of a linked list 
// post: return the number of times val occurs in (unchanged list)
template <typename T>
size_t list_count(const node<T>* h, const node<T>* t, const T& val) {
    if (h==nullptr) return 0;
    return (h->data()==val?1:0) + list_count(h->link(),t,val);
}

// pre: h and t point to first and last node of a linked list
// post: return true iff val is present, removed first instance if so
template <typename T>
bool list_remove_one(node<T>*& h, node<T>*& t, const T& val) {
    node<T> *curr = h, *prev = nullptr;
    while (curr!=nullptr) {
        if (curr->data()==val) {
            if (prev==nullptr) h = h->link(); // update head if removing first
            else prev->set_link(curr->link());
            if (curr==t) t = prev; // update head if removing last node
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->link();
    }
    return false;
}

// pre: h and t point to first and last node of a linked list
// post: return true iff val is present, removed first instance if so
template <typename T>
size_t list_remove_all(node<T>*& h, node<T>*& t, const T& val) {
    size_t count = 0;
    node<T> *curr = h, *prev = nullptr;
    while (curr!=nullptr) {
        if (curr->data()==val) {
            // delete current node and rewire appropriately
            if (prev==nullptr) h = h->link();
            else prev->set_link(curr->link());
            if (curr==t) t = prev;
            delete curr;
            curr = prev; // REWIND BEFORE SETTING UP FOR NEXT LOOP
            count++;
        }
        prev = curr; 
        if (curr == nullptr) curr = h; // JUST DELETED HEAD
        else curr = curr->link();
    }
    return count;
}

// pre: lhead and ltail are nullptr, rhead points to first node of a linked list
// post: lhead and ltail address first and last nodes in deep copy of rhead list
template <typename T>
void list_copy(node<T>*& lhead, node<T>*& ltail, const node<T>* rhead);

// pre: h and t point to first and last node of a linked list
// post: all nodes in list are deallocated, and h and t are set to nullptr
template <typename T>
size_t list_clear(node<T>*& h, node<T>*& t);


#endif // NODE_H
