// Test code while completing the static array implementation of Bag.
//
// Note: You must compile this and the implementation file to run this, e.g.,
//   $ g++ bagtests.cpp bag.cpp -std=c++11
//
// Sara Krehbiel, 10/6/25

#include <iostream>//for console input and output
#include <fstream>//for file input and output
#include "bag.h"

using namespace std;

int main() {
	cout << "Any Bag has capacity " << Bag::CAPACITY << endl; // static const

	// construct an empty bag and add to it

	Bag b1; // default/0-arg constructor
	size_t n = b1.size();
	cout << "Initial bag size: " << n << endl;
	b1.insert(2); 
	b1.insert(3); 
	cout << "Size after inserting 2 and 3: " << b1.size() << endl;
	cout << "The first entry is " << b1[0] << endl;
	cout << "The next entry is " << b1[1] << endl;
	cout << "The next entry is " << b1[2] << endl; // undefined content!
	cout << "The next entry is " << b1[3] << endl; // undefined content!

	// use << to print contents of bag to console
	cout << b1 << endl;

	// use the same << to print contents of bag to file
	ofstream fout("contents.txt");
	fout << b1 << endl;
	fout.close();


	// construct a bag initialized with some contents, query, and erase from it

	int arr[5];// = {5, 4, 5, 5, 1}; // initialize an array
	arr[0]=5; arr[1]=4; arr[2]=5; arr[3]=5; arr[4]=1;
	/*Bag b2(arr,5); // 2-arg constructor
	cout << "Bag 2:\n" << b2 << endl; // use of overloaded insertion
	cout << "Bag 2 size: " << b2.size() << endl;

	cout << b2.count(5) << " 5s\n";

	cout << "Attempting to erase 4:\n";
	bool erased = b2.erase_one(4);
	cout << (erased?"C":"Not c") << "hanged: " << b2 << endl;
	cout << "Attempting to erase -1:\n";
	erased = b2.erase_one(-1);
	cout << (erased?"C":"Not c") << "hanged: " << b2 << endl;
	cout << "Erasing all 5s:\n";
	cout << b2.erase(5) << " erased: " << b2 << endl;*/
	
	// test code to make sure erasing at end of bag works

	/*Bag b3; // call 0-arg constructor for an empty bag
	b3.insert(1);
	b3.insert(2);
	b3.insert(3);
	cout << b3 << endl;
	b3.erase_one(3);
	cout << b3 << endl;*/


	// test code for += and +

	/*cout << "b1: " << b1 << "\nb2: " << b2 << endl;
	b2+=b1; // += mutates left operand (b2) without creating a new object
	cout << "b2, after b2+=b1: " << b2 << endl;
	+ creates new object, but this test code inserts it without naming
	cout << "b1+b2: " << b1+b2 << endl; */

	return 0;
}

