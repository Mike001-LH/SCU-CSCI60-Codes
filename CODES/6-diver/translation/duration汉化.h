// Duration 类的接口文件（头文件）。
// 一个 Duration 对象表示一段时间，用小时和分钟显示。
// Duration 对象可以相加，我们会用多种方式实现。
// 新知识点包括运算符重载、友元函数，以及 const（将于下节课深入讨论）。
// 注意：sumDuration 可以同时作为成员函数和非成员函数重载，
// 但 + 不行，因为调用方式不同。
// Sara Krehbiel, 2025/10/1-2025/10/3

#ifndef DURATION_H // 头文件保护（宏定义防止重复包含）
#define DURATION_H

#include <iostream>
using namespace std;

// 类定义：声明所有成员变量，也可以有内联函数定义
class Duration {
public:
	// 构造函数（使用初始化列表定义）
	/*在 : mins(...) 这种“初始化列表”语法中
	冒号左边的 mins → 是类里的 private 成员变量
	括号里的内容 (...) → 是你传进来的参数、表达式，或局部计算结果*/
	Duration() : mins(0) { } //初始化列表，把内部private的 mins 设为 0
	//第一个 mins（左边的）: mins(...) 里的。是对象自己的 private 成员//第二个 mins（右边的）括号 (int mins) 的参数。是传进来的局部变量
	Duration(int mins) : mins(mins) { } //从左到右3个mins分别是driver.cpp里面的100，duration.h这里的private mins，以及driver.cpp里面的100
	Duration(int hrs, int mins) : mins(hrs*60+mins) { } //

	// 成员函数声明

	// 把 Duration 对象格式化为字符串
	string toString() const; // const 表示禁止修改调用对象

	// 1 sumDuration 声明为成员函数
	Duration sumDuration(Duration rhs); // 不要声明调用对象（即左操作数）

	// 4 声明 + 为成员函数
	Duration operator +(Duration rhs); 

	// 7 内联的 += 重载，直接用内置 += 修改调用对象
	void operator +=(Duration rhs) { mins += rhs.mins; }

	// 一个仅供“非成员非友元函数”使用的内联访问器
	int getMins() { return mins; } 

	// 友元函数声明
	friend Duration sumDuration(Duration lhs, Duration rhs); // 3
	//friend Duration operator +(Duration lhs, Duration rhs); // 6
private:
	int mins; //来自 class Duration 的 private 成员，这是对象内部的变量
};

// 与本类相关的非成员非友元函数声明
//Duration sumDuration(Duration lhs, Duration rhs); // 2
//Duration operator +(Duration lhs, Duration rhs); // 5

#endif
