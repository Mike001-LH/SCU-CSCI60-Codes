#include <iostream>
#include "l_iterator.h"
using namespace std;

template <typename T>
class Bag {
public:
	Bag() : head(nullptr), tail(nullptr) {}
	~Bag() { list_clear(head, tail); }
	Bag(const Bag<T>& other) { list_copy(head, tail, other.head); }

	Bag<T>& operator =(const Bag<T>& other) {
		list_clear(head, tail);
		list_copy(head, tail, other.head);
		return *this;
	}

	typedef L_iterator<T> iterator;//iterator是L_iterator的别名//typedef的作用是给类型起别名
	iterator begin() const { return iterator(head); }//返回一个指向head的迭代器
	iterator end() const { return iterator(nullptr); }

	void insert(const T& value) {
		node<T>* newNode = new node<T>(value, head);
		head = newNode;
		if (tail == nullptr) {
			tail = newNode;
		}
	}
	//remove all values equal to value
	void remove(const T& value) {
		while (head != nullptr && head->data() == value) {
			node<T>* temp = head;//保存head节点
			head = head->link();//head指向下一个节点
			delete temp;//删除原head节点,这样可以用来移除等于value的节点
		}
	}
	int size() const {
		int count = 0;
		for (node<T>* curr = head; curr != nullptr; curr = curr->link()) {
			count++;
		}
		return count;
	}
	bool empty() const {
		return head == nullptr;
	}
	bool contains(const T& value) const {
		for (node<T>* curr = head; curr != nullptr; curr->link()) {
			if (curr->data() == value) {
				return true;
			}
		}
		return false;
	}
	int count(const T& value) const {
		int number = 0;
		for (node<T>* curr = head; curr != nullptr; curr = curr->link()) {
			if (curr->data() == value) {
				number++;
			}
		}
	}
	void clear() {
		list_clear(head, tail);
	}

	void print() const {
		for (node<T>* curr = head; curr != nullptr; curr = curr->link()) {
			cout << curr->data() << " ";
		}
		cout << endl;
	}


private:
	node<T> *head, *tail;
}