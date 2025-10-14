// CSCI 60 作业 2 测试程序
// 功能：创建 Histogram 对象并测试所有函数
// 作者：你的名字  日期：2025/10/8

#include <iostream>
#include "histogram.h"
using namespace std;

int main() {
    // 创建一个 Histogram 对象，从文件 data.txt 读取数据
    Histogram h("data.txt");

    // 打印基本统计结果
    cout << "总计数 Total count = " << h.size() << endl;
    cout << "最小值 Min = " << h.min() << endl;
    cout << "最大值 Max = " << h.max() << endl;
    cout << "众数 Mode = " << h.mode() << endl;
    cout << "中位数 Median = " << h.median() << endl;
    cout << "平均数 Mean = " << h.mean() << endl;
    cout << "方差 Variance = " << h.variance() << endl;

    // 打印整个直方图
    cout << "\n直方图 Histogram:\n" << h;

    return 0;
}

/*
运行结果示例：
Total count = 8
Min = 1
Max = 9
Mode = 2
Median = 2
Mean = 3
Variance = 5.5

Histogram:
1: *
2: ****
3: **
9: *
*/
