// Starter iterator interface file for CSCI 60 Homework 9; due Thursday 12/4/25
// 
// This P_iterator class is designed to work with your other Parity files.
// All required and extra credit iterator member functions are declared below; 
// you should implement at least the required ones in p_iterator.cpp
// for the fourth and final milestone of this last programming assignment.

#ifndef P_ITERATOR_H
#define P_ITERATOR_H

#include "node.h"

class P_iterator {
public:
	// required constructor and three overloaded operator declarations

	// pre: none
	// post: iterator points to first even and first odd node of a parity object
	P_iterator(node* curr_e = nullptr, node* curr_o = nullptr);

	// pre: iterator points to next even and next odd node of a parity object;
	//      you may assume * is not called when both pointers are null
	// post: iterator returns the smaller of the two values
	int operator *() const;

	// pre: calling object and rhs are well-formed iterators
	// post: return false if iterators address the same nodes, true otherwise
	bool operator !=(const P_iterator& rhs) const;

	// pre: calling object is a well-formed iterator; 
	//      you may assume ++ is not called when both pointers are null
	// post: calling object is updated to have moved past the next element
	P_iterator& operator ++();

	// extra credit operator overload declarations

	// pre: calling object is a well-formed iterator with a next element 
	// post: calling object is updated to have moved past the next element,
	//       and a copy of the previous state of the iterator is returned
	P_iterator operator ++(int); 

	// pre: calling object and rhs are well-formed iterators
	// post: return true if iterators address the same nodes, false otherwise
	bool operator ==(const P_iterator& rhs) const;

	// pre: calling object and rhs are well-formed iterators
	// post: return true if operands point to nodes in the same parity object 
	//       AND the calling object's next node comes before rhs's next node;
	//       return false otherwise
	bool operator <(const P_iterator& rhs) const;

	// pre: calling object and rhs are well-formed iterators
	// post: return true if operands point to nodes in the same parity object 
	//       AND the calling object's next node after before rhs's next node;
	//       return false otherwise
	bool operator >(const P_iterator& rhs) const;

private:
	node * curr_e;
	node * curr_o;
	// INVARIANTS: curr_e and curr_o always address one node in the evens list
	//             and one in the odds list of a parity object; 
	//             the values of the nodes should be adjacent in the combined
	//             sorted list, i.e., given lists 0,2,4,6 and 3,5,7, there
	//             should never be an iterator with curr_e pointing to 2 and 
	//             curr_o pointing to 5 -- a constructor could make this happen, 
	//             but parity's begin and end followed by any sequence of member
	//             function calls would not.
};

#endif