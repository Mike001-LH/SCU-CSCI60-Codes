// Interface and implementation of iterator for templatized linked list
// Sara Krehbiel, 12/1/25

#ifndef L_ITERATOR_H
#define L_ITERATOR_H

#include "node.h"

template <typename T>
class L_iterator {
public:
	// constructor with default value
	L_iterator(node<T>* curr = nullptr) : curr(curr) {}

	// accessors: dereference and equality checking
	T operator *() const { return curr->data(); } // overloaded dereference
	bool operator !=(const L_iterator<T>& rhs) const { return curr!=rhs.curr; }
	bool operator ==(const L_iterator<T>& rhs) const { return curr==rhs.curr; }
	// range-based for loop doesn't need ==, but it's so easy, so just do it!

	// mutators: prefix and postfix increment operators
	L_iterator<T>& operator ++(); // prefix increment (++it)
	L_iterator<T> operator ++(int);// postfix increment (it++)
	// range-based for loop doesn't need postfix, and it's a step more complex
private:
	node<T> *curr; // address of next node in a list we're iterating through
};

// non-inline definitions here
template <typename T> 
L_iterator<T>& L_iterator<T>::operator ++() { // pre: increment then return
	curr = curr->link(); // update calling object
	return *this; // return a reference to the post-incremented calling object
}

template <typename T> 
L_iterator<T> L_iterator<T>::operator ++(int) { // post: "return" then increment
	node<T>* old_addr = curr; // copy pre-incremented address
	curr = curr->link(); // update calling object
	return L_iterator<T>(old_addr); // return (by value) iterator w/ old address
}

/*template <typename T>
L_iterator<T> L_iterator<T>::operator ++(int) { // alternate postfix definition
	L_iterator<T> old_it(*this); // new object copies pre-incremented iterator 
	curr = curr->link(); // update calling object
	return old_it; // return (by value) the copy of the pre-incremented object
}*/

#endif
