// Interface for templatized dynamic array implementation of Bag.
// Also includes all the implementation normally in the cpp file.
// Sara Krehbiel, class design by Natalie Linnell and Nicholas Tran, 10/29/25

#ifndef BAG_H
#define BAG_H

#include <ostream>
using std::size_t;
using std::ostream;

// INTERFACE

template <typename T>
class Bag {
public:
  // constructor
  Bag() : size_(0), cap_(0), data_(nullptr) {}

  // mutator
  void insert(T val);

  // accessor(s)
  size_t getSize() const { return size_; }
  size_t getCapacity() const { return cap_; }
  T operator [](size_t index) const { return data_[index]; } 

private:
  T *data_; // the address associated with a dynamic array
  size_t size_; // how much memory is currently used
  size_t cap_; // how much memory is currently allocated
  // INVARIANTS: data_[0],...,data_[size_-1] always contain the elements 
};

// declaration for << overloaded for bag
template <typename T> // outside class, so need new template prefix
ostream& operator <<(ostream& out, const Bag<T>& b);



// IMPLEMENTATION
template <typename T>
void Bag<T>::insert(T val) {} // TODO: replace this stub next week


#endif

//新知识点：
//template<typename T>
//Templates 是 C++ 中的一个强大功能，让程序员能够编写通用的代码，使得类型在使用时才被确定。就像一个"烤饼干模具"，你可以用它做巧克力饼干、燕麦饼干等，但模具本身不会改变。
//使用方法：
//1. 定义模板：使用 template 关键字定义一个模板，指定一个或多个类型参数。
//2. 使用模板：在使用模板时，指定具体的类型参数，编译器会生成相应类型的代码。
//例如：
/*
template <typename T>
T add(T a, T b) {
	return a + b;
}
*/
//这里定义了一个模板函数 add，可以接受任何类型的参数，只要这些类型支持加法操作。
//然后你可以这样使用它：
/*
* int main() {
	int x = 5, y = 10;
	double p = 5.5, q = 10.2;
	cout << add(x, y) << endl; // 输出 15
	cout << add(p, q) << endl; // 输出 15.7
	return 0;
}
*/
//这段代码展示了模板函数的强大之处，可以处理不同类型的数据，而不需要为每种类型编写单独的函数。
//模板类：类似于模板函数，模板类允许你定义一个类的通用版本。
//例如：
/*
* template <typename T>
* class Box {
* private:
*    T content;//定义一个类型为 T 的成员变量 content
* public:
*   void setContent(T c) { content = c; }
*   T getContent() const { return content; }
* };
*/	
//这里定义了一个模板类 Box，可以存储任何类型的内容。
//然后你可以这样使用它：
/*
* int main() {
*  Box<int> intBox; // 创建一个存储整数的 Box
*  intBox.setContent(123);
*  cout << intBox.getContent() << endl; // 输出 123
*  Box<string> strBox; // 创建一个存储字符串的 Box
*  strBox.setContent("Hello, Templates!");
*  cout << strBox.getContent() << endl; // 输出 "Hello, Templates!"
*  return 0;
* }
*/
//这里展示了模板类的灵活性，可以创建不同类型的对象，而不需要为每种类型编写单独的类定义。