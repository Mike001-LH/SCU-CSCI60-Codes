#include <iostream>// for cout, endl
#include <fstream>// for ofstream
#include "dbiguint.h"
#include <cassert>// for assert
#include <string>// for string
using namespace std;

int main() {
	//test default constructor
	dbiguint a;
	//test 1-arg constructor
	dbiguint b("2233");
	dbiguint c("6721");
	//test int size() const;
	cout << "Size of b: " << b.size() << endl;
	cout << "Size of c: " << c.size() << endl;
	//test << operator overload
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	//test += operator overload
	a += b;
	a += c;
	cout << "a after += b and c: " << a << endl;

	return 0;
}