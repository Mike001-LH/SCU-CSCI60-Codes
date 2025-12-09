// A templatized node class and a linked lists toolkit
// Sara Krehbiel, 11/15/25-11/21/25

#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::ostream;

template <typename T>
class node {
public:
    // constructor(s)
	node(const T& d = T(), node<T>* l = nullptr) : data_(d), link_(l) {}//T()的意思是调用T类型的默认构造函数，如果T是int，则T()为0，如果T是string，则T()为空字符串

    // accessors
    T data() const { return data_; }
    node<T>* link() const { return link_; }

    // mutators
	void set_data(const T& val) { data_ = val; }//这里的const T& val是为了避免传值时的开销，同时保证val不会被修改
    void set_link(node<T>* new_link) { link_ = new_link; }

private:
    T data_;
    node<T> *link_; 
};

// linked list toolkit functions

// pre: curr points to first node of a linked list
// post: in-order list data have been output and list is unchanged
template <typename T>
ostream& operator <<(ostream& o, const node<T>* curr) {//这里的const node<T>* curr是为了保证curr指向的节点不会被修改，但我们还是可以通过curr遍历链表访问节点的数据
    if (curr==nullptr) return o; // base case
    return o << curr->data() << " " << curr->link(); // insert one then the rest
	//首先输出当前节点的数据，然后递归调用operator<<输出下一个节点的数据（curr->link()），直到curr为nullptr为止
}

// pre: h and t point to first and last node of a linked list
// post: t is the same, h points to a newly constructed first node
template <typename T>
void list_insert_head(node<T>*& h, node<T>*& t, const T& val) {//这里的node<T> *& h是一个引用，指向指向链表头节点的指针，这样我们可以修改调用者传入的指针本身
    h = new node<T>(val,h); // point head to a new node that points to old head//新节点的data是val，link指向原来的头节点h
    if (t==nullptr) t = h; // update t if if list was previously empty
}
//比方说原本的链表为 h -> [data1|link1] -> [data2|link2] -> nullptr//插入后就变成了 h -> [val|h] -> [data1|link1] -> [data2|link2] -> nullptr

// pre: h and t point to first and last node of a linked list
// post: h is the same, t points to a newly constructed last node
template <typename T>
void list_insert_tail(node<T> *& h, node<T> *& t, const T& val) {
    if (t==nullptr) { // check if this is the first node being inserted
        h = t = new node<T>(val,nullptr); // new node is both the head and tail
    } else { // t points to an existing node in the usual case
        t->set_link(new node<T>(val,nullptr)); // point old last node to new one
        t = t->link(); // increment the tail pointer
    }
	//如果老链表为 h -> [data1|link1] -> [data2|link2] -> nullptr，先创建新节点 [val|nullptr]，然后把老链表的最后一个节点的link指向新节点，最后更新t指向新节点
	//h ->[data1 | link1] ->[data2 | link2] -> nullptr    // h --> [data1|link1] -> [data2|link2] -> [val|nullptr] -> nullptr   // h --> [data1|link1] -> [data2|link2] -> [val|nullptr] -> nullptr
    //                             ↑                      //                              ↑                                     //                                              ↑
    //                             t                      //                              t                                     //                                              t
}

// pre: h and t point to first and last node of a linked list
// post: the list is unchanged, the #nodes in list is returned
template <typename T>
size_t list_size(const node<T>* h, const node<T>* t) {
    if (h==nullptr) return 0; // done when the remaining list to count is empty
    return 1 + list_size(h->link(),t); // 1 for current node + size of the rest
}

// pre: h and t point to first and last node of a linked list
// post: the list is unchanged, return true iff val is in the list
template <typename T>
bool list_search(const node<T>* h, const node<T>* t, const T& val){
    if (h==nullptr) return false; // val can't be present in an empty list
    if (h->data()==val) return true; // stop if the current node's data is val
    return list_search(h->link(),t,val); // check the rest of the list otherwise
}

// pre: h and t point to first and last node of a linked list 
// post: return the number of times val occurs in (unchanged list)
template <typename T>
size_t list_count(const node<T>* h, const node<T>* t, const T& val) {
    if (h==nullptr) return 0;
	return (h->data() == val ? 1 : 0) + list_count(h->link(), t, val);//h->data()==val?1:0的意思是如果当前节点的数据等于val，则计数加1，否则加0，然后递归调用list_count计算剩余节点中val的出现次数
}

// pre: h and t point to first and last node of a linked list
// post: return true iff val is present, removed first instance if so
template <typename T>
bool list_remove_one(node<T>*& h, node<T>*& t, const T& val) {
    node<T> *curr = h, *prev = nullptr;
    while (curr!=nullptr) {
        if (curr->data()==val) { // delete current node and rewire appropriately
            if (prev==nullptr) h = h->link(); // update head if removing first
			else prev->set_link(curr->link());//将前一个节点的link指向当前节点的下一个节点，从而跳过当前节点，curr指向的节点在这里没有向后移动
            if (curr==t) t = prev; // update tail if removing last node
			delete curr;//与上面配合，删除当前节点
            return true;
        }
		prev = curr;//将prev更新为curr，准备下一次循环
		curr = curr->link();//将curr移动到下一个节点
    }
    return false;
}

// pre: h and t point to first and last node of a linked list 
// post: return true iff val is present, removed first instance if so
template <typename T>
size_t list_remove_all(node<T>*& h, node<T>*& t, const T& val) {
    size_t count = 0;
    node<T> *curr = h, *prev = nullptr;
    while (curr!=nullptr) {
        if (curr->data()==val) { // delete current node and rewire appropriately
            if (prev==nullptr) h = h->link();
            else prev->set_link(curr->link());
            if (curr==t) t = prev;
            delete curr;
            curr = prev; // rewind before setting up for next loop
            count++;
        }
        prev = curr; 
        if (curr == nullptr) curr = h; // check if just deleted head
        else curr = curr->link();
    }
    return count;
}

// pre: lhead and ltail are nullptr, rhead points to first node of a linked list
// post: lhead and ltail address first and last nodes in deep copy of rhead list
template <typename T>
void list_copy(node<T>*& lhead, node<T>*& ltail, const node<T>* rhead) { //rhead是被复制链表的头节点，lhead和ltail是新链表的头尾指针引用
    if (rhead==nullptr) return; // base case
    if (ltail==nullptr) { // create first node
        lhead = ltail = new node<T>(rhead->data(),nullptr);
    } else { // create subsequent nodes and relink tail
        ltail->set_link(new node<T>(rhead->data(),nullptr));
        ltail=ltail->link(); 
    }
    list_copy(lhead,ltail,rhead->link()); // recursively copy rest of list
}

// pre: h and t point to first and last node of a linked list
// post: all nodes in list are deallocated, and h and t are set to nullptr
template <typename T>
void list_clear(node<T>*& h, node<T>*& t) {
    if (h==nullptr) { // base case
        t = nullptr; // h is already nullptr; t needs to be nullptr also
        return;
    }
    node<T>* deleteme = h; // next node to be deleted
    h = h->link(); // set up to delete rest of list
    delete deleteme; // deallocate first node
    list_clear(h,t); // recursively clear rest of list
}


#endif // NODE_H
