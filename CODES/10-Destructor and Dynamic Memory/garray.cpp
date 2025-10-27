// Implementation of GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/22/25

#include "garray.h"

// TODO: replace these stub implementations with correct ones

void GArray::insert(int val) {//这个函数用于在动态数组中插入一个新的整数值
	// 该函数用于在动态数组末尾插入一个整数：
	// 1️ 重新分配一块新内存（长度为 size_ + 1）
	// 2️ 拷贝旧数据到新数组
	// 3️ 把 val 添加到最后一位
	// 4️ 释放旧数组，更新指针和 size_
} 

ostream& operator <<(ostream& out, const GArray& a) {//重载输出运算符。返回 ostream&（引用），用于链式输出：cout << a << b;
  return out; // 输出格式示例：[1, 2, 3]
}