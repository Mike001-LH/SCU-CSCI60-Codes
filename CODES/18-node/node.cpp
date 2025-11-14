// Implementations of linked list functionality declared in node.h
// Sara Krehbiel, 11/10/25

#include "node.h"

void list_insert_head(node *& h, node *& t, int val) {
	h = new node(val,h); // point head to a new node that points to old head
	if (t==nullptr) t = h; // update t if if list was previously empty
}

void list_insert_tail(node *& h, node *& t, int val) {
	if (t==nullptr) { // check if this is the first node being inserted
		h = t = new node(val,nullptr); // the new node is both the head and tail
	} else { // t points to an existing node in the usual case
		t->set_link(new node(val,nullptr)); // point old last node to a new one
		t = t->link(); // increment the tail pointer
	}
}

ostream& operator <<(ostream& o, const node* curr) {
	//curr->set_data(1000); // illegal for const node* curr
	for ( ; curr!=nullptr; curr = curr->link()) {
    	o << curr->data() << " ";
	}
	return o;
}
