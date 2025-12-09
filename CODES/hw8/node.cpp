// Implementation file for CSCI 60 Homework 8; due due Wednesday 11/19/25
// Write your name and list collaborators here

#include "node.h"

// overloaded << for debugging (plus a bonus example of recursion!)
ostream& operator <<(ostream& out, const node * head) {
  if (head==nullptr) return out; // base case: empty list
  out << head->data() << " "; // non-recursively output the data of the head
  return (out << head->link()); // recursively output everything else
}

// stubs for HW8 functions
// write a function comment for each, plus more comments as appropriate

int f1(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return f1(n - 2) + (n - 1);
	}
}
  
void f2(int * a, int first, int last) {
	if (first >= last) {
		return;
	}
	else {
		int temp = a[first];
		a[first] = a[last];
		a[last] = temp;
		f2(a, first + 1, last - 1);
	}
}

void f3(node *& head, node *& tail, int * a, int n) {
	if (n <= 0) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		// recursive call to construct the linked list of the rest of the array(n-1 elements)
		f3(head, tail, a, n - 1);//a是数组，n-1是数组长度
		//create a new node for the n-1 element of the array(index n-1)
		node* newNode = new node;//创建一个新节点
		newNode->set_data(a[n - 1]);//设置新节点的数据为数组的第n-1个元素（也就是最后一个元素）
		newNode->set_link(nullptr);//新节点的链接指向nullptr，因为它是最后一个节点
		//if this is the first node
		if (head == nullptr) {
			head = newNode;
		}
		else {
			tail->set_link(newNode);
		}
		tail = newNode;
	}
}

void f4(node *& head, node *& tail) {
	if (head == nullptr) {
		tail = nullptr;
		return;
	}
	else {
		node* temp = head;//用temp保存head指针，防止丢失
		head = head->link();//head指向下一个节点
		delete temp;
		f4(head, tail);
	}
}
