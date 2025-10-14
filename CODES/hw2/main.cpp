// Test program starter file for CSCI 60 Homework 2; due Wednesday 10/8/25
// Give a program description, list any collaborators, and write your name here

#include <iostream>
#include "histogram.h"//you are defining a variable named h of type Histogram.

using namespace std;

int main() {

  /* TODO: replace this comment and the code below with your unit tests */
  
  // // your constructor needs similar file-reading code to initialize a Histogram
  // int total = 0; // var to store total
  // ifstream in("data.txt"); // open a file called data.txt as an input stream in
  // int val; // var to store one int at a time
  // while (in >> val) { // read int tokens from stream 1-by-1 until end of file
  //   total += val; // add value of each token to total
  // }
  // in.close(); // close file
  // cout << "Sum of all ints in a file = " << total << endl; // report total

  // Histogram h("data.txt"); 
  // //Histogram h2("data2.txt"); // constructor should work for other filenames!
  // cout << "The stub 1-argument constructor ran without error!\n";
  // //cout << h; // after overloading <<, compare this to the hw2.pdf sample run


//step9: test the program
  Histogram h("data.txt"); //变量（h）= 真正造出来的“物品”, 创建变量（对象）histogram.h
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




/*result from my terminal:
lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2
$ g++ histogram.cpp main.cpp -o hw2.exe -std=c++11

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2
$ ./hw2.exe
Total count = 8
Min = 1
Max = 9
Mode = 2
Median = 2
Mean = 3
Variance = 5.5

Histogram:
1: *
2: ****
3: **
9: *

*/