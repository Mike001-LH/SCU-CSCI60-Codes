// garray.h
// Lesson 10 — Destructor & Dynamic Memory in Classes (Rule of Three)
// 预习版：包含析构、拷贝构造、赋值运算符、插入、输出

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>
#include <cstddef>

using std::ostream;
using std::cout;
using std::endl;

class GArray {
public:
	// 0-arg ctor: 空数组；size_=0, data_=nullptr
	GArray() : size_(0), data_(nullptr) {}

	// Rule of Three
	~GArray();                               // 析构：释放堆数组					//Destructor — 释放资源
	GArray(const GArray& other);             // 拷贝构造：深拷贝					//Copy Constructor — 深拷贝
	GArray& operator=(const GArray& rhs);    // 赋值：深拷贝 + 自赋值防御 + 链式	//Copy Assignment Operator — 深拷贝赋值

	// 基本行为
	void insert(int val);                    // 以“新开更大数组”的方式尾插
	size_t length() const { return size_; }  // 元素个数
	int operator[](size_t i) const { return data_[i]; } // 只读下标（演示用）
	int* address() const { return data_; }   // 返回底层数组地址（便于观察）

	// 语义别名（可选）：与 vector::push_back 类似
	void push_back(int val) { insert(val); }

private:
	size_t size_; // 已用长度
	int* data_; // 指向 size_ 个 int 的堆数组；size_==0 时应为 nullptr

	// INVARIANT:
	//  - 若 size_ > 0，则 data_ 指向堆上大小为 size_ 的 int 数组
	//  - 若 size_ == 0，则 data_ == nullptr
};

// 非成员：输出“地址 + 内容”，用于观察是否共享同一块堆内存
ostream& operator<<(ostream& out, const GArray& a);

#endif // GARRAY_H
