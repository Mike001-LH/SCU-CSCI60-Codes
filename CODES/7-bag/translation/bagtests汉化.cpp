// 用于测试静态数组实现的 Bag 类的代码。
// 注意：要运行本程序，必须同时编译实现文件，例如：
//   $ g++ bagtests.cpp bag.cpp -std=c++11
//
// 作者：Sara Krehbiel，2025年10月6日

#include <iostream>
#include <fstream>
#include "bag.h"

using namespace std;

int main() {
	cout << "任何 Bag 的最大容量为 " << Bag::CAPACITY << endl; // static const 示例

	// 构造一个空的 bag 并向其中添加元素
	Bag b1; // 调用默认（无参）构造函数
	size_t n = b1.size();
	cout << "初始 bag 大小：" << n << endl;
	b1.insert(2); 
	b1.insert(3); 
	cout << "插入 2 和 3 后的大小：" << b1.size() << endl;
	cout << "第一个元素是 " << b1[0] << endl;
	cout << "第二个元素是 " << b1[1] << endl;
	cout << "第三个元素是 " << b1[2] << endl; // 未定义内容！（超出 size）
	cout << "第四个元素是 " << b1[3] << endl; // 未定义内容！

	// 使用重载的 << 运算符将 bag 内容输出到控制台
	cout << b1 << endl;

	// 同样的 << 运算符也可用于将 bag 内容输出到文件
	ofstream fout("contents.txt");
	fout << b1 << endl;
	fout.close();


	// 构造一个带初始内容的 bag，测试查询与删除功能
	int arr[5];// = {5, 4, 5, 5, 1}; // 初始化数组
	arr[0]=5; arr[1]=4; arr[2]=5; arr[3]=5; arr[4]=1;
	/*Bag b2(arr,5); // 调用带参数构造函数
	cout << "Bag 2:\n" << b2 << endl; // 使用重载的 << 输出
	cout << "Bag 2 大小: " << b2.size() << endl;

	cout << b2.count(5) << " 个 5\n";

	cout << "尝试删除 4:\n";
	bool erased = b2.erase_one(4);
	cout << (erased?"已":"未") << "改变: " << b2 << endl;
	cout << "尝试删除 -1:\n";
	erased = b2.erase_one(-1);
	cout << (erased?"已":"未") << "改变: " << b2 << endl;
	cout << "删除所有 5:\n";
	cout << b2.erase(5) << " 个被删除: " << b2 << endl;*/

	
	// 测试删除末尾元素的情况
	/*Bag b3; // 调用无参构造函数创建空 bag
	b3.insert(1);
	b3.insert(2);
	b3.insert(3);
	cout << b3 << endl;
	b3.erase_one(3);
	cout << b3 << endl;*/


	// 测试 += 与 + 运算符
	/*cout << "b1: " << b1 << "\nb2: " << b2 << endl;
	b2+=b1; // += 改变左操作数（b2），不会创建新对象
	cout << "b2 在执行 b2+=b1 后: " << b2 << endl;
	// + 运算符创建新对象，但此测试代码直接打印未命名对象
	cout << "b1+b2: " << b1+b2 << endl; */

	return 0;
}
