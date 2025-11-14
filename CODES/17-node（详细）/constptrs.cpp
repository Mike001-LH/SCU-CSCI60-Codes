// Goal: Learn how const affects pointers.
// Sara Krehbiel, 11/10/25

#include <iostream>

using namespace std;

int main() {
  int a = 5, b = 6;

  int* pa = &a; // can reassign pa and can change the value it points to//可以重新分配pa并且可以更改它指向的值
  //const int *pa = &a; // can reassign pa, can't change the value it points to//可以重新分配pa，不能更改它指向的值
  //int *const pa = &a; // can't reassign pa, can change the value it points to//不能重新分配pa，可以更改它指向的值
  //const int *const pa = &a; // can't change value or location pa points to//不能更改pa指向的值或位置

  cout << "a: " << a << ", b: " << b << ", *pa: " << *pa << endl;

  *pa = b + 3; //  const int * pa outlaws this one //const int * pa禁止此操作
  pa = &b; //  int * const pa outlaws this one //int * const pa禁止此操作

  cout << "a: " << a << ", b: " << b << ", *pa: " << *pa << endl;

  return 0;
}
