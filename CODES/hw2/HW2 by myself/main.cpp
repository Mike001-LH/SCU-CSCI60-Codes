// Test program starter file for CSCI 60 Homework 2; due Wednesday 10/8/25
// Give a program description, list any collaborators, and write your name here

#include <iostream>
#include "histogram.h"

using namespace std;

int main() {

  /* TODO: replace this comment and the code below with your unit tests */

  //// your constructor needs similar file-reading code to initialize a Histogram
  //int total = 0; // var to store total
  //ifstream in("data.txt"); // open a file called data.txt as an input stream in
  //int val; // var to store one int at a time
  //while (in >> val) { // read int tokens from stream 1-by-1 until end of file
  //  total += val; // add value of each token to total
  //}
  //in.close(); // close file
  //cout << "Sum of all ints in a file = " << total << endl; // report total

  //Histogram h("data.txt"); 
  ////Histogram h2("data2.txt"); // constructor should work for other filenames!
  //cout << "The stub 1-argument constructor ran without error!\n";
  ////cout << h; // after overloading <<, compare this to the hw2.pdf sample run

	cout << "testing start!" << endl;
	Histogram h("data.txt");//Create a Histogram object named h and read data from the file data.txt
	cout << "Total count = " << h.size() << endl;
	cout << "Min = " << h.min() << endl;
	cout << "Max = " << h.max() << endl;
	cout << "Mode = " << h.mode() << endl;
	cout << "Median = " << h.median() << endl;
	cout << "Mean = " << h.mean() << endl;
	cout << "Variance = " << h.variance() << endl;
	cout << "\nHistogram:\n" << h; //"<< h" triggers ostream& operator<<(ostream& out, const Histogram& h); thus print the whole Histogram
	return 0;
}
