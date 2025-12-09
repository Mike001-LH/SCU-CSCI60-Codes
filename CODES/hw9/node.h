#include<iostream>
using namespace std;

template <typename T>
class node {
public:
	node(T data, node<T>* link = nullptr) : data_(data), link_(link) {}
	const T& data() const { return data_; }  // ✅ 改为 const T& 返回常量引用
	node<T>* link() { return link_; }
	void set_link(node<T>* newlink) { link_ = newlink; }
	node<T>* get_link() const { return link_; }
private:
	T data_;
	node<T>* link_;
};

template <typename T>
class LinkedListIterator;   // 前向声明

template <typename T>
class LinkedList {
public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	void push_front(const T& value) {
		node<T>* newNode = new node<T>(value, head);
		head = newNode;
		if (tail == nullptr) {
			tail = newNode;
		}
	}
	void push_back(const T& value) {
		node<T>* newNode = new node<T>(value, nullptr);
		if (tail != nullptr) {
			tail->set_link(newNode);
		}
		tail = newNode;
		if (head == nullptr) {
			head = newNode;
		}
	}
	LinkedListIterator<T> begin() const {  // ✅ 加 const 
		return LinkedListIterator<T>(head);
	}
	LinkedListIterator<T> end() const {    // ✅ 加 const
		return LinkedListIterator<T>(nullptr);
	}
private:
	node<T>* head;
	node<T>* tail;
	template <typename U>
	friend class LinkedListIterator;
};

template <typename T>
class LinkedListIterator {
public:
	LinkedListIterator(node<T>* start) : current(start) {}
	const T& operator*() const {           // ✅ 改为 const T&
		return current->data();
	}
	LinkedListIterator& operator++() {
		if (current != nullptr) {
			current = current->link();
		}
		return *this;
	}
	LinkedListIterator operator++(int) {
		LinkedListIterator temp = *this;
		++(*this);
		return temp;
	}
	bool operator==(const LinkedListIterator& other) const {
		return current == other.current;
	}
	bool operator!=(const LinkedListIterator& other) const {
		return current != other.current;
	}
private:
	node<T>* current;
};

template <typename T>
class ReverseIterator {
public:
	ReverseIterator(node<T>* head) : current(head) {
		// 移动到最后一个节点
		if (head != nullptr) {
			while (current->link() != nullptr) {
				current = current->link();
			}
		}
	}
	// ✅ 添加默认构造函数用于 end()
	ReverseIterator() : current(nullptr) {}

	const T& operator*() const {           // ✅ 改为 const T&，加 const
		return current->data();
	}
	// ✅ 注意：单向链表无法真正反向遍历
	// 这里的实现只能从末尾开始，但无法回退
	ReverseIterator& operator++() {
		// 单向链表无法获得前驱节点
		// 此处不做任何操作或者直接跳到末尾
		if (current != nullptr) {
			current = nullptr;  // 直接移动到 end
		}
		return *this;
	}
	bool operator==(const ReverseIterator& rhs) const {
		return current == rhs.current;
	}
	bool operator!=(const ReverseIterator& rhs) const {
		return current != rhs.current;
	}
private:
	node<T>* current;
};

template <typename T, typename Predicate>
class FilterIterator {
public:
	FilterIterator(node<T>* start, node<T>* end, Predicate p) : current(start), end_(end), pred(p) {
		skip_invalid();
	}

	const T& operator*() const {           // ✅ 改为 const T&，加 const
		return current->data();
	}
	FilterIterator& operator++() {
		if (current != end_) {
			current = current->link();
			skip_invalid();
		}
		return *this;
	}
	bool operator==(const FilterIterator& rhs) const {
		return current == rhs.current;
	}
	bool operator!=(const FilterIterator& rhs) const {
		return current != rhs.current;
	}

private:
	node<T>* current;
	node<T>* end_;
	Predicate pred;

	void skip_invalid() {
		while (current != end_ && !pred(current->data())) {
			current = current->link();
		}
	}

};

class EvenIterator {
public:
	EvenIterator(node<int>* start) : current(start) {
		skip_to_even();
	}

	const int& operator*() const {         // ✅ 改为 const int&，加 const
		return current->data();
	}
	EvenIterator& operator++() {
		if (current != nullptr) {
			current = current->link();
			skip_to_even();
		}
		return *this;
	}
	bool operator==(const EvenIterator& rhs) const {
		return current == rhs.current;
	}
	bool operator!=(const EvenIterator& rhs) const {
		return current != rhs.current;
	}

private:
	node<int>* current;
	void skip_to_even() {
		while (current != nullptr && current->data() % 2 != 0) {
			current = current->link();
		}
	}
};

/*
要求：
不能修改节点值（只能 const int& operator*() const）
必须支持前向迭代
必须能与普通 iterator 做比较（== / !=）
*/
class ConstIterator {
public:
	ConstIterator(node<int>* p) : current(p) {}

	const int& operator*() const {
		return current->data();
	}
	ConstIterator& operator++() {
		if (current != nullptr) {
			current = current->link();
		}
		return *this;
	}
	bool operator==(const ConstIterator& rhs) const {
		return current == rhs.current;
	}
	bool operator!=(const ConstIterator& rhs) const {
		return current != rhs.current;
	}

private:
	node<int>* current;
};