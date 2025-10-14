// 驱动程序源码：用于演示如何使用 Duration 类。
// 程序展示了如何调用 Duration 类中的所有函数，
// 包括 0 参数、1 参数、2 参数构造函数，toString 成员函数，
// 以及重载的 + 运算符；本节的主要新知识点是运算符重载。
// 注意：必须编译实现文件才能运行，例如：
//   $ g++ driver.cpp duration.cpp -std=c++11
// Sara Krehbiel, 2025/10/1-2025/10/3

#include <iostream>
#include "duration.h" // 包含接口文件
using namespace std;

int main() {
  // 周三：构造三个对象并测试 toString 成员函数

  Duration d0;        // 调用 0 参数构造函数（若未定义则用默认构造）//新建了一个 Duration 对象
  Duration d1(1,55);  // 调用 2 参数构造函数
  Duration d2(100);   // 调用 1 参数构造函数
  cout << "D0: " << d0.toString() << endl; // 调用 toString 成员函数
  cout << "D1: " << d1.toString() << endl; 
  cout << "D2: " << d2.toString() << endl;

  // 周五：用多种方式将 Duration 对象相加
  //   0. 简述 const：禁止在函数中修改对象
  //   1. 使用成员函数 sumDuration
  //   2. 使用非成员函数 sumDuration
  //   3. 使用友元函数
  //   4. 将 + 重载为成员函数
  //   5. 将 + 重载为非成员非友元函数
  //   6. 将 + 重载为友元函数
  //   7. 将 += 重载为（学生可自由选择实现）

  //Duration total = d1.sumDuration(d2); // 1 成员函数
  //Duration total = sumDuration(d1,d2); // 2-3 非成员函数（可友元或非友元）
  Duration total = d1+d2; // 4-6 重载的 +（成员/非成员，友元/非友元）
  cout << "Total: " << total.toString() << endl;

  d1+=total; // 7 重载 +=
  cout << "d1+=total;\n";
  cout << "D1: " << d1.toString() << "\nTotal: " << total.toString() << endl;

  return 0;
}
