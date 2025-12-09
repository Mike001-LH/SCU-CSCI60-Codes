#include <iostream>
using namespace std;

template <typename T>
class node {
public:
	node(T d, node<T>* l = nullptr) : data_(d), link_(l) {}
	T data() const { return data_; }
	node<T>* link() const { return link_; }
	void set_data(T d) { data_ = d; }
	void set_link(node<T>* l) { link_ = l; }
private:
	T data_;
	node<T>* link_;
};

template <typename T>
void list_clear(node<T>* h, node<T>* t) {//h->[1]->[2]->...->[n]->t//head一步一步往前推进
	//BC
	if (h == nullptr) {
		t = nullptr;
		return;
	}
	//1 step + recursion
	node<T>* deletenode = h;
	h = h->link();
	delete deletenode;
	list_clear(h, t);
}

template <typename T>
void list_copy(node<T>*& lhead, node<T>*& ltail, const node<T>* rhead) {//被复制的是rhead，复制到lhead和ltail
	if (rhead == nullptr) return;//如果被复制的链表为空，直接返回
	if (ltail != nullptr) lhead = ltail = new node<T>(rhead->data(), nullptr);//如果ltail为空，说明是第一次拷贝，需要创建头节点
	else {
		ltail->set_link(new node<T>(rhead->data(),nullptr));
		ltail = ltail->link();
	}
	list_copy(lhead, ltail, rhead->link());
}