/*
问题 3: 求链表所有元素之和
编写一个递归函数 int sumList(node* head)，返回链表中所有数据的和。
示例：2->4->6->nullptr 返回 12
*/
#include <iostream>
using namespace std;
class Node {
public:
	// constructors
	Node(int d = 0, Node* l = nullptr) : data_(d), link_(l) {}
	// accessors
	int data() const { return data_; }
	Node* link() const { return link_; }
	// mutators for data_ and link_
	void set_data(int val) { data_ = val; }
	void set_link(Node* new_link) { link_ = new_link; }
private:
	int data_;
	Node* link_;
};

int sumList(Node* head) {
	if (head == nullptr) {
		return 0; // base case: empty list has sum 0
	}
	return head->data() + sumList(head->link()); // recursive case: current node's data + sum of the rest of the list
}