// Iterator implementation file for CSCI 60 Homework 9; due Thursday 12/4/25
// List any collaborators and write your name here

#include "p_iterator.h"

// MILESTONE 4: Implement your P_iterator member functions here
P_iterator::P_iterator(node* e, node* o) : curr_e(e), curr_o(o) {}


bool P_iterator::operator !=(const P_iterator& rhs) const {
	//Note two iterators are the same only if they are pointing to the exact same locations in the same objects.
	//return false if iterators address the same nodes, true otherwise
	return !(curr_e == rhs.curr_e && curr_o == rhs.curr_o);
}

int P_iterator::operator*() const {//The dereference operator * overloaded for P iterator. which returns the smaller of the two values pointed to by curr_e and curr_o.
	//if one of the pointers is null, return the other one
	if(curr_e == nullptr) {
		return curr_o->data();
	}
	if(curr_o == nullptr) {
		return curr_e->data();
	}
	//if both pointers are not null, return the smaller one
	return (curr_e->data() < curr_o->data()) ? curr_e->data() : curr_o->data();//compare and return the smaller one
}

P_iterator& P_iterator::operator ++() {//calling object is updated to have moved past the next element//it is used to move the iterator to the next element
	//we need to determine where is the next element
	//if the number pointed by curr_e is smaller, move curr_e to the next node
	if (curr_e != nullptr && (curr_o == nullptr || curr_e->data() < curr_o->data())) {
		curr_e = curr_e->link();
	}
	else if(curr_o != nullptr) {//if the number pointed by curr_o is smaller, move curr_o to the next node
		curr_o = curr_o->link();
	}
	return *this; //return the updated iterator
}

//extra credit
// post: calling object is updated to have moved past the next element,
//       and a copy of the previous state of the iterator is returned
P_iterator P_iterator::operator ++(int){
	P_iterator temp = *this;
	++(*this);//using the pre-increment operator ++
	return temp;
}

//return true if iterators address the same nodes, false otherwise
bool P_iterator::operator ==(const P_iterator& rhs) const {
	return (curr_e == rhs.curr_e && curr_o == rhs.curr_o);
}

// post: return true if operands point to nodes in the same parity object 
//       AND the calling object's next node after before rhs's next node;
//       return false otherwise
bool P_iterator::operator <(const P_iterator& rhs) const {//used to compare the values of two iterators that are pointing to satisfying the lhs is less than rhs
	return *(*this) < *(rhs);//*(*this); first * dereference this pointer to get a P_iterator object, then the second * calls the overloaded dereference operator to get the value
}

bool P_iterator::operator >(const P_iterator& rhs) const {
	return this->operator*() > rhs.operator*();//here, we use the dereference operator to get the values and compare them
}