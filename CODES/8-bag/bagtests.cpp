// Test code while completing the static array implementation of Bag.
//
// Note: You must compile this and the implementation file to run this, e.g.,
//   $ g++ bagtests.cpp bag.cpp -std=c++11
//
// Sara Krehbiel, 10/6/25

#include <iostream>// for cout, endl
#include <fstream>// for ofstream
#include "bag.h"// include the interface for Bag

using namespace std;

int main() {
	cout << "Any Bag has capacity " << Bag::CAPACITY << endl; // static const CAPACITY 是 public static const 类常量（类级别，所有对象共享），可直接通过 Bag::CAPACITY 访问，值是 1000

	// construct an empty bag and add to it

	Bag b1; // default/0-arg constructor 构造一个叫b1的空bag //b1是一个空bag
	size_t n = b1.size(); //意思是调用b1的size()方法，返回当前bag中int的数量，赋值给n // n应该是0
	cout << "Initial bag size: " << n << endl;//输出初始bag的大小，应该是0
	b1.insert(2); // insert 2 into the bag
	b1.insert(3); // insert 3 into the bag
	cout << "Size after inserting 2 and 3: " << b1.size() << endl; // should be 2 //输出插入2和3后的bag大小，应该是2
	cout << "The first entry is " << b1[0] << endl;// should be 2 //输出bag中第一个元素，应该是2
	cout << "The next entry is " << b1[1] << endl;// should be 3 //输出bag中第二个元素，应该是3
	cout << "The next entry is " << b1[2] << endl; // undefined content!//输出bag中第三个元素，应该是未定义内容，因为只插入了两个元素
	cout << "The next entry is " << b1[3] << endl; // undefined content! //输出bag中第四个元素，应该是未定义内容，因为只插入了两个元素

	// use << to print contents of bag to console
	cout << b1 << endl;//由于重载了<<运算符，所以可以直接用cout打印bag的内容

	// use the same << to print contents of bag to file
	ofstream fout("contents.txt");//创建一个ofstream对象fout，打开一个名为contents.txt的文件
	fout << b1 << endl;//将bag的内容写入文件
	fout.close();//关闭文件，防止数据丢失


	// construct a bag initialized with some contents, query, and erase from it

	int arr[5];// = {5, 4, 5, 5, 1}; // initialize an array
	arr[0] = 5; arr[1] = 4; arr[2] = 5; arr[3] = 5; arr[4] = 1;//给数组赋值
	Bag b2(arr, 5); // 2-arg constructor //调用2参构造器，构造一个叫b2的bag，内容是arr数组的前5个元素
	cout << "Bag 2:\n" << b2 << endl; // use of overloaded insertion //输出bag2的内容，例如"5 4 5 5 1 " //输出结果： Bag 2: 5 4 5 5 1
	cout << "Bag 2 size: " << b2.size() << endl;//输出bag2的大小，应该是5//输出结果： Bag 2 size: 5

	cout << b2.count(5) << " 5s\n";// should be 3 //输出bag2中5出现的次数，应该是3 //输出结果： 3 5s

	cout << "Attempting to erase 4:\n";
	bool erased = b2.erase_one(4);// should be true //调用erase_one方法，尝试删除bag2中第一个出现的4，返回值赋给erased，应该是true
	cout << (erased ? "C" : "Not c") << "hanged: " << b2 << endl;//运用三目运算符，如果erased为true，输出"Changed: "，否则输出"Not changed: "，然后输出bag2的内容 //输出结果： Changed: 5 5 5 1
	cout << "Attempting to erase -1:\n";
	erased = b2.erase_one(-1);// should be false //尝试删除bag2中第一个出现的-1，由于没有-1，返回值赋给erased，应该是false
	cout << (erased ? "C" : "Not c") << "hanged: " << b2 << endl;//输出： Not changed: 5 5 5 1
	cout << "Erasing all 5s:\n";
	cout << b2.erase(5) << " erased: " << b2 << endl;//调用erase方法，删除bag2中所有的5，返回删除的数量，应该是3，然后输出bag2的内容 //输出结果： 3 erased: 1 //也就是说bag2在删掉4和5之后，内容只有"1 "了
	
	// test code to make sure erasing at end of bag works

	Bag b3; // call 0-arg constructor for an empty bag //构造一个叫b3的空bag
	b3.insert(1);// insert 1 into the bag
	b3.insert(2);// insert 2 into the bag
	b3.insert(3);// insert 3 into the bag
	cout << b3 << endl; //输出bag3，应该是"1 2 3 "
	b3.erase_one(3);//删除bag3中第一个出现的3
	cout << b3 << endl;//输出bag3，应该是"1 2 "

	// test code for += and +

	cout << "b1: " << b1 << "\nb2: " << b2 << endl;//输出bag1和bag2的内容，应该是"2 3 "和"1 "
	b2 += b1; // += mutates left operand (b2) without creating a new object//调用+=运算符，将bag1的内容添加到bag2中，bag2变为"1 2 3 "
	cout << "b2, after b2+=b1: " << b2 << endl;//输出bag2的内容，应该是"1 2 3 "
	// + creates new object, but this test code inserts it without naming
	cout << "b1+b2: " << b1 + b2 << endl; //调用+运算符，创建一个新的bag对象，内容是bag1和bag2的内容的结合，然后输出这个新bag的内容，应该是"2 3 1 2 3 "

	return 0;
}

