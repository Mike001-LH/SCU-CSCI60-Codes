// …（说明：这是一段演示如何使用 Duration 类的主程序，并给出编译命令）
#include <iostream>
#include "duration.h" // 只需要包含头文件（接口）
using namespace std;

int main() {
  // 1) 创建三个对象，分别触发不同构造函数
  Duration d0;        // 0 参构造：把 mins 设为 0
  Duration d1(1,55);  // 2 参构造：把 mins 设为 1*60+55 = 115
  Duration d2(100);   // 1 参构造：把 mins 设为 100

  // 2) 调用成员函数 toString()，把对象转成可打印的字符串
  cout << "D0: " << d0.toString() << endl;
  cout << "D1: " << d1.toString() << endl;
  cout << "D2: " << d2.toString() << endl;

  // 3) TODO：后续会演示把两个 Duration 相加的多种写法
  //   - 成员函数、非成员函数、友元函数、运算符重载等等
  //   这里先留空，等实现了再取消注释测试

  return 0;
}
