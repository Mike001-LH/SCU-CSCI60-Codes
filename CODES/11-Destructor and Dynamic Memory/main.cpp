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

#include <iostream>
#include "garray.h"

using namespace std;

//这三行代码是函数声明，告诉编译器这些函数将在后面定义//此外这三行代码是测试函数，分别用于测试插入函数、内存管理函数，以及传递和返回GArray对象的函数
void insertTests();//测试插入函数，先函数声明
void memoryTests();//测试内存管理函数，先函数声明
GArray passByValueAndReturnObject(GArray arr);//这一行代码意思是声明了一个名为passByValueAndReturnObject的函数，该函数接受一个GArray类型的参数arr，并返回一个GArray类型的对象。

int main() {
  cout << "main is beginning\n\n";//输出提示信息，表示main函数开始执行
  insertTests();//调用测试插入函数，实现插入功能的测试
	//memoryTests();
  cout << "\nmain is returning\n";//输出提示信息，表示main函数即将结束执行
  return 0;//返回0，表示程序正常结束
}

//这里代码里面全部的数组都是动态数组
void insertTests() {//测试插入函数，实现函数定义//作用是测试GArray类的insert函数的功能
  cout << "insertTests is beginning\n\n";

  GArray arr;//创建一个GArray对象arr，利用GArray里面的0参构造器初始化为空数组
  cout << "arr: " << arr << endl;//输出arr对象的初始状态，调用重载的<<运算符，显示数组的地址和内容//输出结果：arr: (0x55f8c3e2eeb0)//这里之所以输出地址，是因为重载的<<运算符中的代码声明是先输出地址，然后再输出数组内容，而此时数组为空，所以只显示地址
  arr.insert(2);//调用arr对象的insert函数，插入值2到数组中
  cout << "arr: " << arr << endl;//输出arr对象的状态，显示插入值2后的数组内容//输出结果：arr: (0x55f8c3e2eeb0) 2
  arr.insert(4);//插入值4到数组中
  cout << "arr: " << arr << endl;//输出arr对象的状态，显示插入值4后的数组内容//输出结果：arr: (0x55f8c3e2eeb0) 2 4
  arr.insert(6);//插入值6到数组中
  cout << "arr: " << arr << endl;//输出arr对象的状态，显示插入值6后的数组内容//输出结果：arr: (0x55f8c3e2eeb0) 2 4 6
  arr.insert(8);//插入值8到数组中
  cout << "arr: " << arr << endl;//输出arr对象的状态，显示插入值8后的数组内容//输出结果：arr: (0x55f8c3e2eeb0) 2 4 6 8

  arr.~GArray();//显式调用arr对象的析构函数(destructor)，释放动态内存//由于是测试函数，所以要调用析构函数来释放内存，防止内存泄漏

  // TODO: destructor should free memory
  cout << "\ninsertTests is returning\n";//输出提示信息，表示insertTests函数即将结束执行
}

