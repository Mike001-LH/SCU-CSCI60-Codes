// CSCI 60 作业 2 接口文件（Histogram 类定义）
// 请勿修改或上传此文件至提交平台
// Sara Krehbiel, 2025/10/2

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <fstream>
using namespace std;

/*
Histogram 类用于存储和处理一组整数（0~MAX）的频率分布。
它支持：
- 从文件读取数据
- 获取最小值、最大值、众数、中位数、平均数、方差
- 使用 += 合并两个直方图
- 使用 [] 查询某个值出现的次数
- 使用 << 输出整个直方图
*/

class Histogram {
public:
  static const size_t MAX = 100; // 可存储的最大数值

  Histogram(string filename); // 从文件读取整数并构建直方图
  Histogram();                // 创建一个空直方图（所有频率为0）

  // 基本统计函数
  size_t size() const;    // 返回总样本个数
  size_t min() const;     // 返回出现次数>0的最小值
  size_t max() const;     // 返回出现次数>0的最大值
  size_t mode() const;    // 返回众数（出现次数最多的值）
  size_t median() const;  // 返回中位数（奇数为正中，偶数为两中间值平均）
  double mean() const;    // 返回平均值
  double variance() const;// 返回方差

  // 运算符重载
  void operator +=(const Histogram& rhs); // 合并两个直方图（逐项相加）
  size_t operator [](size_t val) const;   // 查询某个值出现的次数

private:
  size_t counts[MAX + 1]; // 频率数组：counts[i] 表示值 i 出现的次数
};

// 非成员函数：打印直方图（例如 cout << h;）
ostream& operator <<(ostream& out, const Histogram& h);

#endif
