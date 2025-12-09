#include <iostream>
using namespace std;

class node {
public:
	node(int d = 0, node* l = nullptr) : data_(d), link_(l) {}
	int data() const { return data_; }
	node* link() const { return link_; }
	void set_data(int val) { data_ = val; }
	void set_link(node* new_link) { link_ = new_link; }
private:
	int data_;
	node* link_;
};

class IntList {
public:
	IntList() : head(nullptr), tail(nullptr) {}
	~IntList() {
		while (head != nullptr){
			node* temp = head;
			head = head->link();
			delete temp;//删除当前节点
		}
		tail = nullptr;
	}
	void insert(int val) {
		node* new_node = new node(val);
		if (head == nullptr) {
			head = new_node;
			tail = new_node;
		}
		else {
			new_node->set_link(head);//新节点指向当前头节点
			head = new_node;//头节点向前移动到新节点
		}
	}
	bool remove(int val) {
		node* curr = head;
		node* prev = nullptr;//记录前一个节点
		while (curr != nullptr) {
			if (curr->data() == val) {
				if (prev == nullptr) { head = head->link(); }//如果前一个节点为空，说明删除的是头节点
				else { prev->set_link(curr->link()); }//否则将前一个节点的链接指向当前节点的下一个节点
				if (curr == tail) { tail = prev; } //如果删除的是尾节点，更新尾节点指针
				delete curr;
				return true;
			}
		}
		return false;
	}

	int size() const {
		int count = 0;
		node* curr = head;
		while (curr != nullptr) {
			count++;
			curr = curr->link();
		}
		return count;
	}

	void print() const {
		node* curr = head;
		while (curr != nullptr) {
			cout << curr->data() << " ";
			curr = curr->link();
		}
		cout << endl;
	}

	//排序函数，把链表按照升序排列
	void sort() {
		if (head == nullptr || head->link() == nullptr) return;//if only one element or empty list, do nothing
		//bubble sort
		for (node* i = head; i != nullptr; i = i->link()) {
			for (node* j = head; j->link() != nullptr; j = j->link()) {//从下一个节点开始比较
				if (i->data() > j->data()) {//swap data
					int temp = i->data();
					i->set_data(j->data());
					j->set_data(temp);
				}
			}
		}
	}
	//copy constructor and assignment operator
	IntList(const IntList& other) : head(nullptr), tail(nullptr) {//initialize head and tail to nullptr, so we can use insert function to copy a new list
		node* curr = other.head;
		while (curr != nullptr) {
			insert(curr->data());
			curr = curr->link();
		}
	}

	IntList& operator=(const IntList& other) {
		if (this == &other) { return *this; }
		while (head != nullptr) {
			node* temp = head;
			head = head->link();
			delete temp;
		}
		head = nullptr;
		tail = nullptr;
		node* curr = other.head;
		while (curr != nullptr) {
			insert(curr->data());
			curr = curr->link();
		}
		return *this;
	}
	boo

private:
	node* head;
	node* tail;
};

int main() {
	IntList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);

	cout << "Size: " << list.size() << endl;        // 3
	cout << "Contains 2? " << list.contains(2) << endl;  // 1

	list.print();  // 输出：3 2 1 

	list.remove(2);
	list.print();  // 输出：3 1

	cout << "Size: " << list.size() << endl;  // 2

	list.insert(5);
	list.insert(2);
	list.insert(8);
	list.insert(1);
	list.insert(9);

	cout << "Before: ";
	list.print();  // 9 1 8 2 5

	list.sort();

	cout << "After: ";
	list.print();  // 1 2 5 8 9

	return 0;
}