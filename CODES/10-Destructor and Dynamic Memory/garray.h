// Interface for GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/22/25

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>

//using namespace std;
using std::ostream;//ostream是一种输出流类型
using std::cout; // for debugging
using std::endl; // for debugging

class GArray {
public:
  GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor//这个构造函数初始化了一个空的GArray对象，大小为0，数据指针为nullptr

  // TODO: declare dynamic memory management functions

  // mutator to insert in new slightly larger array
  void insert(int val); // TODO: implement in garray.cpp//这个函数将在garray.cpp中实现，用于在动态数组中插入一个新的整数值

  // accessors to get size, individual elements, and location of array
  size_t length() const { return size_; }//返回当前存储的整数数量
  int operator [](size_t i) const { return data_[i]; }//重载 中括号 运算符，使对象可用 arr[i] 访问元素（只读）
  int* address() const { return data_; }//返回指向动态整数数组的指针	// 返回底层数组指针，仅供调试使用，外部不要 delete[]

private:
  size_t size_;// 存储的整数数量
  int* data_;//这是一个指向动态整数数组的指针
  // INVARIANT: data_ addresses a dynamic array of size_ ints if size_>0, 
  //            or data_ is nullptr
};

ostream& operator <<(ostream& out, const GArray& a); //重载输出运算符。返回 ostream&（引用），用于链式输出：cout << a << b;
// TODO: implement
//ostream& out是输出流的引用，const GArray& a是要输出的GArray对象的常量引用

#endif