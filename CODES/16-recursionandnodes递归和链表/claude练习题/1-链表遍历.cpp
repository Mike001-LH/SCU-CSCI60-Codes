/*
问题 1: 链表遍历（递归 vs 迭代）
给定一个链表 1->2->3->4->5，编写两个函数：

*printListIterative(node head)**：用while循环打印链表
*printListRecursive(node head)**：用递归打印链表

两个函数都应该输出：1->2->3->4->5
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

void nodeCode() {
	// build a list 1->2->3->4->5 from the back to the front
	Node* head = new Node(5, nullptr);
	head = new Node(4, head);
	head = new Node(3, head);
	head = new Node(2, head);
	head = new Node(1, head);
	cout << "Iterative print: ";
	printListIterative(head);
	cout << "Recursive print: ";
	printListRecursive(head);
}

void printListIterative(Node* head) {
	Node* current = head;//先新建一个指针current，指向head
	while (current != nullptr) {
		cout << current->data();//打印current指向的节点的数据
		if (current->link() != nullptr) {
			cout << "->";
		}
		current = current->link();//将current指向下一个节点
	}
	cout << endl;
}

void printListRecursive(Node* head) {
	if (head == nullptr) {
		cout << endl;
		return;
	}
	cout << head->data();//打印当前节点的数据
	if (head->link() != nullptr) {
		cout << "->";
	}
	printListRecursive(head->link());//递归调用，打印下一个节点
}
