#ifndef PRACTISE_H
#define PRACTISE_H

#include <iostream>
using namespace std;
//任务1：建立一个包含5个整数的链表，然后把它们都打印出来
class node {
public:
	//constructors
	node() : data_(0), link_(nullptr) {}
	node(int initdata, node* initlink) : data_(initdata), link_(initlink) {}//这个构造函数用于初始化节点的数据和链接
	//accessors
	int data() const { return data_; }
	node* link() const { return link_; }
	//mutators
	void set_data(int newdata) { data_ = newdata; }
	void set_link(node* newlink) { link_ = newlink; }
private:
	int data_;
	node* link_;
};
//任务2：写一个函数，计算链表里有多少个数
size_t count_nodes(const node* head);
//任务3：写一个函数，在链表里查找一个数，找到返回true，找不到返回false
bool find_value(const node* head, int target);
//任务4: 写一个函数，在链表的最前面插入一个新数字
void insert_at_front(node*& head, node*& tail, int value);
//任务5: 写一个函数，在链表的最后面加入一个新数字
void append_to_end(node*& head, node*& tail, int value);





#endif // PRACTISE_H