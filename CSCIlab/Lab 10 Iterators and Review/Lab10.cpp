#include <iostream>
#include "bag.h"
using namespace std;

int main() {
	int arr[] = {1,2,3,4,5,6,7};
	bag<int> b(arr, 7);
	for (auto val : b) {
		cout << val << endl;
	}
	for (bag<int>::iterator trace = b.begin(); trace != b.end(); trace++) {
		cout << *trace << endl;
	}
	return 0;
}