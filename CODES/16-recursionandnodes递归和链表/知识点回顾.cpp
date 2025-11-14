//什么是递归？
//递归是一个函数调用自己的编程技术。 每次函数调用自己时，都会在栈上创建一个新的"层级"。
//递归函数通常包含两个主要部分：
//1. 基本情况（Base Case）：这是递归停止的条件。当满足这个条件时，函数不再调用自己，而是返回一个具体的值。
//2. 递归情况（Recursive Case）：这是函数调用自己的部分。每次调用时，问题规模通常会减小，逐渐接近基本情况。
//代码递归例子：
void unpackAndRepackDolls(int n) {
	if (n == 0) return;                    // ①基础情况 (BASE CASE)
	cout << "Unpacking doll #" << n << endl;  // ②递归前操作
	unpackAndRepackDolls(n - 1);             // ③递归调用
	cout << "Repacking doll #" << n << endl;  // ④递归后操作
}
/*递归的三个必要部分：
┌─────────────────────────────────────────────────────┐
│ 1. 基础情况 (Base Case)                             │
│    ├─ 什么时候停止递归                              │
│    └─ if (n == 0) return;                            │
├─────────────────────────────────────────────────────┤
│ 2. 递归情况 (Recursive Case)                        │
│    ├─ 执行某个工作                                  │
│    ├─ 调用自己处理更小的问题                        │
│    └─ 继续执行或清理工作                            │
├─────────────────────────────────────────────────────┤
│ 3. 进展 (Progress)                                  │
│    ├─ 每次递归调用的参数必须更接近基础情况          │
│    └─ n 每次减1，最终会到达 n==0                    │
└─────────────────────────────────────────────────────┘
*/
/*
想象俄罗斯套娃：最大的娃 → 中等的娃 → 小的娃 → 最小的娃(END)

递归就是：
- "打开"：从大到小打开所有娃（这是递前的代码）
- "关闭"：从小到大关闭所有娃（这是递后的代码）
*/


//第二部分：Node（节点）
//什么是 Node？
//Node 是一个包含数据和指向下一个 Node 指针的结构。 它是构建链表的基本单元。
class node {
public:
    // 数据部分
    int data_;

    // 链接部分（指向下一个 node）
    node* link_;
};
//你代码中的 Node 类
class node {
public:
    // 构造函数：可以同时初始化 data 和 link
    // 默认值：data=0, link=nullptr
    node(int d = 0, node* l = nullptr) : data_(d), link_(l) {}

    // 获取数据
    int data() const { return data_; }

    // 获取链接（下一个 node 的地址）
    node* link() const { return link_; }

    // 修改数据
    void set_data(int val) { data_ = val; }

    // 修改链接
    void set_link(node* new_link) { link_ = new_link; }

private:
    int data_;      // 数据
    node* link_;    // 指针（地址）
};
//Node 的内存结构
/*
单个 Node 的样子：
┌──────────────────────┐
│ node 对象            │
├──────────────────────┤
│ data_: 42            │  ← 整数数据
├──────────────────────┤
│ link_: 0x2000        │  ← 指向下一个 node 的地址
└──────────────────────┘
     (地址: 0x1000)

link_ 指向的下一个 node：
                         ┌──────────────────────┐
                         │ node 对象            │
                         ├──────────────────────┤
                         │ data_: 15            │
                         ├──────────────────────┤
                         │ link_: nullptr       │  ← 没有下一个 node
                         └──────────────────────┘
                              (地址: 0x2000)
*/

//创建 Node：两种方式
//方式1：后到前构建（从后往前）
node* head = new node(2, nullptr);  // 创建最后一个 node：2->null
head = new node(4, head);           // 在前面插入：4->2->null
head = new node(6, head);           // 在前面插入：6->4->2->null

// 结果：6 -> 4 -> 2 -> null

//过程可视化：
/*
第1步：node(2, nullptr)
┌─────┐
│ 2   │
└─────┘

第2步：node(4, head) 将 head 指向新 node
┌─────┐         ┌─────┐
│ 4   │────────→│ 2   │
└─────┘         └─────┘

第3步：node(6, head) 将 head 指向新 node
┌─────┐         ┌─────┐         ┌─────┐
│ 6   │────────→│ 4   │────────→│ 2   │
└─────┘         └─────┘         └─────┘
(head)
*/

//方式2：前到后构建（从前往后）
node* h = new node(6, nullptr);  // 创建第一个 node：6->null
node* t = h;                      // tail 指向最后一个 node
// 现在 head=tail 都指向 6

t->set_link(new node(4, nullptr));  // 在 6 后面插入 4
t = t->link();                        // tail 向前移动到 4

t->set_link(new node(2, nullptr));  // 在 4 后面插入 2
t = t->link();                        // tail 向前移动到 2

// 结果：6 -> 4 -> 2 -> null

//过程可视化：
/*
第1步：new node(6, nullptr)
h,t
  ↓
┌─────┐
│ 6   │
└─────┘

第2步：t->set_link(new node(4, nullptr)); t = t->link();
h       t
│       ↓
└──→ ┌─────┐      ┌─────┐
     │ 6   │─────→│ 4   │
     └─────┘      └─────┘

第3步：t->set_link(new node(2, nullptr)); t = t->link();
h              t
│              ↓
└──→ ┌─────┐      ┌─────┐      ┌─────┐
     │ 6   │─────→│ 4   │─────→│ 2   │
     └─────┘      └─────┘      └─────┘
*/

//第三部分：链表的遍历
//方式1：使用 while 循环
void printList_While(node* head) {
    node* current = head;
    while (current != nullptr) {
        cout << current->data() << " ";
        current = current->link();  // 移动到下一个 node
    }
    cout << endl;
}

// 如果链表是 6->4->2->null
// 输出：6 4 2

//过程：
