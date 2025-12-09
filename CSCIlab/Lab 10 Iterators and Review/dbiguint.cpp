#include "dbiguint.h"

//In the .cpp file, modify the two existing constructors from biguint so that they allocate memory for the dynamic array.

// Do the default constructor first
// default/0-arg constructor
//change biguint to dbiguint, make them dynamic arrays
dbiguint::dbiguint() {
	capacity_ = 1;//set capacity to 1, default value
	data_ = new unsigned short[capacity_];//create a dynamic array
	data_[0] = 0;
};
// 1-argument constructor
//write the constructor that takes in a string.
//convert the character ‘5’ to the number 5 by subtracting the character ‘0’ from it.//For example, ‘5’ - ‘0’ = 5.
dbiguint::dbiguint(const string &s) {
	//Remove the leading 0 and assign only the necessary digits
	size_t first = 0;//initialize the first non-zero digit position
	while (first < s.size() && s[first] == '0') {//find the first non-zero digit
		first++; //increase first to the next digit index if the current digit is 0
	}

	//here, if all digits are 0, we will set the biguint to 0 and return, then the rest of the code wont be executed
	if (first == s.size()) {//if the string is all 0s
		capacity_ = 1;//set capacity to 1, default value
		data_ = new unsigned short[1];//create a dynamic array
		data_[0] = 0;//set the only digit to 0
		return;
	}

	//now, we assign numbers for only the required number of bits (significant bits = s.size () - first)
	int needed_len = s.size() - first;//calculate the number of digits needed,
	//s.size()is the total length of the string that passed in, first is the index of the first non-zero digit
	capacity_ = needed_len;//set capacity_ to needed_len, which is the number of digits we need// typecast size_t to int because capacity_ is int in definition(in dbiguint.h)
	data_ = new unsigned short[capacity_];//create a dynamic array
	for (int i = 0; i < capacity_; i++) {	
		data_[i] = s[s.length() - 1 - i] - '0';//wo minus 0 because we need to convert char to int
	}
};



//Overload the [] operator to return the ith digit in the biguint (use the array indexing; so if they do [0] you will give the digit in the ones place). //中文：重载[]运算符以返回biguint中的第i位数字（使用数组索引；所以如果他们做[0]，你将给出个位数字）。
unsigned short dbiguint::operator [](int pos) const {//unsigned的意思是非负的
	if (pos >= 0 && pos < capacity_) {//pos is the index we want to access, so it should be non-negative and less than capacity_
		return data_[pos];//return the digit at index pos
	}
	else {
		return 0;//if pos is out of range, return 0
	}
}

//Explain how you plan to overload +=. Think about how you learned to add in elementary school. Be sure to check in with the TA before moving on.
//I plan to overload += by adding each digit, starting from the least significant digit (the rightmost digit), and carrying over any value greater than 9 to the next digit.

//Overload the += operator as a member function. The command big1 += big2; should add big2 to big1.
void dbiguint::operator += (const dbiguint& b) {
	//add each digit, starting from the least significant digit (the rightmost digit), and carrying over any value greater than 9 to the next digit.
	int carry = 0;//used to determine whether it is greater equal than 10 or not, 0 means <10, 1 means >=10
	//b is the value we passed in, a is the current object, for example: a+=b, a is this, b is the parameter
	if (size() < b.size()) {//if b is larger than a, we need to reserve more space for a
		reserve(b.size());//use reserve function to increase the capacity of a if size of b is larger than a//making sure a has enough space to hold the result
	}
	for (size_t i = 0; i < capacity_; i++) {//要把每一位加到一起，满10进1，
		//由于b可能比a短，我们需要检查b的每一位是否存在//because b may be shorter than a, we need to check if each digit of b exists
		int b_digit = 0;//get the digit from b, default is 0, when the size of b is less than i, we will use 0
		//for example: 123 + 45 = 168, when we add the hundreds place, which is when i=2, b_digit should be 0
		if (i < b.size()) {
			b_digit = b.data_[i];//once i is less than size of b, we change b_digit to the actual digit
		}
		int sum = data_[i] + b_digit + carry;//add the digits and carry together
		if (sum >= 10) {
			data_[i] = sum - 10;//if sum is greater than or equal to 10
			carry = 1;//set carry to 1
		}
		else {//if sum is less than 10
			data_[i] = sum;
			carry = 0;//set carry to 0
		}
	}
	//if there is still a carry after the last addition, we need to increase the capacity by 1//for example: 999 + 1 = 1000
	//中文：如果在最后一次加法后仍然有进位，我们需要将容量增加1，因为我们需要添加一个新数字，例如：999 + 1 = 1000
	if (carry == 1) {
		reserve(capacity_ + 1);//increase capacity by 1
		data_[capacity_ - 1] = 1;//set the new digit to 1
	}
}



//Write a new function int size() as described in the header. Modify the definition for the [] operator. 
int dbiguint::size() const {
	return capacity_;
}

//Write a member function void reserve(int new_capacity) that  updates the object as necessary to increase the capacity to new_capacity. 
void dbiguint::reserve(int new_capacity) {
	//make a new_capacity.
	if (new_capacity <= capacity_) {
		return;
	}
	else {
		unsigned short* new_data = new unsigned short[new_capacity];//create a new dynamic array
		//copy all the existing old digits to the new array
		for (int i = 0; i < capacity_; ++i) {
			new_data[i] = data_[i];
		}
		//fill the rest with 0
		for (int i = capacity_; i < new_capacity; i++) {
			new_data[i] = 0; 
		}
		delete [] data_;
		data_ = new_data;//points to the actual array in the heap
		capacity_ = new_capacity;
	}
}

ostream& operator << (ostream& out, const dbiguint& b) {
	int i = b.size() - 1;//index of last digit
	//skip leading zeros
	while (i > 0 && b[i] == 0) {
		i--;//when b[i] is 0, which means the last digit is 0, we decrease i to skip the leading zeros
	}
	for (; i >= 0; i--) {//print from the most significant non-zero digit to the least significant digit
		out << b[i];
	}
	return out;
}

void dbiguint::clean() {
	int i = capacity_ - 1;//i stores the index of the last digit
	while (i > 0 && data_[i] == 0) {
		i--;
	}
	int new_capacity = i + 1;//capacity is index + 1
	unsigned short* temp = new unsigned short[new_capacity];
	for (int j = 0; j < new_capacity; j++) {
		temp[j] = data_[j];
	}
	delete[] data_;
	data_ = temp;
	capacity_ = new_capacity;
}