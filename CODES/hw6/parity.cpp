// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/29/25
// List any collaborators and write your name here

#include "parity.h" // Do NOT add any additional libraries/namespaces!
//milestone 0: Write stub functions for insert, odd, and the 2-argument constructor in the implementation file
//milestone 1: Implement and test the insert member function.
void Parity::insert(int val) {
	// it should check whether its parameter val is even or odd
	bool isEven = (val % 2 == 0);
	// then  add it to the end of the corresponding dynamic array associated with the object.
	//However, if that array is at its current capacity, insert should create a new array with CAP more elements than before and then insert the new value,
	if (isEven) {
		// check if evens array is at capacity
		if (nEven_ % CAP == 0) {//nEven_ is 0 at the beginning, CAP=5, so 0%CAP==0, we need to expand the array
			//we create a new dynamic array with CAP more elements than before called tempEvens, where(nEven_ + CAP)=0+5=5
			int* tempEvens = new int[nEven_ + CAP];
			//copy the existing elements from the old array to the new array,
			for (size_t i = 0; i < nEven_; i++) {
				tempEvens[i] = evens_[i];
			}
			// clean up old array and make tempEvens point to evens_, so we can get a new evens_ array that includes val
			delete[] evens_;
			evens_ = tempEvens;
		}
		//then add the new value to the end of the new array and increase nEven_ by 1.
		evens_[nEven_++] = val;
	}
	else {
		// check if odds array is at capacity
		if (nOdd_ % CAP == 0) {//nOdd_ is 0 at the beginning, CAP=5, so 0%CAP==0, we need to expand the array
			// we create a new dynamic array with CAP more elements than before called tempOdds, where(nOdd_ + CAP)=0+5=5
			int* tempOdds = new int[nOdd_ + CAP];
			//copy the existing elements from the old array to the new array,
			for (size_t i = 0; i < nOdd_; i++) {
				tempOdds[i] = odds_[i];
			}
			// clean up old array and make tempOdds point to odds_, so we can get a new odds_ array that includes val
			delete[] odds_;
			odds_ = tempOdds;
		}
		//then add the new value to the end of the new array and increase nOdd_ by 1.
		odds_[nOdd_++] = val;
	}
}



//Milestone 3: Implement and test your 2-argument constructor. //用来初始化Parity对象，传入一个数组和它的大小，将偶数和奇数分别存储在evens_和odds_数组中
//The 2-argument constructor should take in an array and its size,
///int arr[] = { 3,5,-1,2,6,8,10,7,-2,11,15 };
///Parity lists(arr, 11);
//and it should initialize a Parity object consistent with one that resulted from a sequence of calls to insert, passing in the values inside the array in order.
//Note that you may use your insert function to do this so you don’t have to rethink all the same logic! Although it has

//Before the 2-argument constructor is called, the 0-argument constructor has already been called first! Therefore, nEven_, nOdd_, evens_, and odds_ have already been initialized to 0 and nullptr.
//So in the 2-argument constructor, we only need to call the insert function to insert each element in the array.
//Thus when my 2-argument constructor start to get executed, nEven_ and nOdd_ are both 0, evens_ and odds_ are both nullptr.
Parity::Parity(int* a, size_t n) {//a is the pointer to the array, n is the size of the array
	//loop through each element in array a of size n
	for (int i = 0; i < n; i++) {
		insert(a[i]);//use insert function to insert each element into the Parity object
	}
}
//for example, after executing the following code:
///int arr[] = { 3,5,-1,2,6,8,10,7,-2,11,15 };
///Parity lists(arr, 11);
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
		return 0; //if both arrays are empty, return 0//error case
	}
	//then, find the minimum value among both arrays
	int minVal = INT_MAX;//INT_MAX was defined in <climits> as the maximum value for an int type //initialize minVal to the maximum possible int value
	//loop through all elements in evens_ and odds_ arrays to find the minimum value
	for (int i = 0; i < nEven_; i++) {
		if (evens_[i] < minVal) {
			minVal = evens_[i];
		}
	}
	for (int i = 0; i < nOdd_; i++) {
		if (odds_[i] < minVal) {
			minVal = odds_[i];
		}
	}
	return minVal;
}

int Parity::max() const {
	//first, check if the arrays are empty
	if (nEven_ == 0 && nOdd_ == 0) {
		return 0; //if both arrays are empty, return 0//error case
	}
	//then, find the maximum value among both arrays
	int maxVal = INT_MIN;//INT_MIN was defined in <climits> as the minimum value for an int type //initialize maxVal to the minimum possible int value
	//loop through all elements in evens_ and odds_ arrays to find the maximum value
	for (int i = 0; i < nEven_; i++) {
		if(evens_[i]>maxVal){
			maxVal=evens_[i];
		}
	}
	for (int i = 0; i < nOdd_; i++) {
		if(odds_[i]>maxVal){
			maxVal=odds_[i];
		}
	}
	return maxVal;
}

