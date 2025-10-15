#include <iostream>// for cout, endl
#include <fstream>// for ofstream
#include "biguint.h"// include the interface for biguint
#include <cassert>// for assert
#include <string>// for string
using namespace std;

int main() {
	biguint a;
	biguint b("2233");
	biguint c("0721");
	a += b;
	a += c;	
	//operator [] test
	for(size_t i=0; i< biguint::CAPACITY; i++){
		cout << a[i] << " ";
	}



	return 0;
}