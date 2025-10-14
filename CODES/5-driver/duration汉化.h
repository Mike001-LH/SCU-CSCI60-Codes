// …（说明：Duration 是“小时+分钟”的时长；会支持相加、友元、运算符重载等）

#ifndef DURATION_H   // 头文件保护宏：防重复包含：若未定义 DURATION_H，则继续
#define DURATION_H	 // 定义 DURATION_H，防止被重复包含造成重定义

#include <iostream>  // 课堂里用这个；更规范应当 #include <string>
using namespace std;

// 类定义：只“声明”长什么样（字段 & 函数原型），通常不写实现体
class Duration {
public:
    // 构造函数（内联 + 初始化列表）
    Duration() : mins(0) { } 
    Duration(int mins) : mins(mins) { }
    Duration(int hrs, int mins) : mins(hrs*60+mins) { }

    // 成员函数“声明”（这里只说有这个函数，具体实现放 .cpp 里）
    string toString();

    // 预留：友元函数的声明（现在还没写）

private:
    int mins; // 私有字段：用分钟数存储时长
};

// 预留：与类相关的“非成员、非友元”函数的声明

#endif				 // 头文件保护宏的结束标记
