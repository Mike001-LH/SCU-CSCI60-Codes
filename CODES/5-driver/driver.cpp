// Source code for driver program that uses the Duration class.
// The program illustrates how to call all the functions in the Duration class,
// including 0-, 1-, and 2-argument constructors, a toString member function, 
// and the overloaded + operator; operator overloading is the main new concept. 
// Note: You must compile the implementation file to run this, e.g.,
//   $ g++ driver.cpp duration.cpp -std=c++11
// Sara Krehbiel, 10/1/25

#include <iostream>
#include "duration.h" // include the interface file
using namespace std;

int main() {
  // construct three objects and test the toString member function
  Duration d0; // calls a 0-arg constructor (or default iff none are defined)
  Duration d1(1,55); // calls a 2-arg constructor
  Duration d2(100); // calls a 1-arg constructor
  cout << "D0: " << d0.toString() << endl; // calls a toString member function
  cout << "D1: " << d1.toString() << endl; 
  cout << "D2: " << d2.toString() << endl;

  // TODO: add duration objects together in several ways
  //   1. Using member function sumDuration
  //   2. Using nonmember function sumDuration
  //   3. Using friend function
  //   4. Using + overloaded as member function
  //   5. Using + overloaded as friend function
  //   6. Using + overloaded as nonmember nonfriend function

  //Duration total = d1.sumDuration(d2); // member function
  //Duration total = sumDuration(d1,d2); // nonmember function (friend or not)
  //Duration total = d1+d2; // overloaded operator (member or not, friend or not)
  //cout << "Total: " << total.toString() << endl;

  return 0;
}

