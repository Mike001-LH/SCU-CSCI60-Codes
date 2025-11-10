// Driver program to test a templatized Bag class that uses dynamic arrays.
// MONDAY: Implement <<, insert, copy-constructor, assignment, and destructor
// WEDNESDAY TODO: A doubly templatized function; start implementing erase_one
//
// Sara Krehbiel, 11/3/25

#include <iostream>
#include "bag.h"
using namespace std;

int main() {
  // overload << and test 0-arg constructor and size accessor
  Bag<int> b1;
  cout << "Initial bag size: " << b1.size() << endl;//Êä³ö£ºInitial bag size: 0
  cout << "b1 contents: " << b1 << endl; //Êä³ö£ºb1 contents:

  // test insert for Bag
  size_t n = 5;
  cout << "Adding " << n << " 1s to a capacity " << b1.cap() << " bag\n";
  for (int i=0; i<n; i++) {
    b1.insert(1); // note: insert for bag plays the role of push_back for vector
    cout << "Capacity " << b1.cap() << " after insertion " << (i+1) << endl;
  }
  cout << "b1: " << b1 << endl;

  // dynamic memory management tests
  Bag<int> b2(b1); // call copy constructor to construct new bag object
  cout << "After Bag<int> b2(b1): \b1: " << b1 << "\nb2: " << b2 << endl;
  
  // copy constructor should allow us to modify two bags independently
  b2.insert(2);
  cout << "After b2.insert(2): \nb1: " << b1 << "\nb2: " << b2 << endl;

  b1.insert(3);
  cout << "After b1.insert(3): \nb1: " << b1 << "\nb2: " << b2 << endl;
   
  // assignment operator should, too
  b1 = b2; 
  cout << "After b1 = b2: \nb1: " << b1 << "\nb2: " << b2 << endl;\

  b2.insert(2);
  cout << "After b2.insert(2): \nb1: " << b1 << "\nb2: " << b2 << endl;

  b1.insert(3);
  cout << "After b1.insert(3): \nb1: " << b1 << "\nb2: " << b2 << endl;

  // NOTE: obj=obj is easy for bag but might cause problems for other classes!
  b2 = b2; 

  /*
  // erase_one tests
  cout << "Erasing one 2\n";
  b1.erase_one(2); 
  cout << b1 << endl;
  
  cout << "Erasing 1s, one-by-one\n";
  for (int i=0; i<n+2; i++) {
    b1.erase_one(1); 
    cout << b1 << endl;
    cout << "Size " << b1.size() << " and capacity " << b1.cap() << endl;
  }*/

  // check that everything works for a bag of different template type
  Bag<string> sb;
  sb.insert("hello");
  sb.insert("world");
  cout << "sb: " << sb << endl;

  // TODO: exercise for doubly templatized functions
  //cout << "b1 is " << ((b1>sb) ? "" : "not ") << "bigger than sb\n";
  
  return 0;
}

