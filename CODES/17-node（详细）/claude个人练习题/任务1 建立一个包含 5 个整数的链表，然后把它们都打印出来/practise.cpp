//知识点复盘：
//link()函数用于获取当前节点指向的下一个节点的指针(->link()可以简单理解为跳到下一个节点)
//set_link()函数用于设置当前节点指向的下一个节点的指针（->set_link()可以简单理解为把当前节点和下一个节点连接起来）
//data()函数用于获取当前节点存储的数据（->data()可以简单理解为读取当前节点的数据）
//set_data()函数用于设置当前节点存储的数据（->set_data()可以简单理解为修改当前节点的数据）


/*
任务 1: 建立一个包含 5 个整数的链表，然后把它们都打印出来
────────────────────────────────────────────────────────────────────────
要求：
• 创建5个node对象，数据分别为：6, 4, 2, 8, 10
• 用指针把它们连接成一个链表
• 打印出链表内容
示例输出：
6 -> 4 -> 2 -> 8 -> 10
你需要写什么：

创建5个 new node
用 set_link() 把它们连接起来
用循环遍历并打印
*/
/*
任务 2: 写一个函数，计算链表里有多少个数
────────────────────────────────────────────────────────────────────────
函数签名：
size_t count_nodes(const node* head)
要求：
• 输入：链表的头指针
• 输出：链表中节点的总数
• 不能修改链表
示例：
node* h = ...;  // 6 -> 4 -> 2
count_nodes(h);  // 返回 3
*/
/*
任务 3: 写一个函数，在链表里查找一个数，找到返回true，找不到返回false
────────────────────────────────────────────────────────────────────────
函数签名：
bool find_value(const node* head, int target)
要求：
• 输入：链表的头指针和要查找的数值
• 输出：true 如果找到，false 如果没找到
• 不能修改链表
示例：
node* h = ...;  // 6 -> 4 -> 2
find_value(h, 4);   // 返回 true
find_value(h, 5);   // 返回 false
*/
/*
任务 4: 写一个函数，在链表的最前面插入一个新数字
────────────────────────────────────────────────────────────────────────
函数签名：
void insert_at_front(node *& head, node *& tail, int value)
要求：
• 输入：链表的头指针、尾指针、和要插入的数值
• 输出：无（直接修改head和tail指针）
• 新数字要成为链表的第一个
特别注意：
• head 和 tail 参数前面有 & ，这很重要！
• 这样你才能改变调用者的 head 和 tail
示例：
node* h = ...;  // 原来是 6 -> 4 -> 2
node* t = ...;  // t 指向最后的 2
insert_at_front(h, t, 8);
// 现在 h 指向 8，链表变成 8 -> 6 -> 4 -> 2
*/
/*
任务 5: 写一个函数，在链表的最后面加入一个新数字
────────────────────────────────────────────────────────────────────────
函数签名：
void append_to_end(node *& head, node *& tail, int value)
要求：
• 输入：链表的头指针、尾指针、和要插入的数值
• 新数字要成为链表的最后一个
• 注意空链表的特殊情况
示例：
node* h = nullptr;  // 空链表
node* t = nullptr;
append_to_end(h, t, 6);   // h 和 t 都指向新创建的 6
append_to_end(h, t, 4);   // 链表变成 6 -> 4
append_to_end(h, t, 2);   // 链表变成 6 -> 4 -> 2
*/
/*
任务 6: 用递归的方式计算链表长度（不用循环！）
────────────────────────────────────────────────────────────────────────
函数签名：
size_t count_nodes_recursive(const node* curr)
要求：
• 必须用递归实现
• 不能用循环
• 返回链表长度
提示：
• 如果 curr 是 nullptr，返回 0
• 否则返回 1 + count_nodes_recursive(curr->link())
示例：
递归的思想：一个链表的长度 = 1 + 剩余链表的长度
*/
/*
任务 7: 写一个函数，打印链表（用递归方式）
────────────────────────────────────────────────────────────────────────
函数签名：
void print_list_recursive(const node* curr)
要求：
• 必须用递归实现
• 打印格式：6->4->2（中间用 -> 连接，最后没有 ->）
提示：
• 基础情况：curr == nullptr 时停止
• 递归情况：打印当前数字，然后递归打印下一个
*/
/*
任务 8: 写一个函数，删除链表的第一个节点
────────────────────────────────────────────────────────────────────────
函数签名：
void remove_first_node(node *& head, node *& tail)
要求：
• 第一个节点要被删除（用 delete）
• head 要指向第二个节点
• 如果删除后链表变空，tail 也要变成 nullptr
示例：
原链表：6 -> 4 -> 2
删除后：4 -> 2
危险区域：
• 记得用 delete 释放内存
• 不能访问已删除的节点
*/
/*
任务 9: 在链表的任意位置插入一个数字
────────────────────────────────────────────────────────────────────────
函数签名：
void insert_at_position(node *& head, node *& tail, int value, int pos)
要求：
• pos = 0 表示插入到最前面
• pos = 链表长度 表示插入到最后面
• 其他情况插入到中间
示例：
原链表：6 -> 2 (位置 0 和 1)
insert_at_position(head, tail, 4, 1);
新链表：6 -> 4 -> 2
*/
#include <iostream>
#include "practise.h"
using namespace std;
// 任务2：写一个函数，计算链表里有多少个数
size_t count_nodes(const node* head) {
	size_t count = 0;
	const node *current = head;
	while (current != nullptr) {
		count++;
		current = current->link();
	}
	return count;
}
// 任务3：写一个函数，在链表里查找一个数，找到返回true，找不到返回false
bool find_value(const node* head, int target) {
	const node *current = head;
	while (current != nullptr) {
		if (current->data() == target) {
			return true;
		}
	}
	return false;
}
// 任务4: 写一个函数，在链表的最前面插入一个新数字
void insert_at_front(node*& head; node*& tail; int value) {
	node* new_head = new node(value, head);//创建一个新节点，数据为value，指向当前的head
	if (tail == nullptr) {
		tail = new_head;
	}
	head = new_head;//将head指针更新为new_head
	//这样新节点就成为了链表的第一个节点
	//举个例子：假设原链表为 head → [6|•] → [4|•] → [2|nullptr] ← tail
	//调用insert_at_front(head, tail, 8)后，链表先创建一个新节点new_head → [8|•] → [6|•] → [4|•] → [2|nullptr]，然后更新head指向new_head
	//最后链表变成 head → [8|•] → [6|•] → [4|•] → [2|nullptr] ← tail
}
// 任务5: 写一个函数，在链表的最后面加入一个新数字
void append_to_end(node*& head; node*& tail; int value) {
	node* new_tail = new node(value, nullptr);//创建一个新节点，数据为value，指向nullptr
	if (head == nullptr) {
		head = new_tail;
	}
	tail->set_link(new_tail);//将当前尾节点的链接指向新节点
	tail = new_tail;//更新tail指针为新节点
	//这样新节点就成为了链表的最后一个节点
	//举个例子：假设原链表为 head → [6|•] → [4|•] → [2|nullptr] ← tail
	//调用append_to_end(head, tail, 8)后，链表先创建一个新节点new_tail → [8|nullptr]，然后将tail节点的链接指向new_tail得到 head → [6|•] → [4|•] → [2|•] → [8|nullptr]
	//最后更新tail指向new_tail，链表变成 head → [6|•] → [4|•] → [2|•] → [8|nullptr] ← tail
}
// 任务6: 用递归的方式计算链表长度（不用循环！）
size_t count_nodes_recursive(const node* curr) {
	if (curr == nullptr) {
		return 0;
	}
	else {
		return 1 + count_nodes_recursive(curr->link());
	}
}
//递归的思想：一个链表的长度 = 1 + 剩余链表的长度
//举个例子：假设链表为 head → [6|•] → [4|•] → [2|nullptr]
//调用count_nodes_recursive(head)时，curr指向6节点，不是nullptr，返回1 + count_nodes_recursive(4节点)
//调用count_nodes_recursive(4节点)时，curr指向4节点，不是nullptr，返回1 + count_nodes_recursive(2节点)
//调用count_nodes_recursive(2节点)时，curr指向2节点，不是nullptr，返回1 + count_nodes_recursive(nullptr)
//调用count_nodes_recursive(nullptr)时，curr是nullptr，返回0

