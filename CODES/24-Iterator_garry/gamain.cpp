// Driver program for our Week 5 (inefficiently) growable array class,
// now with added iterator functionality.
//   
// Sara Krehbiel, 12/3/25 

#include <iostream>
#include "garray.h"

using namespace std;

int main() {
  // insert 3 ints into a GArray object
  GArray arr;
  for (int i=0; i<5; i++) arr.insert(i);

  // print out contents 3 ways
  cout << "Contents output via <<:\n" << arr << endl;
  cout << "Contents output via standard for loop:\n";
  for (int i=0; i<arr.length(); i++) { // note: uses length and overloaded []
    cout << arr[i] << " ";
  }
  cout << endl;
  
  cout << "Contents output via an iterator-powered range-based for loop:\n";
  for (int val : arr) {
    cout << val << " ";
  }
  cout << endl;
  
	return 0;
}

