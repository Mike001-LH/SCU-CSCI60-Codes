// Test code for templatized linked list implementation of our bag class
// Week 9: 
//   MON: Finish implementing accessor/mutators (count, erase_one, erase)
//   WED: Implement dynamic memory management functions (copy-constructor, ~, =)
//   FRI: Learn about iterators and start implementing one for Bag
// Week 10:
//   MON: Learn about pre- and post-incrementation and finish L_iterator
// To compile: g++ main.cpp bag.cpp node.cpp -std=c++11
// Sara Krehbiel, 11/17/25-12/1/25

#include <iostream>
#include "bag.h" 
#include <vector>

using namespace std;

void bagTests(); // bag test code (week 9)
void iteration(); // intro to iterators
void printArray(int arr[], size_t n); // can't use range-based for loop
template<typename T>
void printVector(const vector<T>& vec); // can use range-based for loop
void bagIteratorTests(); // implement and test a basic iterator for bag
void preAndPostIncrement(); // learn about n++ vs ++n and apply to iterators


int main() {
  //bagTests();
  //iteration();
  //bagIteratorTests();
  preAndPostIncrement();
  return 0;
}

// test code for basic bag functionality (without an iterator)
void bagTests() {
  // construct empty bag and insert 3 elements
  Bag<int> b;
  b.insert(1);
  b.insert(2);
  b.insert(2);
  b.insert(3);
  
  // test << overload and size/count member functions
  cout << "b: " << b << endl; 
  cout << "size: " << b.size() << endl;
  cout << "#1s: " << b.count(1) << endl;
  cout << "#2s: " << b.count(2) << endl;
  cout << "#3s: " << b.count(3) << endl;
  cout << "#4s: " << b.count(4) << endl;
  Bag<int> empty;
  cout << "#1s in an empty bag: " << empty.count(1) << endl;
  
  // test erase_one and erase functions
  cout << b.erase(2) << endl;
  //cout << b.erase_one(3) << endl; 
  //cout << b.erase_one(5) << endl;
  cout << "b: " << b << endl;
  
  // test copy constructor and assignment
  Bag<int> b2(b);
  b2.insert(4);
  cout << "Bag<int> b2(b);\nb2.insert(4);\n";
  cout << "b:  " << b << endl;
  cout << "b2: " << b2 << endl;
  b2.erase_one(3);
  cout << "b2.erase_one(3);\n";
  cout << "b:  " << b << endl;
  cout << "b2: " << b2 << endl;
  b=b2;
  cout << "b=b2;\n";
  cout << "b:  " << b << endl;
  cout << "b2: " << b2 << endl;
  
  cout << "about to return from bag tests\n"; // cout in list_clear helps test ~
}

// sample code to demonstrate how range-based for loops and iterators work
void iteration() {
  // a local, statically-allocated array
  int arr[3] = {8,-9,10};

  // a standard for loop to iterate through array contents
  for (size_t i=0; i<3; i++) {
    cout << *(arr+i) << " "; // recall *(arr+i) is the same as arr[i]
  }
  cout << endl;

  // a range-based for loop for a (local, statically-allocated) array
  for (int elem : arr) {
    cout << elem << " ";
  }
  cout << endl;

  printArray(arr,3); // arr forgets its size when passed (by address) into a fn

  // same strategies with a locally-declared vector
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  // print contents with standard for loop + overloaded array-style subscripting
  for (size_t i=0; i<vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  // a range-based for loop for a vector objeect
  for (int elem : vec) {
    cout << elem << " ";
  }
  cout << endl;

  // can use for loops for vectors passed (by reference or value) into a fn
  printVector(vec); 

  // this is how a range-based for loop uses iterators!
  for (vector<int>::iterator it = vec.begin(); it!=vec.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  // an iterator is a pointer-like object with the following functionality:
  // 1/ it can be constructed by some underlying container object 
  // 2/ it can be dereferenced to get a single piece of data 
  // 3/ it can be compared to other iterators
  // 4/ it can be incremented
}

// we pass array size into a function because arrays are passed as addresses;
// that's why a range-based for loop doesn't work here!
void printArray(int a[], size_t n) {
  for (size_t i=0; i<n; i++) {
    cout << a[i] << " ";
  }
  /*for (int elem : a) { // only possible if a is declared statically in scope
    cout << elem << " ";
  }*/
  cout << endl;
}

// iterator is accessible for vectors passed (by value or ref) into a function
template <typename T>
void printVector(const vector<T>& vec) {
  for (T elem : vec) { // possible because of vector's built-in iterator
    cout << elem << " ";
  }
  cout << endl;
}

// test code for our custom bag iterator
void bagIteratorTests() {
    // construct empty bag and insert 3 elements
  Bag<int> b;
  b.insert(1);
  b.insert(2);
  b.insert(2);
  b.insert(3);

  cout << "b: " << b << endl; 
  
  // compiler needs specific instructions for a bag range-based for-loop
  for (int elem : b) {
    cout << elem << " ";
  }
  cout << endl;
  
  // specifically, need to overload !=, ++ (note subtleties!), and *
  for (Bag<int>::iterator it = b.begin(); it!=b.end(); it++) {
    cout << *it << " ";
  }
  cout << endl; 
}

// test code for pre- and post-increment for ints and iterators
void preAndPostIncrement() {
  // note how n++ and ++n work differently for ints
  int n = 0;
  cout << n << endl;
  n++; 
  cout << n << endl;
  ++n; 
  cout << n << endl;
  cout << n++ << endl;
  cout << n << endl;
  cout << ++n << endl;
  cout << n << endl;

  // implement ++() and ++(int) to work the same for iterators
  Bag<int> b;
  for (int i=4; i>=0; i--) b.insert(i);
  cout << b << endl; // a bag with contents 0 1 2 3 4
  auto it = b.begin();
  cout << *it << endl;
  it++;
  cout << *it << endl;
  ++it;
  cout << *it << endl;
  cout << *(it++) << endl;
  cout << *it << endl;
  cout << *(++it) << endl;
  cout << *it << endl;
  
}
