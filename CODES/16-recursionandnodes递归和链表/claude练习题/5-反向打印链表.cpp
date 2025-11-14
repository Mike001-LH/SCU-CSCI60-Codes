/*
问题 5: 反向打印链表
编写一个递归函数 void printReverse(node* head)，从后往前打印链表。
示例：对 1->2->3->nullptr，输出应该是 3 2 1
思考：这个函数如何利用递归的回溯特性？
*/
#include <iostream>
using namespace std;
class node {
public:
    // constructors
    node(int d = 0, node* l = nullptr) : data_(d), link_(l) {}
    // accessors
    int data() const { return data_; }
    node* link() const { return link_; }
    // mutators for data_ and link_
    void set_data(int val) { data_ = val; }
    void set_link(node* new_link) { link_ = new_link; }
private:
    int data_;
    node* link_;
};

void printReverse(node* head) {//递归函数，从后往前打印链表
    if (head == nullptr) {
        return;
    }
	printReverse(head->link());//递归调用，先递归到最后面的节点，然后开始打印
    cout << head->data() << " ";
}

int main() {
    // Build a list 1->2->3->nullptr
    node* head = new node(3, nullptr);
    head = new node(2, head);
    head = new node(1, head);
    // Test printReverse
    cout << "Reverse print: ";
    printReverse(head);
    cout << endl;
    return 0;
}