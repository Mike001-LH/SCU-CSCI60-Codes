// Interface and implementation of iterator for templatized linked list
// Sara Krehbiel, 11/21/25

#ifndef L_ITERATOR_H
#define L_ITERATOR_H

#include "node.h"

template <typename T>
class L_iterator {
public:
	// WEEK 10 TODO: implement constructor(s), overload != and ++
	//iterator的构造器要初始化迭代器指向某个节点
	L_iterator(node<T>* p = nullptr) : curr(p) {} // default constructor
	T operator *() const { return curr->data(); } // overloaded dereference
	bool operator !=(const L_iterator<T>& other) const {
		return curr != other.curr; // compare addresses of current nodes
	}
	L_iterator<T>& operator ++() { // pre-increment overload//引用传参是为了链式调用，这里++是前置++，用来移动到下一个节点
		curr = curr->link();
		return *this; // 返回当前对象的引用，以便支持链式调用
	}

private:
	node<T> *curr; // address of next node in a list we're iterating through
};



#endif
