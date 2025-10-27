// Test file illustrating memory management for classes, specifically GArray.
// We'll implement insert to handle dynamic memory for a single object, and 
// by the end of the week, we'll have understood the need for and implemented
// an overloaded assignment operator, a copy constructor, and a destructor.
//
// WEDNESDAY: 
//   Overview interface in garray.h and insertTests in main
//   Implement insert using dynamic memory
// FRIDAY: 
//   Implement DESTRUCTOR with cout statements to see when it's called
//   Overload ASSIGNMENT operator to deep copy rhs
//   Implement a COPY CONSTRUCTOR to deep copy existing object into new one
// MINI-LECTURE:
//   Run passByValueAndReturnObject to learn when various functions are called
//   Modify assignment operator to allow for chained assigment
//   
// Sara Krehbiel, 10/22/25-10/24/25

#include <iostream>
#include "garray.h"

using namespace std;

void insertTests();//这是插入测试函数的声明
void memoryTests();//这是内存测试函数的声明
GArray passByValueAndReturnObject(GArray arr);//这是一个函数声明，传入一个GArray对象，返回一个GArray对象

int main() {
  cout << "main is beginning\n";
  //insertTests();
	memoryTests();
  cout << "\nmain is returning\n";
	return 0;
}

void insertTests() {//测试insert函数的功能
  cout << "\ninsertTests is beginning\n\n";

  GArray arr;//创建一个GArray对象arr数组
  cout << "arr: " << arr << endl;
  arr.insert(2);
  cout << "arr: " << arr << endl;
  arr.insert(4);
  cout << "arr: " << arr << endl;
  arr.insert(6);
  cout << "arr: " << arr << endl;
  arr.insert(8);
  cout << "arr: " << arr << endl;

  cout << "\ninsertTests is returning\n";
  // NOTE: destructor automatically gets called (should free memory)
}

void memoryTests() {//测试内存管理相关的功能
  cout << "\nmemoryTests is beginning\n\n";
  // set up two GArray objects and cout their contents
  GArray first;//创建第一个GArray对象first数组
  first.insert(1);
  first.insert(2);
  GArray second;//创建第二个GArray对象second数组
  second.insert(3);
  second.insert(4);
  second.insert(5);
  cout << "First: " << first << endl;//输出： First: (First的地址) 1 2
  cout << "Second: " << second << endl;//输出： Second: (Second的地址) 3 4 5

  // assignment should give identical objects separate memory
  cout << "\nsecond = first;\n";//这里我们要测试赋值操作符重载的功能
  second = first; // without overloading =, this makes a shallow copy//如果没有重载=操作符，这里会进行浅拷贝，但我们已经重载了，所以会进行深拷贝
  cout << "\nFirst: " << first << endl;//输出： First: (First的地址) 1 2
  cout << "Second: " << second << endl;//输出： Second: (Second的地址) 1 2

  // copy-constructor should deep copy an existing object's contents
  cout << "\nGArray third(first);\n";//这里我们要测试拷贝构造函数的功能
  GArray third(first); //调用拷贝构造函数，创建third对象，是first的深拷贝 //ps：这里也可以写成 GArray third = first;效果是一样的，因为都是调用拷贝构造函数
  //区别在于，GArray third(first); 是定义了一个GArray类的third对象，然后直接用另一个叫first的对象来初始化新对象。
  //而 GArray third = first; 如果 third 已经存在，那调用的是拷贝赋值运算符（operator=）//如果 third 不存在，那调用的是拷贝构造函数。
  cout << "\nFirst: " << first << endl;//输出： First: (First的地址) 1 2
  cout << "Second: " << second << endl;//输出： Second: (Second的地址) 1 2
  cout << "Third: " << third << endl;//输出： Third: (Third的地址) 1 2

  // modifying one object shouldn't affect others if dynamic memory isn't shared
  cout << "\nfirst.insert(6);\n";
  first.insert(6); //往first数组中插入6
  cout << "\nFirst: " << first << endl;//输出： First: (First的地址) 1 2 6
  cout << "Second: " << second << endl;//输出： Second: (Second的地址) 1 2
  cout << "Third: " << third << endl;//输出： Third: (Third的地址) 1 2

  // note that destructor maintains well-formedness of object
  cout << "\nsecond.~GArray();\n";//调用second对象的析构函数，释放其动态内存
  second.~GArray(); // not common, but can call destructor explicitly//通常不常见，但可以显式调用析构函数
  //PS：调用析构函数的语法是 对象名.~类名(); 这里的类名是GArray
  cout << "\nSecond: " << second;//输出： Second: (0x0) ，因为析构函数将data_设为nullptr，size_设为0
  second.insert(7); //往second数组中插入7 //虽然我们用析构函数释放了second的动态内存，并将其设为nullptr，但insert函数会新建一个新的动态数组然后分配给second并插入7，所以这里是合法的
  cout << "\n\nsecond.insert(7);\n\nFirst: " << first << endl;//输出: First: (First的地址) 1 2 6
  cout << "Second: " << second << endl;//输出: Second: (Second的地址) 7
  cout << "Third: " << third << endl;//输出: Third: (Third的地址) 1 2

  // TODO: note other places that copy-constructor is called automatically
  cout << "\nsecond = passByValueAndReturnObject(first);\n\n";
  second = passByValueAndReturnObject(first);//调用函数，传入first对象，返回一个GArray对象，然后赋值给second对象//这里会调用拷贝构造函数和赋值运算符重载
  cout << "\nFirst: " << first << endl;//输出： First: (First的地址) 1 2 6
  cout << "Second: " << second << endl;//输出： Second: (Second的地址) 1 2 6
  cout << "Third: " << third << endl;//输出： Third: (Third的地址) 1 2

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
//这个函数的作用是传入一个GArray对象arr，输出其内容，并返回该对象，可以用来测试拷贝构造函数和析构函数的调用时机
GArray passByValueAndReturnObject(GArray arr) { //传入一个GArray对象arr，返回一个GArray对象
  cout << "passByValueAndReturnObject is running\n"; //调试信息，表示函数正在运行
  cout << "arr: " << arr << endl;//输出传入的arr对象的内容
  return arr; //返回传入的arr对象，这里会调用拷贝构造函数创建一个新的GArray对象作为返回值
}

