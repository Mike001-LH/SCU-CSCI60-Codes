// Interface for GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/24/25

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>

//using namespace std;
using std::ostream;// for operator <<，ostream是标准输出流的类型
using std::cout; // for debugging
using std::endl; // for debugging

class GArray {
public:
	// constructor and dynamic memory management functions//构造器和动态内存管理函数
	//rule of three: 如果一个类需要自定义析构函数、拷贝构造函数或赋值运算符中的任何一个，那么通常需要自定义另外两个，以确保资源管理的一致性和正确性。
  GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor
  GArray(const GArray&); // copy constructor (deep copy other into new object)//1，拷贝构造函数（将other深拷贝到新对象中），当用一个对象初始化另一个对象时调用。
  ~GArray(); // destructor (automatically called by compiler)//2，析构函数（由编译器自动调用），当对象生命周期结束时自动调用，用于释放资源。
  void operator =(const GArray& rhs); // assignment (deep copy rhs into this) //3，赋值运算符（将rhs深拷贝到this中），当一个对象被赋值给另一个对象时调用。

  // mutator to insert in new slightly larger array
  void insert(int val); 

  // accessors to get size, individual elements, and location of array
  size_t length() const { return size_; }
  int operator [](size_t i) const { return data_[i]; }
  int *address() const { return data_; }

private:
  size_t size_;//这是数组的当前大小
  int* data_;//这是一个指向动态分配的整数数组的指针
  // INVARIANT: data_ addresses a dynamic array of size_ ints if size_>0, 
  //            or data_ is nullptr
};

ostream& operator <<(ostream& out, const GArray& a); // insertion overload //输出重载，一般来说输出重载都要通过传入ostream引用和const对象引用来实现链式输出

#endif

/*这节课的新知识点讲解：
1. 深拷贝与浅拷贝的区别
2. 动态内存分配与释放
3. 析构函数的作用
4. 拷贝构造函数的实现
5. Rule of Three（三法则）

1. 深拷贝与浅拷贝的区别：
浅拷贝只是简单地复制指针地址，导致多个对象共享同一块内存，可能会在一个对象被销毁时导致其他对象的悬挂指针问题。
深拷贝则是为每个对象分配独立的内存空间，复制实际数据，避免了上述问题。
浅拷贝（shallow copy）代码示例：
GArray a;
GArray b = a; // 默认浅拷贝：b.data_ 与 a.data_ 指向同一块堆内存！
深拷贝（deep copy）代码示例：
//这里写一个简单的深拷贝实现
void GArray::operator =(const GArray& rhs) {// 重载赋值运算符实现深拷贝
	size_ = rhs.size_;//size_和rhs.size_相等，比方说，在调用 GArray a = b; 时, size_就是a的size_rhs, rhs.size_就是b的size_//这里之所以不用写成lhs.size_，是因为lhs是隐含的调用对象，因为这是一个member function
	data_ = new int[size_];//创建一个新的动态数组，分配内存
	for (size_t i=0; i<size_; i++) {
		data_[i] = rhs.data_[i];//复制数据，实现深拷贝，而不是简单地复制指针地址
	}
}
这里我们通过传入地址对象rhs，分配新的内存，并复制数据，实现了深拷贝。

2. 动态内存分配与释放：
动态内存分配允许程序在运行时请求内存空间，使用new关键字分配内存，使用delete释放内存，防止内存泄漏。

3. 析构函数的作用：
析构函数用于释放对象占用的资源，包括动态分配的内存。它在对象生命周期结束时自动调用，确保资源得到正确释放，防止内存泄漏。
语法为：
~ClassName() {
	// 释放资源的代码，包含delete语句和指针置空等操作
}
// 例如：
GArray::~GArray() {
	delete [] data_; // 释放动态数组内存
	data_ = nullptr; // 避免悬挂指针
	size_ = 0; // 重置大小
}
//这个析构函数适用于释放GArray对象的动态数组内存，防止内存泄漏。此外，size_重置为0是因为对象生命周期结束后，size_不再有意义。

4. 拷贝构造函数的实现：
拷贝构造函数用于创建一个新对象，并将另一个同类型对象的内容复制到新对象中。它通常用于按值传递对象或返回对象时。
语法为：
ClassName(const ClassName& other) {
	// 复制other对象的数据到新对象
}
	// 例如：
GArray a;
GArray b = a; // 调用拷贝构造函数
GArray::GArray(const GArray& other) : GArray() {//这里调用了默认构造函数初始化新对象，效果是先将size_设为0，data_设为nullptr//此外，这里传入的是const引用的other对象（把本体传过来但不做修改）
	//other是已经存在的对象，我们要把它的内容复制到新对象中
	size_ = other.size_;//将other的size_赋值给新对象的size_
	data_ = new int[size_];
	for (size_t i=0; i<size_; i++) {
		data_[i] = other.data_[i];
	}
}

5. Rule of Three（三法则）：
如果一个类需要自定义析构函数（destructor）、拷贝构造函数（copy constructor）或赋值运算符（assignment operator）中的任何一个，那么通常需要自定义另外两个，以确保资源管理的一致性和正确性。
语法示例：
class ClassName {
public:
	ClassName(); // 默认构造函数
	ClassName(const ClassName&); // 拷贝构造函数
	~ClassName(); // 析构函数
	void operator =(const ClassName&); // 赋值运算符
	private:
	// 成员变量
	};
}



*/