#include <iostream>
using namespace std;

// 首先定义 node 类
template <typename T>
class node {
public:
    // Constructor
    node(const T& val, node<T>* next = nullptr) : data_(val), link_(next) {}

    // Accessors
    T data() const { return data_; }
    node<T>* link() const { return link_; }

    // Mutators
    void set_data(const T& val) { data_ = val; }
    void set_link(node<T>* new_link) { link_ = new_link; }

private:
    T data_;
    node<T>* link_;
};

// 然后定义 Bag 类
template <typename T>
class Bag {
public:
    // 0-arg constructor
    Bag() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~Bag();

    // Copy constructor
    Bag(const Bag<T>& other);

    // Assignment operator
    Bag<T>& operator=(const Bag<T>& other);

    // Methods
    size_t size() const;
    void insert(const T& val);
	size_t count(const T& val) const; //返回 Bag 中等于 val 的元素个数//这里两个const分别表示不会修改传入的val和不会修改Bag对象本身
    bool contains(const T& val) const;
	bool is_empty() const { return head == nullptr; }
    T getFirst() const;
	T getLast() const;
	bool erase_one(const T& val); //删除第一个等于val的元素，返回是否删除成功
	size_t erase_all(const T& val); //删除所有等于val的元素，返回删除的个数

    // Output operator
    template <typename T2>
    friend ostream& operator<<(ostream& o, const Bag<T2>& b);

private:
    node<T>* head;
    node<T>* tail;
};

// ============ Destructor ============
template <typename T>
Bag<T>::~Bag() {
    node<T>* current = head;
    while (current != nullptr) {
        node<T>* next = current->link();  // 保存下一个节点
        delete current;                    // 删除当前节点
        current = next;                    // 移动到下一个节点
    }
    head = nullptr;
    tail = nullptr;
}

// ============ Copy Constructor ============
template <typename T>
Bag<T>::Bag(const Bag<T>& other) : head(nullptr), tail(nullptr) {
    node<T>* current = other.head;
    while (current != nullptr) {
        insert(current->data());  // insert 会自动处理 head 和 tail 的更新
        current = current->link(); 
    }
}

// ============ Assignment Operator ============
template <typename T>
Bag<T>& Bag<T>::operator=(const Bag<T>& other) {
    // 检查自赋值情况
    if (this == &other) {
        return *this;
    }

    // 释放原有的链表
    node<T>* current = head;
    while (current != nullptr) {
        node<T>* next = current->link();
        delete current;
        current = next;
    }

    // 重新初始化 head 和 tail
    head = nullptr;
    tail = nullptr;

    // 进行深拷贝
    current = other.head;
    while (current != nullptr) {
        insert(current->data());
        current = current->link();
    }

    return *this;
}

// ============ Size Method ============
template <typename T>
size_t Bag<T>::size() const {
    size_t count = 0;
    node<T>* current = head;
    while (current != nullptr) {
        count++;
        current = current->link();
    }
    return count;
}

// ============ Insert Method ============
template <typename T>
void Bag<T>::insert(const T& val) {
    // 创建新节点，link 指向当前的 head
    node<T>* newNode = new node<T>(val, head);
    head = newNode;  // 新节点成为新的 head

    // 如果这是第一个节点（列表之前为空）
    if (tail == nullptr) {
        tail = head;
    }
}

template <typename T>
size_t Bag<T>::count(const T& val) const {
    size_t count = 0;
    for (node<T>* current = head; current != nullptr; current = current->link()) {
        if (current->data() == val) {
			count++;
        }
    }
}

template <typename T>
bool Bag<T>::contains(const T& val) const {
    for (node<T>* current = head; current != nullptr; current = current->link()) {
        if (current->data() == val) {
            return true;
		}
    }
	return false;
}

template <typename T>
T Bag<T>::getFirst() const {
    if(head == nullptr) {
		//throw runtime_error("Bag is empty");//runtime_error在#include <stdexcept>中定义
		//由于throw catch我还没学，所以先用下面的方式处理
		cout << "Error: Bag is empty." << endl;
		exit(1);//exit的意思是终止程序的运行，1表示异常终止
	}
	return head->data();
}

template <typename T>
T Bag<T>::getLast() const {
    if (head == nullptr) {
		//throw runtime_error("Bag is empty");
		cout << "Error: Bag is empty." << endl;
		exit(1);
    }
    return tail->data();
}

template <typename T>
bool Bag<T>::erase_one(const T& val) {
    node<T>* current = head;
	node<T>* previous = nullptr;//记录当前节点的前一个节点
    while (current != nullptr) {
        if (current->data() == val) {
            // 找到要删除的节点
			if (previous == nullptr) {//previous为nullptr说明删除的是第一个节点
                // 删除的是 head 节点
				head = current->link();//更新 head 指向下一个节点
                if (head == nullptr) {
                    // 如果删除后链表为空，更新 tail
                    tail = nullptr;
                }
            } else {
                // 删除中间或尾部节点
				previous->set_link(current->link());//更新前一个节点的 link 指向当前节点的下一个节点
                if (current == tail) {
                    // 如果删除的是 tail 节点，更新 tail
                    tail = previous;
                }
            }
            delete current; // 释放内存
            return true;    // 成功删除
        }
        previous = current;
        current = current->link();
    }
	return false; // 未找到要删除的节点
}


// ============ Output Operator ============
template <typename T2>//这里用T2是因为friend函数模板需要独立于类模板
ostream& operator<<(ostream& o, const Bag<T2>& b) {
    o << "{";
    node<T2>* current = b.head;
    while (current != nullptr) {
        o << current->data();
        current = current->link();
        if (current != nullptr) {
            o << ", ";  // 只在不是最后一个元素时添加逗号
        }
    }
    o << "}";
    return o;
}

// ============ Test Code ============
int main() {
	Bag<int> bag1;//Q：bag1是vector吗？A：不是，bag1是Bag类的一个实例，是一个链表实现的包（bag）数据结构。Q：那bag1是链标吗？A：不是，bag1是Bag类的一个实例，它内部使用链表来存储数据。

    // Test insert
    bag1.insert(5);
    bag1.insert(3);
    bag1.insert(7);
    bag1.insert(1);

    cout << "Bag1: " << bag1 << endl;
    cout << "Size of Bag1: " << bag1.size() << endl;

    // Test copy constructor
    Bag<int> bag2(bag1);
    cout << "Bag2 (copy of Bag1): " << bag2 << endl;

    // Test assignment operator
    Bag<int> bag3;
    bag3.insert(10);
    bag3.insert(20);
    cout << "Bag3 before assignment: " << bag3 << endl;

    bag3 = bag1;
    cout << "Bag3 after assignment from Bag1: " << bag3 << endl;

    // Test self-assignment
    bag1 = bag1;
    cout << "Bag1 after self-assignment: " << bag1 << endl;

    return 0;
}