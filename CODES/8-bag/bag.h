// Complete interface for static array implementation of a container called Bag,
// which should holds up to CAPACITY ints, possibly with repetition. 
//
// Sara Krehbiel, via Natalie Linnell and Nicholas Tran, 10/8/25

#ifndef BAG_H
#define BAG_H

#include <cstdlib>// for size_t
using std::size_t; // allows you to use size_t instead of std::size_t

#include <iostream>
using std::ostream; // allows you to use ostream instead of std::ostream
// Note: using namespace std in class defns results in namespace pollution

class Bag {
public:
  static const size_t CAPACITY = 1000; // static = NOT a member variable

  // constructors (post-conditions guarantee well-structured bags) //中文： 构造函数（后置条件保证结构良好的包）
  Bag() : size_(0) {}// default/0-arg constructor (内联定义) //size_(number of ints currently in the bag) initialized to 0 //内联定义的构造函数，所以不需要在bag.cpp中再写一遍
  // ↑↑↑ 内联定义：编译器在调用 Bag() 时，直接插入 "size_ = 0" 的初始化代码，
  // 不必跳转到别处执行。

  // 2-arg constructor 只声明（实现写在 bag.cpp）
  Bag(int a[], size_t n);// 2-arg constructor //a[]是n个int的数组，n是数组大小

  // accessors (pre- and post-conditions are the same well-structured bags)//中文： 访问器（前置条件和后置条件都是相同的结构良好的包）
  size_t size() const { return size_; }//返回当前bag中int的数量
  int operator [](size_t index) const { return data_[index]; }//返回data_中index位置的int，data_是存储int的数组
  size_t count(int val) const; // returns #times val appears in data_

  // mutators (pre-conditions are well-structured bags, post-conditions differ)//中文： 变异体（前置条件是结构良好的包，后置条件不同）

  // Post: if the bag has excess capacity, val is inserted into the next
  //       available spot in data_ and size_ is incremented; no change otherwise
  void insert(int val) { if (size_ < CAPACITY) data_[size_++] = val; } //解释：如果当前bag中int的数量小于CAPACITY，则将val插入到data_的下一个可用位置，并将size_加1；否则不做任何改变

  // Post: if data_ initially contained val, first copy is removed (overwritten)
  //       with size_ decremented and true returned; otherwise false is returned
  bool erase_one(int val);

  // Post: all copies of val are removed with # removed returned
  size_t erase(int val);

  // Post: rhs contents are inserted in order to calling object, rhs unchanged
  void operator +=(const Bag& rhs); // NOTE: const param but not a const fn!
 
private:
	int data_[CAPACITY];// array of ints, with unused entries unspecified
	size_t size_;// number of ints currently in the bag
  // INVARIANT: data_[0],...,data_[size_-1] contain previously-inserted ints,
  //            and size_<=CAPACITY
};

// Post: bag with lhs and rhs contents in order returned, lhs and rhs unchanged
Bag operator +(const Bag& lhs, const Bag& rhs);

// Post: in-order true contents of b.data_ are inserted into ostream o
ostream& operator <<(ostream& o, const Bag& b);


#endif
