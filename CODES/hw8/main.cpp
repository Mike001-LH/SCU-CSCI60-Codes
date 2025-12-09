// Sample test file for CSCI 60 Homework 8; due Wednesday 11/19/25
// Sara Krehbiel

#include <iostream>
#include "node.h"

using namespace std;

int main() {
  cout << "f1 test:\n";
  for (int i=0; i<10; i++) {
    cout << "a_" << i << "=" << f1(i) << endl; // CHECK: 1 1 2 3 5 7 10 13 17 21
  }

  cout << "\nf2 test:\n";
  int a1[7] = {1,2,3,4,5,6,7};
  f2(a1,0,6);
  for (int i=0; i<7; cout << a1[i++] << " "); // CHECK: 7 6 5 4 3 2 1
  cout << endl;
  int a2[4] = {4, 7, 3, 12}; 
  f2(a2,0,3);
  for (int i=0; i<4; cout << a2[i++] << " "); // CHECK: 12 3 7 4
  cout << endl;

  cout << "\nUsing << overloaded for linked lists:\n";
  node *head=nullptr, *tail=nullptr;
  head = tail = new node(3,head); // construct last element on heap
  head = new node(4,head); // construct penultimate element linking to last
  head = new node(5,head); // construct first element linking to penultimate
  cout << "Initial list: " << head << endl; // CHECK: 5 4 3

  cout << "\nf4 test:\n";
  f4(head,tail);
  cout << "After clearing: " << head << endl; // CHECK: 

  cout << "\nf3 test:\n";
  int *arr = new int[7];
  for (int i=0; i<7; i++) arr[i] = ((i<2) ? i : arr[i-1]+arr[i-2]); 
  f3(head,tail,arr,7);
  cout << head << endl; // CHECK: 0 1 1 2 3 5 8

  return 0;
}
