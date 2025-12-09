// A templated node class
// Sara Krehbiel, 11/16/25

#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::ostream;

/*
T 是“节点里面存储的数据的类型”
node<T> 是“节点本身的类型”
*/
template <typename T>
class node {
public:
    // constructors
	node(const T& d = T(), node<T>* l = nullptr) : data_(d), link_(l) {}
    //const T& d = T()的意思是如果没有传入参数d，则使用T类型的默认构造函数来初始化data_成员变量（注：T() 表示“创建一个类型 T 的默认构造的对象”）
	// node<T>* l = nullptr的意思是如果没有传入参数l，则将link_成员变量初始化为nullptr，表示该节点最初不指向任何其他节点。

    // accessors
    T data() const { return data_; }
    node<T>* link() const { return link_; }

    // mutators
    void set_data(const T& new_data) { data_ = new_data; }
    void set_link(node<T>* new_link) { link_ = new_link; }

private:
	T data_;//这个是节点存储的数据 //这表示：节点里面保存一个类型为 T 的“值”
    node<T>* link_;//这个是指向下一个节点的指针
};
// linked list toolkit functions

// pre: curr points to first node of a linked list
// post: in-order list data have been output and list is unchanged
template <typename T>
ostream& operator <<(ostream& o, const node<T>* curr) {
    //for (; curr != nullptr; curr = curr->link()) {
    //    o << curr->data() << " ";  // note: T should have << overloaded
    //}
    //return o;
	if (curr == nullptr) return o;//如果curr为空，直接返回
	return o << curr->data() << " " << curr->link();//curr->data()是当前节点的数据，curr->link()是下一个节点
	//这里的 curr->link() 也是一个 node<T>*，而 << 对 node<T>* 又会再调用这个操作符本身：
    //所以它 又会调用一次 operator<<。
    //然后新的调用又会输出下一个结点……
    //直到链表结束（curr==nullptr）。
}

// pre: h and t point to first and last node of a linked list
// post: t is the same, h points to a newly constructed first node
template <typename T>
void list_insert_head(node<T>*& h, node<T>*& t, const T& val) {
	h = new node<T>(val, h);     // point head to a new node that points to old head//创建一个新节点，数据为val，链接指向当前的头节点h，然后将h更新为指向这个新节点
	if (t == nullptr) t = h;      // update t if list was previously empty//如果链表之前是空的（t为nullptr），则将t也更新为指向新节点h
}



// linked list toolkit functions

// pre: curr points to first node of a linked list
// post: in-order list data have been output and list is unchanged
template <typename T>
ostream& operator <<(ostream& o, const node<T>* curr) {//const node<T>* curr是新建的一个指向node<T>类型常量的指针，表示链表的当前节点
    for (; curr != nullptr; curr = curr->link()) {
        o << curr->data() << " ";   // note: T should have << overloaded
    }
    return o;
}

// pre: h and t point to first and last node of a linked list
// post: h is the same, t points to a newly constructed last node
template <typename T>
void list_insert_tail(node<T>*& h, node<T>*& t, const T& val) {//传入头指针h和尾指针t的引用，以及要插入的值val
	if (t == nullptr) {       // check if this is the first node being inserted//如果尾指针t为空，说明链表是空的
		h = t = new node<T>(val, nullptr);  // new node is both the head and tail//创建一个新节点，数据为val，链接为nullptr，然后将头指针h和尾指针t都指向这个新节点
    }
    else {
        t->set_link(new node<T>(val, nullptr));  // new node in the usual case
        t = t->link();       // increment the tail pointer
    }
}

// pre: h and t point to first and last node of a linked list
// post: the list is unchanged, too; #nodes in list is returned
template <typename T>
size_t list_size(const node<T>* h, const node<T>* t) {
    if (h == nullptr) return 0;
    return 1 + list_size(h->link(), t);  // 1 for current node + size of rest
}

