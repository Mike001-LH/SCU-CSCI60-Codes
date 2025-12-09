// Test code for templatized linked list implementation of bag
// To compile: g++ main.cpp bag.cpp node.cpp -std=c++11
// Sara Krehbiel, 11/14/25

#include <iostream>
#include "bag.h" 

using namespace std;

int main() {
  // construct empty bag and insert 3 elements
  Bag<int> b;
  cout << "size: " << b.size() << endl;
  b.insert(1);
  cout << "size: " << b.size() << endl;
  b.insert(2);
  cout << "size: " << b.size() << endl;
  b.insert(3);
  cout << "size: " << b.size() << endl;
  cout << "b: " << b << endl;
  return 0;
}
