// Starter test program for CSCI 60 Homework 5; due Wednesday 10/29/25

#include <iostream>
#include "parity.h"

using namespace std;

int main() {
	Parity p; // a 0-argument function is implemented for you
	p.insert(3);
	p.insert(2);
	p.insert(4);
	cout << p; // the stub function for << exists but doesn't output anything
	cout << "Min: " << p.min() << endl;
	cout << "Max: " << p.max() << endl;
	cout << "Odd? " << (p.odd()?"yes":"no") << endl;
	return 0;
}