template <typename T>
bool list_search(const node<T>* h, const node<T>* t, const T& val) {
	if (h == nullptr) return false;//如果h是nullptr，到达链表末尾还没找到，返回false
    if (h->data() == val) return true;     // stop if the current node's data matches
	return list_search(h->link(), t, val); // check the rest of the list//递归调用list_search函数检查下一个节点，直到找到匹配的值或遍历完整个链表
}

// pre: h and t point to first and last node of a linked list
// post: return the number of times val occurs in (unchanged list)
template <typename T>
size_t list_count(const node<T>* h, const node<T>* t, const T& val) {
    if (h == nullptr) return 0;
    return (h->data() == val ? 1 : 0) + list_count(h->link(), t, val);//调用递归，每次检查当前节点的数据是否与val匹配，如果匹配则加1，否则加0，然后递归调用list_count函数检查下一个节点，直到遍历完整个链表。
}

// pre: h and t point to first and last node of a linked list
// post: return true iff val is present, removed first instance if so
template <typename T>
bool list_remove_one(node<T>*& h, node<T>*& t, const T& val) {
	node<T>* curr = h, * prev = nullptr;//prev记录当前节点的前一个节点
    while (curr != nullptr) {
		if (curr->data() == val) {//如果找到了匹配的值
			if (prev == nullptr) h = h->link();         // update head if removing first node//如果prev为空，说明当前节点是头节点，更新头节点为下一个节点
			else prev->set_link(curr->link());          // bypass the current node//否则，将前一个节点的链接指向当前节点的下一个节点，跳过当前节点
			if (curr == t) t = prev;                    // update head if removing last node//如果当前节点是尾节点，更新尾节点为前一个节点
            delete curr;
            return true;
        }
		prev = curr;//如果没有找到匹配的值，更新prev为当前节点
		curr = curr->link();//继续遍历下一个节点
    }
    return false;
}
///注意：接下来的两个是我提前写的！所以和最后可能不太一样
// pre: h and t point to first and last node of a linked list
// post: return true iff val is present, removed first instance if so
template <typename T>
size_t list_remove_all(node<T>*& h, node<T>*& t, const T& val) {
	node<T>* curr = h, * prev = nullptr;//prev是记录当前节点的一个指针
    size_t count = 0;
	// Traverse the list
    while (curr != nullptr) {
		if (curr->data() == val) {//如果找到了匹配的值
            // Node to be deleted
			node<T>* temp = curr;//用temp临时保存当前节点以便删除
			if (prev == nullptr) {//如果是头节点
                // Deleting head node
				h = h->link();//把链表头节点更新为下一个节点
				curr = h; // Move curr to the new head//curr更新为新的头节点
			}
			else {//如果不是头节点
                // Deleting non-head node
				prev->set_link(curr->link());//把前一个节点的链接指向当前节点的下一个节点，跳过当前节点
				curr = curr->link(); // Move curr to the next node//把当前节点更新为下一个节点
				//如此一来，就成功删除了当前节点
            }
            if (temp == t) {
                // Update tail if needed
                t = prev;
            }
			delete temp;//释放temp指向的节点内存
			count++;
        } else {//如果没找到
            // Move to the next node
			prev = curr;//将上一个节点更新为当前节点，因为下一个轮回curr会变成下一个节点
			curr = curr->link();//继续遍历下一个节点
        }
    }
	return count;
}

// pre: lhead and ltail are nullptr, rhead points to first node of a linked list
// post: lhead and ltail address first and last nodes in deep copy of rhead
template <typename T>
void list_copy(node<T>*& lhead, node<T>*& ltail, const node<T>* rhead) {//lhead和ltail是要创建的新链表的头尾指针引用，rhead是要复制的链表的头指针
    lhead = ltail = nullptr;  // start with an empty list
    for (const node<T>* curr = rhead; curr != nullptr; curr = curr->link()) {
        list_insert_tail(lhead, ltail, curr->data());
	}
}


#endif
