// 静态数组实现的 Bag（袋子）数据结构的函数定义
// 作者：Sara Krehbiel，日期：2025年10月6日

#include "bag.h"

// TODO: 使用构造函数委托（constructor delegation）和 insert 来实现带两个参数的构造函数

// 将 bag 中的每个元素（以空格分隔）插入到输出流 o 中，并返回该输出流
ostream& operator <<(ostream& o, const Bag& b) {
	size_t n = b.size();
	for (size_t i=0; i<n; i++) {
		o << b[i] << " ";
	}
	return o;
}

// TODO: 重载 += 和 + 运算符

// TODO: 逐步分析下面 erase_one 函数的代码逻辑

// 在数据中查找第一个 val，并将其后的所有值向前移动一格
bool Bag::erase_one(int val) {
	bool found = false;
	for (size_t i=0; i<size_; i++) {
		// 当首次找到 val 时，将 found 置为 true，并使 size 减 1
		if (!found && data_[i]==val) {
			found = true;
			size_--;
		}
		// 如果已经找到 val，就用下一个元素覆盖当前元素，实现“向前移位”
		if (found) data_[i] = data_[i+1];
	}
	return found;
}

// TODO: 实现 erase 和 count 函数
