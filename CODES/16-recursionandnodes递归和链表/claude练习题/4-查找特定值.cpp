/*
问题 4: 查找特定值
编写一个递归函数 node* findNode(node* head, int target)，查找链表中第一个数据为target的节点。如果找不到返回nullptr。
示例：在 1->3->5->7->nullptr 中找3，返回指向3的节点
示例：在 1->3->5->7->nullptr 中找10，返回nullptr
*/
#include <iostream>
using namespace std;
class node {
public:
    // constructors
    node(int d = 0, node* l = nullptr) : data_(d), link_(l) {}//这里我们用默认参数直接在构造函数参数列表初始化成员变量
    //也就是说当我们创建一个node对象时，如果没有提供参数，它将默认data_为0，link_为nullptr

    // accessors
    int data() const { return data_; }
    node* link() const { return link_; }

    // mutators for data_ and link_
    void set_data(int val) { data_ = val; }//将data_设置为val
    void set_link(node* new_link) { link_ = new_link; }//将link_设置为new_link

private:
    int data_;//data_是一个整数，存储节点的数据，比方说6、4、2等，一个节点就存储一个整数
    node* link_; // link is the ADDRESS of the next node // link_是一个指向下一个节点的指针
};

node* findNode(node* head, int target) {
    if(head == nullptr) {
        return nullptr; // base case: reached end of list without finding target
	}
    if(head->data() == target) {
        return head; // base case: found the target
    }
	return findNode(head->link(), target); // recursive case: search in the rest of the list
}

/*
链表的结构是这样的：
head -> [data | link] -> [data | link] -> ... -> nullptr
*/
int main() {
    // Build a list 1->3->5->7->nullptr
    node* head = new node(7, nullptr);
    head = new node(5, head);
    head = new node(3, head);
    head = new node(1, head);
    // Test findNode
    int target1 = 3;
	node* result1 = findNode(head, target1);//查找数据为3的节点，如果找到就返回指向该节点的指针
    if (result1 != nullptr) {
		cout << "Found node with data " << target1 << ": " << result1->data() << endl;//输出：Found node with data 3: 3 //ps：result1->data()相当于访问result1指向的节点的data成员
    } else {
		cout << "Node with data " << target1 << " not found." << endl;//如果没找到，输出：Node with data 3 not found.
    }
    int target2 = 10;
	node* result2 = findNode(head, target2);//查找数据为10的节点，如果找到就返回指向该节点的指针
    if (result2 != nullptr) {
        cout << "Found node with data " << target2 << ": " << result2->data() << endl;
    } else {
        cout << "Node with data " << target2 << " not found." << endl;
    }
    return 0;
}