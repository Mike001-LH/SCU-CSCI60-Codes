// Parity implementation starter file for CSCI 60 Homework 9; due Thursday 12/4/25
// List any collaborators and write your name here

#include "parity.h" // Don't add any additional libraries/namespaces!
using namespace std;

// MILESTONE 1: implement insert
//note: there are two node lists in Parity: the even list and the odd list
void Parity::insert(int val) {
	// insert val in appropriate list in sorted order, first we need to check if it's even or odd
	if (val % 2 == 0) {//even
		list_insert_sorted(h_e, t_e, val);
		n_e++;
	}
	else {//odd
		list_insert_sorted(h_o, t_o, val);
		n_o++;
	}
}

// MILESTONE 2: overload <<, and implement min and max
ostream& operator <<(ostream& out, const Parity& lists) {
	// print lists
	out << "Evens: ";
	node* curr_e = lists.h_e;
	while (curr_e != nullptr) {
		out << curr_e->data() << ", ";
		curr_e = curr_e->link();
	}
	out << endl;
	out << "Odds: ";
	node* curr_o = lists.h_o;
	while (curr_o != nullptr) {
		out << curr_o->data() << ", ";
		curr_o = curr_o->link();
	}
	out << endl;
	return out;
}

int Parity::min() const {
	//since the linked list is sorted, the minimum value is at the head of either list
	//first consider the case where both lists are empty
	if (h_e == nullptr && h_o == nullptr) {
		return INT_MAX;
	}
	//if only one list is empty, return the head of the other list
	if (h_e == nullptr) { return h_o->data(); }
	if (h_o == nullptr) { return h_e->data(); }
	//if both lists are non-empty, return the smaller one of the two heads
	return (h_e->data() < h_o->data()) ? h_e->data() : h_o->data();
}

int Parity::max() const {
	if (t_e == nullptr && t_o == nullptr) {
		return INT_MIN;
	}

	if (t_e == nullptr) { return t_o->data(); }
	if (t_o == nullptr) { return t_e->data(); }

	return (t_e->data() > t_o->data()) ? t_e->data() : t_o->data();
}

// MILESTONE 3: implement a destructor and copy constructor, and overload =
Parity::~Parity() {
	// free memory
	list_clear(h_e, t_e);
	list_clear(h_o, t_o);
	n_e = 0;
	n_o = 0;
}

Parity::Parity(const Parity& other) : h_e(nullptr), t_e(nullptr), h_o(nullptr), t_o(nullptr), n_e(0), n_o(0) {
	// copy constructor
	//when we use copy constructor, first initialize the member variables to default values to prevent garbage values

	//now, deep copy the other object's lists
	node* current = other.h_e;
	while (current != nullptr) {
		list_insert_tail(h_e, t_e, current->data());
		current = current->link();
		n_e++;
	}
	current = other.h_o;
	while (current != nullptr) {
		list_insert_tail(h_o, t_o, current->data());
		current = current->link();
		n_o++;
	}
}

Parity& Parity::operator =(const Parity& other) {
	// assignment operator
	//first, check for self-assignment
	if (this == &other) { return *this; }
	//then, free existing memory
	list_clear(h_e, t_e);
	list_clear(h_o, t_o);
	n_e = 0;
	n_o = 0;
	//now, deep copy the other object's lists
	node* current = other.h_e;
	while (current != nullptr) {
		list_insert_tail(h_e, t_e, current->data());
		current = current->link();
		n_e++;
	}
	current = other.h_o;
	while (current != nullptr) {
		list_insert_tail(h_o, t_o, current->data());
		current = current->link();
		n_o++;
	}
	//return the calling object
	return *this;//*this是返回当前对象的引用
}

// MILESTONE 4: implement begin and end
//the iterator has 2 pointers, one pointing to the even list, the other pointing to the odd list
//first write a begin function that is a Parity member and a 2-argument constructor in the P_iterator class
//that begin calls to initialize the iterator member variables to point to the head of the two lists associated with the corresponding parity object.
P_iterator Parity::begin() const {
	return P_iterator(h_e, h_o);// return iterator pointing to start of both lists
}

P_iterator Parity::end() const {
	return P_iterator(nullptr, nullptr);// return iterator with nullptrs
}

