// This is a test file used while developing a linked list toolkit.
// Sara Krehbiel, 11/10/25

#include <iostream>
#include "node.h" 
using namespace std;


void oldNodeCode();
void newNodeCode();
void printList(node* head);
void printListRec(node* head);

int main() {
  oldNodeCode();
  newNodeCode();
	return 0;
}

// 核心成员函数解析：
// link()     返回当前节点指向的下一个节点的地址 (node*)
// set_link() 设置当前节点指向的下一个节点的地址
// data()     返回当前节点的数据成员
// set_data() 设置当前节点的数据成员
// ->         操作符，用于指针访问成员：ptr->fn() 等价于 (*ptr).fn()


// Week 7 code with new syntax and common strategies for linked lists
void oldNodeCode() {
  // build a list 6->4->2 from the back to the front
  node *head = new node(2,nullptr); // head points to a single node with data 2
  //head → [2|nullptr]
  node *tail = head; // head and tail are the same for a 1-elem list
  //head → [2|nullptr] ← tail
  head = new node(4,head); // NOTE: rhs is evaluated first, assigned second
  //head → [4|•] → [2|nullptr] ← tail
  head = new node(6,head);
  //head → [6|•] → [4|•] → [2|nullptr] ← tail

  // build a list 6->4->2 from front to back
  node *h = new node(6,nullptr), *t = h;
  //h → [6|nullptr] ← t

  // first explore with new syntax and different ways to order commands:

  // update tail to point to new node, then find old tail and relink it
  t = new node(4,nullptr); // set tail to point to the next node
  //h → [6|nullptr]   t → [4|nullptr]
  
  // NEW SYNTAX: ptr->fn() dereferences and applies dot operator in one step//翻译： ptr->fn()解引用并一步运用dot operator
  //             (*ptr).fn() is what we'd have to do without ->             //			 (*ptr).fn()是我们没有->时必须做的
  h->set_link(t); // same as (*h).set_link(t) -- update first node link to next //和(*h).set_link(t)一样，更新第一个节点链接到下一个节点
  //set_link()是最后要在哪个节点上修改连接，所以这里是h节点h → [6|•]
  // h → [6|•] → [4|nullptr] ← t

  // do this again for the third node
  t = new node(2,nullptr); 
  //h → [6|•] → [4|nullptr]   t → [2|nullptr]
  
  // NOW: have to find the old tail to link it to the new tail
  h->link()->set_link(t);//same as (*(*h).link()).set_link(t); YUCK! 
  //link()代表h节点的下一个节点，也就是4节点，然后用set_link(t)把4节点的链接指向2节点
  //h → [6|•] → [4|•] → [2|nullptr] ← t

  // how does this look if we keep going to add a fourth node?
  t = new node(0,nullptr);
  //h → [6|•] → [4|•] → [2|nullptr]   t → [0|nullptr]
  h->link()->link()->set_link(t); // traverse multiple nodes to find old tail
  //h → [6|•] → [4|•] → [2|•] → [0|nullptr] ← t

  // OR use a temp variable so we can remember old tail in order to relink it//我们也可以创建临时变量来记住旧尾节点以便重新链接
  node *newTail = new node(-2,nullptr); // 1. construct new node
  //h → [6|•] → [4|•] → [2|•] → [0|nullptr] ← t   newTail → [-2|nullptr]
  t->set_link(newTail); // 2. link old tail node to it
  // h → [6|•] → [4|•] → [2|•] → [0|•] → [-2|nullptr]
  //                               ↑
  //                               t
  t = newTail; // 3. update t pointer to point to new last node
  //h → [6|•] → [4|•] → [2|•] → [0|•] → [-2|nullptr] ← t（现在移到[-2]处）

  // settle on clean code: avoids extra variables and traversing multiple nodes

  // link the old tail to a new node, then update t to point to the new one
  t->set_link(new node(-4,nullptr)); // 1. make new node, 2. relink old tail node
  // h → [6|•] → [4|•] → [2|•] → [0|•] → [-2|•] → [-4|nullptr] 
  //								        ↑
  //								        t
  t = t->link(); // 3. update t pointer to point to new last node
  // h → [6|•] → [4|•] → [2|•] → [0|•] → [-2|•] → [-4|nullptr] ← t

  // do it again!
  t->set_link(new node(-6,nullptr)); 
  // h → [6|•] → [4|•] → [2|•] → [0|•] → [-2|•] → [-4|•] → [-6|nullptr]
  //								                ↑
  //								                t
  t = t->link(); 
  // h → [6|•] → [4|•] → [2|•] → [0|•] → [-2|•] → [-4|•] → [-6|nullptr] ← t

  cout << "The contents of the first list, printed multiple ways:\n";
  cout << "With explicit main code: ";
  // use accessors to get the three pieces of data starting with the head
  cout << head->data() << " "; // data of first node (addressed by head)//输出：head指向的第一个节点的数据，6
  cout << head->link()->data() << " "; // data of second node //输出：head指向的第二个节点的数据，4
  cout << head->link()->link()->data() << endl; // OR use tail->data() //输出：head指向的第三个节点的数据，2

  cout << "With a printList function: ";
  printList(head); // iterative implementation (while loop or for loop)//迭代实现（while循环或for循环）

  cout << "Now recursively! ";
  printListRec(head); // recursive implementation//递归实现

  // TODO: learn about const pointers and add const wherever appropriate!

  // TODO: declare linked list toolkit functions in node.h, define in node.cpp

  cout << "NEXT: overload << for node*\n"; // TODO: overload << in node.cpp
  cout << head << endl; // TODO: implement with a loop, then recursively

  cout << "What will happen to the list when nodeCode returns?\n";
  delete head; // this only frees the first node in the list!
}

void newNodeCode() {
  // TODO: rewrite week 7 functionality after implementing list_insert_head, 
  //       list_insert_tail, and << (iteratively and recursively) in node.cpp
}

// an iterative function that prints each piece of data (in order) in the list
void printList(node* curr) { // TODO: see what breaks if we declare node *const //curr是传入的链表的头节点
  //curr->set_link(nullptr); // TODO: see how this breaks if we use const
  for (; curr != nullptr; curr = curr->link()) {//遍历链表直到curr为空
    cout << curr->data() << " ";//输出当前节点的数据
  }
  cout << endl;
}

// a recursive function that prints each piece of data (in order) in the list
void printListRec(node* curr) {
  if (curr==nullptr) { // base case is the stopping condition for recursion//递归的停止条件，如果当前节点为空，停止
    cout << endl; // advance curser once list is printed and recursion stops
    return;
  }
  cout << curr->data() << " "; // one piece of work (on the way up the stack!)//输出当前节点的数据
  printListRec(curr->link()); // recursively print list starting from next node//递归调用，传入下一个节点
}