// Milestone 2: Implement and test your insertion operator overload.
ostream& operator <<(ostream& out, const Parity& p) {
	//output the even numbers first that start with "E: "
	out << "E: ";
	for (size_t i = 0; i < p.nEven_; i++) { // output array contents//p.nEven_ is the number of even elements in the Parity object p
		out << p.evens_[i] << " ";//p.evens_ is the pointer to the dynamic array of even elements in the Parity object p
	}
	out << endl;
	//output the odd numbers next that start with "O: "
	out << "O: ";
	for (size_t i = 0; i < p.nOdd_; i++) { // output array contents //p.nOdd_ is the number of odd elements in the Parity object p
		out << p.odds_[i] << " ";//p.odds_ is the pointer to the dynamic array of odd elements in the Parity object p
	}
	out << endl;
	return out; // return modified ostream that was passed in, to allow chaining
	/* for example,
	   after inserting a sequence of numbers 3 5 -1 2 6 8 10 7 -2 11 15 into a Parity object called
	   lists, the command cout << lists; in main.cpp would output the following:
	   E: 2 6 8 10 -2
	   O: 3 5 -1 7 11 15
	*/
}

// memory management functions for HW6
//copy constructor
/*for example, if we have the following code:
Parity p1;
p1.insert(3);  // p1.odds_ = [3], p1.nOdd_ = 1
p1.insert(2);  // p1.evens_ = [2], p1.nEven_ = 1

Parity p2(p1);  // <- Call the copy constructor
*/
Parity::Parity(const Parity& rhs) {
	//copy counters
	nEven_ = rhs.nEven_;// p2的nEven_ = p1的nEven_ = 1
	nOdd_ = rhs.nOdd_;// p2的nOdd_ = p1的nOdd_ = 1

	//allocate new memory for evens_ and odds_ arrays
	evens_ = new int[nEven_ + CAP];// p2分配新的evens_数组（大小6）,因为CAP=5而且nEven_=1
	odds_ = new int[nOdd_ + CAP];// p2分配新的odds_数组（大小6）,因为CAP=5而且nOdd_=1

	//deep copy elements from rhs to this object(lhs)//or be specific, from p1 to p2
	for (size_t i = 0; i < nEven_; i++) {
		evens_[i] = rhs.evens_[i];// p2.evens_[0] = p1.evens_[0] = 2//copy even elements from p1 to p2
	}
	for (size_t i = 0; i < nOdd_; i++) {
		odds_[i] = rhs.odds_[i];// p2.odds_[0] = p1.odds_[0] = 3//copy odd elements from p1 to p2
	}
}
//destructor
Parity::~Parity() {//构造器和析构函数之所以都要用scope resolution运算符，是因为它们是类的成员函数，只有这样才能对类的私有成员进行操作
	delete[] evens_;
	delete[] odds_;
}
//这里是一般来说一个destructor的语法：
// ClassName::~ClassName() {
//    // cleanup code here //e.g., delete dynamically allocated memory
//    delete[] evens_;
//    delete[] odds_;
//	  //一般来说，destructor不需要返回值，所以没有return语句//此外，destructor不需要将指针设为nullptr，因为对象即将被销毁，内存会被释放
// }

//assignment operator //for example: p1 = p2// assign p2 to p1, where p1 is the lhs object, p2 is the rhs object
Parity& operator =(const Parity& rhs) {//we pass in a reference to the right-hand side object, rhs, which is p2 in this case, but due to const, we cannot modify p2 inside this function
	if (this == &rhs) {//here, this is p1, rhs is p2, if p1 and p2 are the same object, do nothing
		return *this;//return a address of the left-hand side object, which is p1 in this case//
	} 
	//clean up the old memory
	delete[] evens_;
	delete[] odds_;

	//copy counters,
	nEven_ = rhs.nEven_;//the number of even numbers in p1 equal to p2
	nOdd_ = rhs.nOdd_;//the number of odd numbers in p1 equal to p2

	//Allocate new memory for evens_ and odds_ arrays
	evens_ = new int[nEven_ + CAP];//allocate new memory for evens_
	odds_ = new int[nOdd_ + CAP];//allocate new memory for odds_

	//deep copy elements from rhs to this object(lhs)
	for (size_t i = 0; i < nEven_; i++) {
		evens_[i] = rhs.evens_[i];//copy even elements from rhs to lhs//e.g., p1.evens_[i] = p2.evens_[i]
	}
	for (size_t i = 0; i < nOdd_; i++) {
		odds_[i] = rhs.odds_[i];//copy odd elements from rhs to lhs//e.g., p1.odds_[i] = p2.odds_[i]
	}

	return *this;//return the address of the left-hand side object after assignment// return the address of p1, this helps to allow chained assignments like p1 = p2 = p3;
}