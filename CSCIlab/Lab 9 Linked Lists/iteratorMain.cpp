#include <iostream>
#include "lbiguint.h"
using namespace std;

int main() {
	string s = "12345";
	lbiguint a(s);
	lbiguint b;
	cout << a << endl;
	return 0;
}