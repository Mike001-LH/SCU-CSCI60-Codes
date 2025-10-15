#include "biguint.h"

// default/0-arg constructor
biguint::biguint() {
	for (size_t i = 0; i < CAPACITY; i++) {
		data_[i] = 0;
	}
};
// 1-argument constructor
//write the constructor that takes in a string.
//convert the character ‘5’ to the number 5 by subtracting the character ‘0’ from it.//For example, ‘5’ - ‘0’ = 5.
biguint::biguint(string s) {
	for (size_t i = 0; i < CAPACITY; i++) {
		if(i < s.length()){
			data_[i] = s[s.length() - 1 - i] - '0';//wo minus 0 because we need to convert char to int
		}
		else {
			data_[i] = 0;
		}
	}
};

//Overload the [] operator to return the ith digit in the biguint (use the array indexing; so if they do [0] you will give the digit in the ones place). //中文：重载[]运算符以返回biguint中的第i位数字（使用数组索引；所以如果他们做[0]，你将给出个位数字）。
unsigned short biguint::operator [](int pos) {
	if (pos<CAPACITY) {
		return data_[pos];//返回pos位置的数字
	}
	else {
		return 0;//if pos is out of range, return 0
	}
}

//Explain how you plan to overload +=. Think about how you learned to add in elementary school. Be sure to check in with the TA before moving on.
//I plan to overload += by adding each digit, starting from the least significant digit (the rightmost digit), and carrying over any value greater than 9 to the next digit.

//Overload the += operator as a member function. The command big1 += big2; should add big2 to big1.
void biguint::operator += (biguint b) {
	//add each digit, starting from the least significant digit (the rightmost digit), and carrying over any value greater than 9 to the next digit.
	int carry = 0;//used to determine whether it is greater equal than 10 or not, 0 means <10, 1 means >=10
	for (size_t i = 0; i < CAPACITY; i++) {//要把每一位加到一起，满10进1，
		int sum = data_[i] + b.data_[i] + carry;//add the digits and carry together
		if (sum >= 10) {
			data_[i] = sum - 10;//if sum is greater than or equal to 10
			carry = 1;//set carry to 1
		}
		else {//if sum is less than 10
			data_[i] = sum;
			carry = 0;//set carry to 0
		}
	}

}
