// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/29/25
// List any collaborators and write your name here

#include "parity.h" // Do NOT add any additional libraries/namespaces!
//milestone 0: Write stub functions for insert, odd, and the 2-argument constructor in the implementation file
//milestone 1: Implement and test the insert member function.

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
		evens_[nEven_] = val;
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
			// clean up old array and make tempOdds point to odds_, so we can get a new odds_ array that includes val
			delete[] odds_;
			odds_ = tempOdds;
		}
		odds_[nOdd_] = val;
		nOdd_++;
	}
}



//Milestone 3: Implement and test your 2-argument constructor. //用来初始化Parity对象，传入一个数组和它的大小，将偶数和奇数分别存储在evens_和odds_数组中
//The 2-argument constructor should take in an array and its size,
////int arr[] = { 3,5,-1,2,6,8,10,7,-2,11,15 };
////Parity lists(arr, 11);
//and it should initialize a Parity object consistent with one that resulted from a sequence of calls to insert, passing in the values inside the array in order.
//Note that you may use your insert function to do this so you don’t have to rethink all the same logic! Although it has

Parity::Parity(int* a, size_t n) : Parity() {//use the 0-arg constructor to set the member to zero, this prevent trash value//a is the pointer to the array, n is the size of the array
	//loop through each element in array a of size n
	for (size_t i = 0; i < n; i++) {
		insert(a[i]);//use insert function to insert each element into the Parity object
	}
}
//for example, after executing the following code:
////int arr[] = { 3,5,-1,2,6,8,10,7,-2,11,15 };
////Parity lists(arr, 11);
//the Parity object lists should contain the even numbers 2, 6, 8, 10, -2 in its evens_ array and the odd numbers 3, 5, -1, 7, 11, 15 in its odds_ array.

//Milestone 4: Implement accessor functions. 
// The boolean function odd should return true if the sum of all values in both arrays is odd and false if the sum is even.
bool Parity::odd() const {
	//since the sum in the even array will be even, the sum in the odd array will be odd if there are odd number of values, be even if there are even number of values
	//So we just need to check whether nOdd_ is odd or even, this is because nOdd_ is the number of odd values in the odds_ array.

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

// Milestone 2: Implement and test your insertion operator overload.
ostream& operator <<(ostream& out, const Parity& p) {
	//output the even numbers
	out << "E: ";
	if (p.nEven_ > 0) {
		//create a visited array to track which even numbers have been output, I will use bool array
		bool* visited = new bool[p.nEven_];
		//initialize all elements in visited array to false, because now, no even numbers have been output
		for (size_t i = 0; i < p.nEven_; i++) {
			visited[i] = false;
		}

		//now, we have to output the even numbers in ascending order, to achieve this, I have to use 2 loops.
		//outer loop is used to output each even number, inner loop is used to find the smallest unvisited even number
		for (size_t i = 0; i < p.nEven_; i++) {
			int minIdx = -1;//index of the smallest unvisited even number
			int minVal = INT_MAX;//value of the smallest unvisited even number
			//inner loop to find the smallest unvisited even number
			for (size_t j = 0; j < p.nEven_; j++) {
				//now, compare each unvisited even number with minVal, make sure it is false in visited array, once we find a smaller unvisited even number, update minVal and minIdx
				if (!visited[j] && p.evens_[j] < minVal) {
					minVal = p.evens_[j];
					minIdx = j;
				}
			}
			//if we havn't found any unvisited even number, minIdx will be -1, this is almost impossible.
			//but just in case, I will check if minIdx is not -1, then we can output the even number at minIdx and mark it as visited
			if (minIdx != -1) {
				visited[minIdx] = true;
				out << p.evens_[minIdx];
				if (i < p.nEven_ - 1) out << " ";//if this is not the last even number, output a space after it to seperate it from the next even number
			}
		}
		delete[] visited;//we no longer need the visited array, free it's memory
	}
	out << endl;
	//output the odd numbers next that start with "O: "
	out << "O: ";
	if (p.nOdd_ > 0) {
		//create a visited array to track which odd numbers have been output, I will use bool array
		bool* visited = new bool[p.nOdd_];
		//initialize all elements in visited array to false, because now, no odd numbers have been output
		for (size_t i = 0; i < p.nOdd_; i++) {
			visited[i] = false;
		}

		//now, we have to output the odd numbers in ascending order, to achieve this, I have to use 2 loops.
		//outer loop is used to output each odd number, inner loop is used to find the smallest unvisited odd number
		for (size_t i = 0; i < p.nOdd_; i++) {
			int minIdx = -1;//index of the smallest unvisited odd number
			int minVal = INT_MAX;//value of the smallest unvisited odd number
			//inner loop to find the smallest unvisited odd number
			for (size_t j = 0; j < p.nOdd_; j++) {
				//now, compare each unvisited odd number with minVal, make sure it is false in visited array, once we find a smaller unvisited odd number, update minVal and minIdx
				if (!visited[j] && p.odds_[j] < minVal) {
					minVal = p.odds_[j];
					minIdx = j;
				}
			}
			//if we havn't found any unvisited odd number, minIdx will be -1, this is almost impossible.
			//but just in case, I will check if minIdx is not -1, then we can output the odd number at minIdx and mark it as visited
			if (minIdx != -1) {
				visited[minIdx] = true;
				out << p.odds_[minIdx];
				if (i < p.nOdd_ - 1) out << " ";//if this is not the last odd number, output a space after it to seperate it from the next odd number
			}
		}
		delete[] visited;//we no longer need the visited array, free it's memory
	}
	out << endl;
	return out; // return modified ostream that was passed in, to allow chaining
	//for example, cout << p1 << p2; //this is possible because we return out
}