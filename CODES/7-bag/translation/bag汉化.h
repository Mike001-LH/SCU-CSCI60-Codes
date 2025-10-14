// Bag 容器类的完整接口声明，使用静态数组实现，最多可存储 CAPACITY 个整数（可重复）。
// 作者：Sara Krehbiel，经 Natalie Linnell 与 Nicholas Tran 修订，2025年10月6日

#ifndef BAG_H
#define BAG_H

#include <cstdlib>
using std::size_t; 

#include <iostream>
using std::ostream; // 允许直接使用 ostream，而不是 std::ostream
// 注意：在类定义中使用 “using namespace std” 会造成命名空间污染（namespace pollution）

class Bag {
public:
  static const size_t CAPACITY = 1000; // static 表示不是成员变量（属于类而非实例）

  // 构造函数（后置条件：保证 bag 结构合理）
  Bag() : size_(0) { }                // 默认构造函数，初始为空
  Bag(int a[], size_t n);             // 带参数构造函数

  // 访问器（前后条件：结构保持良好）
  size_t size() const { return size_; }             // 返回当前元素数量
  int operator [](size_t index) const { return data_[index]; } // 访问特定下标元素

  size_t count(int val) const; // 返回 val 在 data_ 中出现的次数

  // 修改器（mutators）
  // 前置条件：结构合理；后置条件视操作不同而不同

  // 后置条件：
  // 若 bag 仍有空间，则将 val 插入到 data_ 的下一个可用位置，并令 size_++
  // 否则不做任何改动
  void insert(int val) { if (size_<CAPACITY) data_[size_++] = val; } // TODO: 可写成内联定义

  // 后置条件：
  // 如果 data_ 中原本包含 val，则删除其第一个副本（覆盖法），
  // 并使 size_ 减 1，同时返回 true；否则返回 false
  bool erase_one(int val);

  // 后置条件：
  // 删除 data_ 中所有的 val，并返回被删除的数量
  size_t erase(int val);

  // TODO: 决定 += 运算符的函数签名
  // 后置条件：
  // 将 rhs 的内容按顺序插入调用对象中，rhs 自身保持不变
 
private:
	int data_[CAPACITY]; // 存放元素的静态数组
	size_t size_;        // 当前元素数量
  // 不变式（INVARIANT）：
  // data_[0] ~ data_[size_-1] 存放已插入的整数，且 size_ <= CAPACITY
};

// 后置条件：返回包含 lhs 和 rhs 内容（按顺序排列）的新 bag，lhs 与 rhs 均保持不变
Bag operator +(const Bag& lhs, const Bag& rhs);

// TODO: 讨论另一种非成员 += 实现的函数签名

// 后置条件：将 b.data_ 中的真实内容按顺序插入到输出流 o 中
ostream& operator <<(ostream& o, const Bag& b);

#endif
