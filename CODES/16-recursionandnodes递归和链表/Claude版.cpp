// Goals: Stack diagrams for a recursive function; introduce nodes
// Sara Krehbiel, 11/5/25

#include <iostream>

using namespace std;

void unpackAndRepackDolls(int);//这是一个递归函数，用于从最大到最小打开一些俄罗斯套娃

class node;//前向声明node类
void nodeCode();//这是一个函数，用于演示节点的使用
void printList(node* head);//这是一个函数，用于打印节点链表

int main() {
    unpackAndRepackDolls(3);
    //nodeCode();
    return 0;
}

// a recursive function to unpack some nesting dolls from largest to smallest
void unpackAndRepackDolls(int n) {
    if (n == 0) return; // recursion base case
    cout << "Unpacking doll #" << n << endl; // open biggest (non-recursive)
    unpackAndRepackDolls(n - 1); // open+close all remaining (recursive)
    cout << "Repacking doll #" << n << endl; // close biggest (non-recursive)
}
//几个例子，如果n=3，输出将是：
//Unpacking doll #3        //  Unpacking doll #2
//  Unpacking doll #2      //    Unpacking doll #1
//    Unpacking doll #1    //    // base case reached here, so start returning
//    Repacking doll #1    //  这里重新包装娃娃#1
//  Repacking doll #2      // 这里重新包装娃娃#2
//Repacking doll #3        //这里重新包装娃娃#3

// a class bundling a piece of data with a link to another piece of data+link
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

// Forward declaration for operator overloading
ostream& operator<<(ostream& out, node* head);

void nodeCode() {
    // TODO: build a list 6->4->2 from the back to the front
    node* head = new node(2, nullptr); // head points to a single node with data 2
    node* tail = head; // head and tail are the same for a 1-elem list
    head = new node(4, head);//调用构造函数创建一个新节点，数据为4，链接指向当前的head，然后更新head指针指向这个新节点
    head = new node(6, head);//同理，创建一个新节点，数据为6，链接指向当前的head，然后更新head指针指向这个新节点
    //下面是图解：
	// head -> [6| ] -> [4| ] -> [2| ] -> nullptr

    // TODO: build a list 6->4->2 from front to back//这里我们从前到后构建一个链表6->4->2
    node* h = new node(6, nullptr), * t = h;//创建一个新节点，数据为6，link_为nullptr，然后令h和t都指向这个节点
    t->set_link(new node(4, nullptr));  // 给尾部添加新节点，数据为4
    t = t->link();                      // 更新尾部指针
    t->set_link(new node(2, nullptr));  // 再添加一个节点，数据为2
    t = t->link();                      // 更新尾部指针

    cout << "The contents of the first list, printed three ways:\n";
    cout << "With explicit main code: ";
	// TODO: use accessors to get the three pieces of data starting with the head //ptr->member 相当于 (*ptr).member
    cout << head->data() << "->" << head->link()->data() << "->"
		<< head->link()->link()->data() << endl;//访问head节点的数据，然后访问head的链接节点的数据，最后访问链接节点的链接节点的数据
	//输出结果是6->4->2

    cout << "With a printList function: ";
    printList(head); // TODO: implement with while loop, for loop, then recursion

    cout << "By overloading << for node*: ";
    cout << head; // TODO: overload << with a loop, then recursively

    cout << "What will happen to the list when nodeCode returns?\n";
    delete head; // this only frees the first node in the list!

    // TODO: learn about const pointers and add const wherever appropriate!

}

// Implementation of printList function using while loop
void printList(node* head) {
	node* current = head;//创建一个指针current，指向head
	while (current != nullptr) {//当current不为nullptr时，继续循环
		cout << current->data();//输出current节点的数据
        if (current->link() != nullptr) cout << "->";
		current = current->link();//将current指向下一个节点
    }
    cout << endl;
	//由此可以输出链表的所有数据
	//输出结果是6->4->2
}

// Overload << operator for printing node lists
ostream& operator<<(ostream& out, node* head) {
	node* current = head;//创建一个指针current，指向head
    while (current != nullptr) {
        out << current->data();
        if (current->link() != nullptr) out << "->";
        current = current->link();
	}//同样是遍历链表，输出每个节点的数据
    out << endl;
	return out;//返回输出流,以便支持链式调用
}