//任务7：写一个函数，打印链表（用递归方式）
void print_list_recursive(const node* curr) {
	if(curr == nullptr) {
		return;
	}
	else {
		cout << curr->data();
		if (curr->link() != nullptr) {
			cout << " ";
		}
		print_list_recursive(curr->link());
	}
}
//任务8：写一个函数，删除链表的第一个节点
void remove_first_node(node*& head, node*& tail) {
	if (head == nullptr) {
		return; //链表为空，什么都不做
	}
	node* old_head = head; //保存当前头节点的指针
	head = head->link(); //将head指向第二个节点
	if (head == nullptr) {
		tail = nullptr; //如果删除后链表变空，tail也要变成nullptr
	}
	delete old_head; //释放原头节点的内存
}
//任务9：在链表的任意位置插入一个数字
void insert_at_position(node*& head, node*& tail, int value, int pos) {
	node* new_node = new node(value, nullptr); // 1. 创建新节点
	// 情况1：空链表，直接变成head和tail
	if (head == nullptr) {
		head = tail = new_node;
		return;
	}
	// 情况2：插在最前面（pos == 0）
	if (pos == 0) {
		new_node->set_link(head);//set_link()的意思是把新节点的链接指向当前的head，举个例子：假设原链表为 head → [6|•] → [4|•] → [2|nullptr] ← tail，那么调用new_node->set_link(head)后，新节点变成 new_node → [value|•] → [6|•] → [4|•] → [2|nullptr] ← tail
		head = new_node;//更新head指向新节点，得到 head → [value|•] → [6|•] → [4|•] → [2|nullptr] ← tail
		return;
	}
	// 情况3：插在中间或最后
	node* curr = head;//从head开始遍历
	int index = 0;
	// 找到要插入位置的前一个节点（第pos-1个）
	while(curr != nullptr && index < pos - 1) {
		curr = curr->link();
		index++;
	}
	// 如果pos超出当前链表长度 → 默认插到最后
	if (curr == nullptr) {
		//假设原链表为 head → [6|•] → [4|•] → [2|nullptr] ← tail
		tail->set_link(new_node);//将当前尾节点的链接指向新节点
		//变为： head → [6|•] → [4|•] → [2|•] → [value|nullptr]
		tail = new_node;//更新tail指针为新节点
		//变为： head → [6|•] → [4|•] → [2|•] → [value|nullptr] ← tail
		return;
	}
	// 正常插入中间位置
	new_node->set_link(curr->link());//这句话意思是：把新节点的链接指向curr的下一个节点，举个例子：假设原链表为 head → [6|•] → [4|•] → [2|nullptr] ← tail，curr指向4节点，那么调用new_node->set_link(curr->link())后，新节点变成 new_node → [value|•] → [2|nullptr]
	curr->set_link(new_node);//这句话意思是：把curr的链接指向新节点，得到 head → [6|•] → [4|•] → [value|•] → [2|nullptr] ← tail
	// 如果插入在尾部之后，要更新tail
	if (new_node->link() == nullptr) {
		tail = new_node;
	}
}