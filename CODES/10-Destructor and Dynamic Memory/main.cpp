// Test file illustrating memory management for classes, specifically GArray.
// We'll implement insert to handle dynamic memory for a single object, and 
// by the end of the week, we'll have understood the need for and implemented
// an overloaded assignment operator, a copy constructor, and a destructor.
//
// TODO: 
//   Overview interface in garray.h and insertTests in main
//   Implement insert using dynamic memory
//   Implement DESTRUCTOR with cout statements to see when it's called
//   Overload ASSIGNMENT operator to deep copy rhs
//   Implement a COPY CONSTRUCTOR to deep copy existing object into new one
//   Add cout statements for assignment, copy constructor, and destructor
//    and run passByValueAndReturnObject to see when they are called
//   
// Sara Krehbiel, 10/22/25-10/24/25
// ------------------------------------------------------------
//翻译：
// 测试文件说明类的内存管理，特别是GArray。
// 我们将实现insert来处理单个对象的动态内存，
// 到本周末，我们将理解并实现重载的赋值运算符、
// 复制构造函数和析构函数的必要性。
// TODO：
// 在garray.h和main中的insertTests中概述接口
// 使用动态内存实现insert
// 实现带有cout语句的析构函数，以查看何时调用它
// 重载赋值运算符以深度复制rhs
// 实现一个复制构造函数，将现有对象深度复制到新对象中
// 为赋值、复制构造函数和析构函数添加cout语句
// 并运行passByValueAndReturnObject以查看它们何时被调用
// 萨拉·克雷比尔，2025年10月22日至24日
#include <iostream>
#include "garray.h"

using namespace std;

void insertTests();//这是一个函数声明，表示insertTests函数将在后面定义
void memoryTests();//这是一个函数声明，表示memoryTests函数将在后面定义
GArray passByValueAndReturnObject(GArray arr);//这是一个函数声明，表示passByValueAndReturnObject函数将在后面定义//PS：GArray是一个类，表示动态整数数组（见h文件）

int main() {
  cout << "main is beginning\n\n";//输出一条消息，表示main函数开始执行
  insertTests();//调用insertTests函数，测试插入功能
	//memoryTests();
  cout << "\nmain is returning\n";//输出一条消息，表示main函数即将结束
	return 0;
}

void insertTests() {
  cout << "insertTests is beginning\n\n";//输出一条消息，表示insertTests函数开始执行

  GArray arr;//创建一个GArray对象arr，初始为空//这是因为我们调用了默认构造函数
  cout << "arr: " << arr << endl;//输出arr的内容，初始为空
  arr.insert(2);//调用insert方法，向arr中插入整数2
  cout << "arr: " << arr << endl;//输出arr的内容，应该包含2
  arr.insert(4);//调用insert方法，向arr中插入整数4
  cout << "arr: " << arr << endl;//输出arr的内容，应该包含2和4
  arr.insert(6);//调用insert方法，向arr中插入整数6
  cout << "arr: " << arr << endl;//输出arr的内容，应该包含2、4和6
  arr.insert(8);//调用insert方法，向arr中插入整数8
  cout << "arr: " << arr << endl;//输出arr的内容，应该包含2、4、6和8

  // TODO: destructor should free memory
  cout << "\ninsertTests is returning\n";//输出一条消息，表示insertTests函数即将结束
}

void memoryTests() {
  cout << "memoryTests is beginning\n\n";//输出一条消息，表示memoryTests函数开始执行
  // set up two GArray objects and cout their contents
  GArray first;//创建一个GArray对象first，初始为空//这是因为我们调用了默认构造函数
  first.insert(1);//调用insert方法，向first中插入整数1
  first.insert(2);//调用insert方法，向first中插入整数2
  GArray second;//创建一个GArray对象second，初始为空//这是因为我们调用了默认构造函数
  second.insert(3);//调用insert方法，向second中插入整数3
  second.insert(4);//调用insert方法，向second中插入整数4
  second.insert(5);//调用insert方法，向second中插入整数5
  cout << "First: " << first << endl;//输出first的内容，应该包含1和2
  cout << "Second: " << second << endl;//输出second的内容，应该包含3、4和5

  // TODO: assignment should enforces give identical objects separate memory
  cout << "\nsecond = first;\n";//输出一条消息，表示将first赋值给second
  second = first; // without overloading =, this makes a shallow copy //没有重载=运算符，这将进行浅拷贝，意思是second和first将共享同一块内存
  cout << "\nFirst: " << first << endl;//输出first的内容//应该包含1和2
  cout << "Second: " << second << endl;//输出second的内容//应该也包含1和2，因为它是first的浅拷贝

  // TODO: copy-constructor should deep copying an existing object's contents
  cout << "\nGArray third(first);\n";//输出一条消息，表示使用first初始化third
  GArray third(first); // calls copy-constructor //调用复制构造函数，创建third作为first的深拷贝//意思是third将有自己独立的内存//另外copy-constructor我们还没写，因此这里实际上是：调用复制构造函数（目前尚未实现，因此仍是浅拷贝）
  cout << "\nFirst: " << first << endl;//输出first的内容，应该包含1和2
  cout << "Second: " << second << endl;//输出second的内容，应该也包含1和2
  cout << "Third: " << third << endl;//输出third的内容，应该也包含1和2，因为它是first的深拷贝

  //知识点回顾：
  //浅拷贝（shallow copy）：当我们将一个对象赋值给另一个对象时，如果只是简单地复制对象的指针或引用，而不复制实际的数据内容，就会发生浅拷贝。这样，两个对象将共享同一块内存区域，修改其中一个对象的数据会影响另一个对象。
  //深拷贝（deep copy）：当我们将一个对象赋值给另一个对象时，如果不仅复制对象的指针或引用，还复制实际的数据内容，就会发生深拷贝。这样，两个对象将拥有各自独立的内存区域，修改其中一个对象的数据不会影响另一个对象。

  // modifying one object shouldn't affect others if dynamic memory isn't shared//中文：如果动态内存没有共享，修改一个对象不应该影响其他对象
  cout << "\nfirst.insert(6);\n";//输出一条消息，表示向first中插入整数6
  first.insert(6); // modify first only //只修改first
  cout << "\nFirst: " << first << endl;//输出first的内容，应该包含1、2和6
  cout << "Second: " << second << endl;// 由于 second 是 first 的浅拷贝，若 insert 复用同一块内存，则输出也会包含 1、2、6（实际效果取决于 insert 实现）
  cout << "Third: " << third << endl;//由于third是first的深拷贝，输出third的内容仍然只包含1和2

  // TODO: note other places that copy-constructor is called automatically
  /*cout << "\nsecond = passByValueAndReturnObject(first);\n";
  second = passByValueAndReturnObject(first);*/

  // TODO: make sure destructor maintains well-formedness of object
  /*second.~GArray(); // not common, but can call destructor explicitly
  cout << "\nsecond.~GArray();\n\nsecond: " << second;
  second.insert(7); 
  cout << "\nsecond.insert(7);\n\nsecond: " << second;*/

  // TODO: implement chained assignment
  /*cout << "\nfirst = second = third;\n";
  first = second = third;
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;
  cout << "Third: " << third << endl;*/

  cout << "\nmemoryTests is returning\n"; 
}

// note: the copy-constructor gets called when parameters are passed by val
// and when objects are returned by value; note destructor calls, too!
GArray passByValueAndReturnObject(GArray arr) { //这是一个函数定义，接受一个GArray对象作为参数，并返回一个GArray对象
  cout << "passByValueAndReturnObject is running\n"; 
  return arr; 
}

