#include <iostream>
#include <l_iterator.h>
#include <node.h>
#include <bag.h>
using namespace std;

int main() {
	Bag<int> b;
	//insert calls
	int total = 0;
	for (int elem : b) {
		total += elem;
	}
	for (Bag<int>::iterator it = b.begin(); it != b.end(); it++) {
		total += *it;
	}
}