/*
题目5：删除特定节点
编写一个函数void deleteNode(Node<int>*& head, int target)，删除数据为target的节点（假设只有一个）。
*/
/*
题目6：反转链表
编写一个函数Node<int>* reverseList(Node<int>* head)，反转整个链表并返回新的头指针。
*/
#include <iostream>
using namespace std;

class Node {
public:
	Node(int d = 0, Node* l = nullptr) : data_(d), link_(l) {}
	int data() const { return data_; }
	Node* link() const { return link_; }//返回下一个节点的地址，以便进行遍历，可以通过不断调用link()来访问链表中的所有节点
	void set_data(int val) { data_ = val; }
	void set_link(Node* new_link) { link_ = new_link; }//将新节点的地址赋值给当前节点的link_，可以实现节点的连接
private:
	int data_;
	Node* link_;
};

void deleteNode(Node*& head, int target) {
    // Case 1: 空链表
    if (head == nullptr) return;

    // Case 2: 删除的是头节点
    if (head->data() == target) {
        Node* tmp = head;
        head = head->link();   // 让 head 指向下一个
        delete tmp;
        return;
    }

    // Case 3: 删除中间节点（或尾节点）
    Node* curr = head;
    while (curr->link() != nullptr && curr->link()->data() != target) {
        curr = curr->link();
    }

    // 如果没找到，直接 return
    if (curr->link() == nullptr) return;

    // 找到了：curr->link() 是要删除的节点
    Node* tmp = curr->link();
    curr->set_link(tmp->link());
    delete tmp;
}

void reverseList(Node* head) {//Node<int>的意思是：这是一个模板类Node的实例化，表示节点中存储的数据类型是int。
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->link(); // 保存下一个节点
        curr->set_link(prev);      // 反转当前节点的指针
        prev = curr;               // 移动 prev 和 curr 指针
        curr = next;
    }
	return prev; // prev 最终会指向新的头节点
}