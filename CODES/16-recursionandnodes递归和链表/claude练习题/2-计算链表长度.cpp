/*
问题 2: 计算链表长度
编写一个递归函数 int length(node* head)，返回链表的长度。
示例：1->2->3->nullptr 返回 3
*/
#include <iostream>
using namespace std;

class Node {
public:
	// constructors
	Node(int d = 0, Node* l = nullptr) : data_(d), link_(l) {}//这里，如果d和l没有提供参数，默认data_为0，link_为nullptr
	// accessors
	int data() const { return data_; }
	Node* link() const { return link_; }
	// mutators for data_ and link_
	void set_data(int val) { data_ = val; }
	void set_link(Node* new_link) { link_ = new_link; }
private:
	int data_;//data_是一个整数，存储节点的数据
	Node* link_;// link_是一个指向下一个节点的指针
};

int length(Node* head) {
	if (head == nullptr) {
		return 0; // base case: empty list has length 0
	}
	return 1 + length(head->link()); // recursive case: 1 + length of the rest of the list
}