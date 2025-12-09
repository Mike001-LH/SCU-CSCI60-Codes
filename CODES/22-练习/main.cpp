// Test code for templatized linked list implementation of our bag class
// Week 9: 
//   MON: Finish implementing accessor/mutators (count, erase_one, erase)
//   WED: Implement dynamic memory management functions (copy-constructor, ~, =)
//   FRI: Learn about iterators and start implementing one for Bag
// To compile: g++ main.cpp bag.cpp node.cpp -std=c++11
// Sara Krehbiel, 11/17/25-11/21/25

#include <iostream>
#include "bag.h" 
#include <vector>

using namespace std;

void bagTests(); // Week 9

void iteration(); // intro to iterators
void printArray(int arr[], size_t n);
template<typename T>
void printVector(const vector<T>& vec);

void bagIteratorTests(); 

int main() {
  //bagTests();
  //iteration();
  bagIteratorTests();
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
  /*int arr[3] = {8,-9,10};

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

  //return;

  printArray(arr,3); // error: arr forgets its size when passed into fn
  return;*/

  // same strategies with a locally-declared vector
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  for (size_t i=0; i<vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  for (int elem : vec) {
    cout << elem << " ";
  }
  cout << endl;

  printVector(vec);

  // equivalent to the range-based for loop above
  for (vector<int>::iterator it = vec.begin(); it!=vec.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

}

void printArray(int a[], size_t n) {
  for (size_t i=0; i<n; i++) {
    cout << a[i] << " ";
  }
  /*for (int elem : a) { // only possible if a is declared statically in scope
    cout << elem << " ";
  }*/
  cout << endl;
}

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
  
  // compiler needs more instructions for a bag range-based for-loop
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
