//HW6, 2025/11/1, by Rentian Dong (Mike)
#include "parity.h" // Do NOT add any additional libraries/namespaces!

void Parity::insert(int val) {
	bool isEven = (val % 2 == 0);//check if the value is even

	if (isEven) {
		// check if evens array is at capacity
		if (nEven_ % CAP == 0) {//nEven_ is 0 at the beginning, CAP=5, so 0%CAP==0, we need to expand the array
			//create a new dynamic array with CAP more elements (0+5=5)
			int* tempEvens = new int[nEven_ + CAP];

			//copy the existing elements from the old array to the new array,
			for (size_t i = 0; i < nEven_; i++) {
				tempEvens[i] = evens_[i];
			}
			// clean up old array and make tempEvens point to evens_, so we can get a new evens_ array that includes val
			delete[] evens_;
			evens_ = tempEvens;
		}

		// Find the correct position to insert val (maintain ascending order)
		size_t pos = 0;
		while (pos < nEven_ && evens_[pos] < val) { //for example: evens_ = {2,4,6}, val=5, 2 < 5 → pos = 1, 4 < 5 → pos = 2, 6 < 5 → false, stop loop, pos = 2
			pos++;
		}

		// Shift elements to the right
		for (size_t i = nEven_; i > pos; i--) {//从最右侧开始往右移，从右往左的元素逐个往右移
			evens_[i] = evens_[i - 1];
		}

		evens_[pos] = val;
		nEven_++;
	}
	else {
		// check if odds array is at capacity
		if (nOdd_ % CAP == 0) {//nOdd_ is 0 at the beginning, CAP=5, so 0%CAP==0, we need to expand the array
			//create a new dynamic array with CAP more elements (0+5=5)
			int* tempOdds = new int[nOdd_ + CAP];

			//copy the existing elements from the old array to the new array,
			for (size_t i = 0; i < nOdd_; i++) {
				tempOdds[i] = odds_[i];
			}

			delete[] odds_;
			odds_ = tempOdds;
		}

		// Find the correct position to insert val (maintain ascending order)
		size_t pos = 0;
		while (pos < nOdd_ && odds_[pos] < val) { //for example: odds_ = {3,5,7}, val=6, 3 < 6 → pos = 1, 5 < 6 → pos = 2, 7 < 6 → false, stop loop, pos = 2
			pos++;
		}

		// Shift elements to the right
		for (size_t i = nOdd_; i > pos; i--) {//从最右侧开始往右移，从右往左的元素逐个往右移
			odds_[i] = odds_[i - 1];
		}

		odds_[pos] = val;
		nOdd_++;
	}
}

// function to remove every occurrence of a particular value, returning the number of entries removed. 
size_t Parity::remove(int val) {
	size_t count = 0;
	bool isEven = (val % 2 == 0);
	if (isEven) {
		for (size_t i = 0; i < nEven_; i++) {
			if(evens_[i]==val){
				//shift elements to the left
				for(size_t j=i; j<nEven_-1; j++){
					evens_[j]=evens_[j+1];
				}
				nEven_--;
				count++;
				i--;//decrease i by 1 to check the new element at index i after shifting
						}
		}
	}
	else {
		for (size_t i = 0; i < nOdd_; i++) {
			if(odds_[i]==val){
				//shift elements to the left
				for(size_t j=i; j<nOdd_-1; j++){
					odds_[j]=odds_[j+1];
				}
				nOdd_--;
				count++;
				i--;//decrease i by 1 to check the new element at index i after shifting
			}
		}
	}
	return count;
}

Parity::Parity(int* a, size_t n) : Parity() {//use the 0-arg constructor to set the member to zero, this prevent trash value//a is the pointer to the array, n is the size of the array
	//loop through each element in array a of size n
	for (size_t i = 0; i < n; i++) {
		insert(a[i]);//use insert function to insert each element into the Parity object
	}
}

// Copy constructor
Parity::Parity(const Parity& rhs) : nEven_(rhs.nEven_), nOdd_(rhs.nOdd_) {
	// Allocate new arrays for evens_ and odds_
	evens_ = new int[nEven_];
	odds_ = new int[nOdd_];

	// Copy the elements from the rhs arrays
	for (size_t i = 0; i < nEven_; i++) {
		evens_[i] = rhs.evens_[i];
	}
	for (size_t i = 0; i < nOdd_; i++) {
		odds_[i] = rhs.odds_[i];
	}
}

// Destructor
Parity::~Parity() {
	delete[] evens_;
	delete[] odds_;
}

Parity& Parity::operator=(const Parity& rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete[] evens_;
	delete[] odds_;
	evens_ = new int[rhs.nEven_];
	odds_ = new int[rhs.nOdd_];
	nEven_ = rhs.nEven_;
	nOdd_ = rhs.nOdd_;
	for (size_t i = 0; i < nEven_; i++) {
		evens_[i] = rhs.evens_[i];
	}
	for (size_t i = 0; i < nOdd_; i++) {
		odds_[i] = rhs.odds_[i];
	}
}

bool Parity::odd() const {
	return (nOdd_ % 2 == 1);//return true if the sum of all values in both arrays is odd and false if the sum is even by checking the number of nOdd_
}

int Parity::min() const {
	//first, check if the arrays are empty
	if (nEven_ == 0 && nOdd_ == 0) {
		return INT_MAX; //if both arrays are empty, return INT_MAX;//error case, we don't use 0 here because 0 might be a valid minimum value in the arrays
	}
	//then, find the minimum value among both arrays
	int minVal = INT_MAX;//INT_MAX was defined in <climits> as the maximum value for an int type //initialize minVal to the maximum possible int value
	//loop through all elements in evens_ and odds_ arrays to find the minimum value
	for (size_t i = 0; i < nEven_; i++) {
		if (evens_[i] < minVal) {
			minVal = evens_[i];
		}
	}
	for (size_t i = 0; i < nOdd_; i++) {
		if (odds_[i] < minVal) {
			minVal = odds_[i];
		}
	}
	return minVal;
}

int Parity::max() const {
	//first, check if the arrays are empty
	if (nEven_ == 0 && nOdd_ == 0) {
		return INT_MIN; //if both arrays are empty, return INT_MIN;//error case, we don't use 0 here because 0 might be a valid maximum value in the arrays
	}
	//then, find the maximum value among both arrays
	int maxVal = INT_MIN;//INT_MIN was defined in <climits> as the minimum value for an int type //initialize maxVal to the minimum possible int value
	//loop through all elements in evens_ and odds_ arrays to find the maximum value
	for (size_t i = 0; i < nEven_; i++) {
		if(evens_[i]>maxVal){
			maxVal=evens_[i];
		}
	}
	for (size_t i = 0; i < nOdd_; i++) {
		if(odds_[i]>maxVal){
			maxVal=odds_[i];
		}
	}
	return maxVal;
}

ostream& operator<<(ostream& out, const Parity& p) {
	// Evens in insertion order
	out << "E: ";
	for (size_t i = 0; i < p.nEven_; ++i) {
		out << p.evens_[i];
		if (i + 1 < p.nEven_) out << " ";
	}
	out << '\n';

	// Odds in insertion order
	out << "O: ";
	for (size_t i = 0; i < p.nOdd_; ++i) {
		out << p.odds_[i];
		if (i + 1 < p.nOdd_) out << " ";
	}
	out << '\n';

	return out;
}

