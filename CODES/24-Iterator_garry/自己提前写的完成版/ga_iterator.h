// Interface for GA_Iterator, an iterator for the GArray class
// Sara Krehbiel, 12/3/25

#ifndef GA_ITERATOR_H
#define GA_ITERATOR_H

class GA_Iterator {
public:
  // TODO #2A: implement constructor and overloaded !=, *, and ++ operators
	GA_Iterator(int* head, int* tail) : current_(head), end_(tail) {}
	bool operator !=(const GA_Iterator& other) const {
		return current_ != other.current_;
	}
	int operator *() const {
		return *current_;
	}
	GA_Iterator& operator ++() {
		++current_;
		return *this;
	}
private:
  // TODO #1: decide on private member variable(s) to keep track of GArray state
	int* current_;
	int* end_;
};

#endif