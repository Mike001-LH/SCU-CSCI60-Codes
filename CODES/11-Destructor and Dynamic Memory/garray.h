// Interface for GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/22/25

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>

//using namespace std;
using std::ostream;
using std::cout; // for debugging
using std::endl; // for debugging

class GArray {
public:
	GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor, initializes empty array//0参构造器，初始化为空动态数组
  ~GArray(); // destructor (automatically called by compiler)//destructor是用来释放动态内存的，作用为：释放动态分配的内存，写法为
			 // GArray::~GArray() {
			 //    delete [] data_;
			 //    data_ = nullptr;
			 // }

  // TODO: declare dynamic memory management functions = and copy constructor

  // mutator to insert in new slightly larger array//中文：插入一个新的稍微大一点的数组
  void insert(int val); 

  // accessors to get size, individual elements, and location of array//获取大小、单个元素和数组位置的访问器
  size_t length() const { return size_; }//返回数组的长度
  int operator [](size_t i) const { return data_[i]; }//重载[]运算符，返回数组中第i个元素的值
  int* address() const { return data_; }//返回数组的地址

private:
  size_t size_;//存储数组的大小
  int* data_;//指向动态分配的整数数组的指针
  // INVARIANT: data_ addresses a dynamic array of size_ ints if size_>0, 
  //            or data_ is nullptr
};

ostream& operator <<(ostream& out, const GArray& a); // insertion overload//重载插入运算符

#endif