void memoryTests() {//测试内存管理函数，实现函数定义
  cout << "memoryTests is beginning\n\n";
  // set up two GArray objects and cout their contents
  GArray first;//创建第一个GArray对象first数组
  first.insert(1);//插入值1到first数组中
  first.insert(2);//插入值2到first数组中
  GArray second;//创建第二个GArray对象second数组
  second.insert(3);//插入值3到second数组中
  second.insert(4);//插入值4到second数组中
  second.insert(5);//插入值5到second数组中
  cout << "First: " << first << endl;//输出first数组的内容//输出结果：First: (0x55f8c3e2eeb0) 1 2
  cout << "Second: " << second << endl;//输出second数组的内容//输出结果：Second: (0x55f8c3e2ef0) 3 4 5

  // TODO: assignment should enforces give identical objects separate memory
  cout << "\nsecond = first;\n";//测试赋值操作符重载
  second = first; // without overloading =, this makes a shallow copy//如果没有重载赋值操作符=，这将进行浅拷贝，意思是second和first将共享同一块动态内存
  cout << "\nFirst: " << first << endl;//输出first数组的内容//输出结果：First: (0x55f8c3e2eeb0) 1 2
  cout << "Second: " << second << endl;//输出second数组的内容//输出结果：Second: (0x55f8c3e2eeb0) 1 2
  /*memory diagram示意图：
    stack:               heap:
	first.data_  ──┐
				   │
				   ├──> [1][2]
				   │
	second.data_ ──┘
  */

  // TODO: copy-constructor should deep copying an existing object's contents//拷贝构造函数应该深拷贝一个已有对象的内容
  cout << "\nGArray third(first);\n";//测试拷贝构造函数
  GArray third(first); // calls copy-constructor to make deep copy of first into new object third//调用拷贝构造函数，将first对象的内容深拷贝到新对象third中
  cout << "\nFirst: " << first << endl;//输出first数组的内容//输出结果：First: (0x55f8c3e2eeb0) 1 2
  cout << "Second: " << second << endl;//输出second数组的内容//输出结果：Second: (0x55f8c3e2eeb0) 1 2
  cout << "Third: " << third << endl;//输出third数组的内容//输出结果：Third: (0x55f8c3e2f30) 1 2
  // memory diagram示意图：
  /*
    stack:               heap:
	first.data_  ──┐
				   │
				   ├──> [1][2]
				   │       │
	second.data_ ──┘       │
					       ↓
	third.data_ ──────> [1][2]
  */
  //知识点讲解：
  //copy-constructor(拷贝构造函数)的作用是创建一个新对象，并将已有对象的内容深拷贝到新对象中，确保两个对象拥有独立的动态内存空间，从而避免共享内存带来的问题。
  //在上面的示意图中，first和second对象共享同一块动态内存，而third对象拥有自己独立的动态内存空间，存储了first对象的内容。
  //copy-constructor的实现逻辑在于：创建一个新的动态数组，并逐个复制已有对象的元素到新数组中，确保新对象拥有独立的内存空间，避免把地址给复制过去。
  // 语法示例：
  // GArray::GArray(const GArray& other) { //拷贝构造函数定义，传入一个已有对象other的常量引用
  //    size_ = other.size_; //将新对象的size_设置为other对象的size_
  //    if (size_ > 0) { //如果size_大于0，表示有动态数组需要拷贝
  //        data_ = new int[size_]; //在堆上分配新的动态数组内存
  //        for (size_t i = 0; i < size_; i++) { //逐个复制other对象的动态数组内容到新对象的动态数组中
  //            data_[i] = other.data_[i]; //深拷贝每个元素，确保新对象拥有独立的内存空间，避免把地址给复制过去
  //        }
  //    } else {//如果size_为0，表示没有动态数组
  //        data_ = nullptr;//将data_指针设置为nullptr，表示没有动态数组
  //    }
  // }
  //
  //而我们这里代码中的GArray third(first);语句实际上就是调用了上面定义的拷贝构造函数，创建了一个新的third对象，并将first对象的内容深拷贝到third对象中。
  //然而很扯淡的是，我们并没有在garray.cpp中实现这个拷贝构造函数，所以实际上GArray third(first);这段代码是有问题的，运行时会出现未定义行为（undefined behavior），可能会导致程序崩溃或者输出错误的结果。

  // modifying one object shouldn't affect others if dynamic memory isn't shared//修改其中一个对象不应该影响其他对象，如果它们没有共享动态内存
  cout << "\nfirst.insert(6);\n";//测试插入操作，修改first对象
  first.insert(6); //插入值6到first数组中
  cout << "\nFirst: " << first << endl;//输出first数组的内容//输出结果：First: (0x55f8c3e2eeb0) 1 2 6
  cout << "Second: " << second << endl;//输出second数组的内容//输出结果：Second: (0x55f8c3e2eeb0) 1 2 6
  cout << "Third: " << third << endl;//输出third数组的内容//输出结果：Third: (0x55f8c3e2f30) 1 2 
  //由于second和first共享动态内存，所以second也受影响，而third没有受影响，是因为third通过神拷贝有自己独立的动态内存

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

  //上面这些注释掉的代码是为了测试传递和返回GArray对象的函数，以及显式调用析构函数和链式赋值操作，但由于目前还没有实现相关功能，所以暂时注释掉了。
  cout << "\nmemoryTests is returning\n"; 
}

// note: the copy-constructor gets called when parameters are passed by val
// and when objects are returned by value; note destructor calls, too!
GArray passByValueAndReturnObject(GArray arr) { //实现函数定义,传入一个GArray对象arr，返回一个GArray对象
  cout << "passByValueAndReturnObject is running\n"; //输出提示信息，表示函数正在运行
  return arr; //返回传入的GArray对象arr
}

