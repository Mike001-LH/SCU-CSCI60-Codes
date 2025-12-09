#include <iostream>
#include <node.h>
using namespace std;

template <typename T>
class L_iterator {
public: 
	L_iterator(node<T>* start = nullptr) : curr(start) {}
	//need to overload ++ for L_iterator
	L_iterator& operator ++() {
		if (curr != nullptr) {
			curr = curr->link();
		}
		return *this;//this指针指向当前对象,解引用得到当前对象的引用
	}
	//need to overload !=
	bool operator !=(const L_iterator& other) const {
		return curr != other.curr;
	}
	//need to overload * for L_iterator
	T operator *() const { return curr->data(); }//重载*运算符，返回当前节点的数据
private:
	//what is an iterator? //iterator is a pointer to a node,用来遍历链表的
	node<T>* curr;
};