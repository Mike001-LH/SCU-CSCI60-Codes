// Implementations of linked list functionality declared in node.h
// Sara Krehbiel, 11/10/25

#include "node.h"

ostream& operator <<(ostream& o, const node* n) {
	const node* curr = n;//创建一个指针curr = 传入的节点指针n，用来遍历链表
	while (curr != nullptr) {
		o << curr->data() << " ";// 输出当前节点的数据
		curr = curr->link();// 移动到下一个节点
	}
	return o;
}

void list_insert_head(node*& h, node*& t, int val) {
	node* new_head = new node(val, h); // 调用构造函数创建新节点，val为数据，h为下一个节点地址
	//比方说：假设原链表为 4 -> 2 -> nullptr，h指向4，t指向2，那么new_head就是一个新节点，数据为val，指向4，即 new_head -> 4 -> 2 -> nullptr
	if (t == nullptr) { // 如果列表为空
		t = new_head; // 更新尾节点指向新头节点
	}
	h = new_head; // 更新头指针h指向新节点
}
//举个例子：假设原链表为 4 -> 2 -> nullptr，h指向4，t指向2
//调用list_insert_head(h, t, 6)后，链表变为 6 -> 4 -> 2 -> nullptr，h指向6，t仍指向2

void list_insert_tail(node*& h, node*& t, int val) {//这里*&的意思是传入的是指针的引用，可以修改指针本身的值（引用传参，但传入的是指针）
	node* new_tail = new node(val, nullptr);
	if (h == nullptr) { // 如果列表为空
		h = new_tail; // 更新头节点指向新尾节点
	}
	else {
		t->set_link(new_tail); // 将旧尾节点链接到新尾节点
	}
	t = new_tail; // 更新尾指针t指向新节点
}

size_t list_size(const node* h, const node* t) {
	size_t count = 0;
	if (h == nullptr) {
		return count; // 空链表返回0
	}
	const node* current = h; // 从头节点开始遍历//这里之所以是const node*，是因为函数参数h是const node*，所以current也必须是const node*，以保持类型一致性
	while (current != nullptr) {
		count++; // 计数
		current = current->link(); // 移动到下一个节点
	}
	return count;
}

bool list_search(const node* h, const node* t, int val) {
	if (h == nullptr) {
		return false; // 空链表返回false
	}
	const node* current = h; // 从头节点开始遍历
	while (current != nullptr) {
		if (current->data() == val) {
			return true; // 找到值返回true
		}
		current = current->link(); // 移动到下一个节点
	}
	return false; // 遍历完未找到返回false
}