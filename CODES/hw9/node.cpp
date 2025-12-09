// Node implementation starter file for CSCI 60 Homework 9; due Thursday 12/4/25
// List any collaborators and write your name here

#include "node.h" // Don't add any additional libraries/namespaces!

// overloaded << to print entire list
ostream& operator <<(ostream& out, const node * head) {
  if (head==nullptr) return out;
  return out << head->data() << ", " << head->link();
}

// traverses through list, keeping track of and then returning # nodes
size_t list_size(const node* head) {
  if (head==nullptr) return 0;
  return 1+list_size(head->link());
}

// traverses through list, returning true if given val is found, false otherwise
bool list_search(const node* head, int val) {
  if (head==nullptr) return false;
  if (head->data()==val) return true;
  return list_search(head->link(),val);
}

// deletes all nodes associated with a list and sets head and tail to nullptr
void list_clear(node*& head, node*& tail) {
  node* next;//temporary pointer to hold next node
  while (head!=nullptr) {
    next=head->link();
    delete head;
    head=next;
  }
  tail=nullptr;
}

// inserts a node with specified value at the head (beginning/front) of a list
void list_insert_head(node*& head, node*& tail, int val) {
  head = new node(val,head);
  if (tail==nullptr) tail = head;
}

// inserts a node with specified value at the tail (end/back) of a list
void list_insert_tail(node*& head, node*& tail, int val) {
  node *temp = new node(val,nullptr);
  if (tail==nullptr) {
    head = tail = temp;
  } else {
    tail->set_link(temp);
    tail = tail->link();
  }
}

// MILESTONE 1: implement list_insert_sorted 
//list goes from head to tail, for example: 1->3->5->7
void list_insert_sorted(node*& head, node*& tail, int val) {
    //if the list is empty or the new value is less than or equal to the head value, insert at head
    if (head == nullptr || val <= head->data()) {
        list_insert_head(head, tail, val);
		return;//end the function, no need to continue
    }
    node* current = head;
	//当前节点的下一个节点不为空且下一个节点的值小于要插入的值时，继续向后遍历
    while (current->link() != nullptr && val > current->link()->data()) { current = current->link(); }//find the position to insert
	//遍历完后，current指向第一个大于等于val的节点的前一个节点，比方说要插入4，遍历后current指向3
	node* newNode = new node(val, current->link());//创建新节点，指向第一个大于等于val的节点，例子中指向5
	current->set_link(newNode);//将current的下一个节点指向新节点，得到1->3->4->5->7 //注意，set_link的作用是改变一个节点指向的下一个节点，所以这里相当于把3的下一个节点从5改成了4，然后4的下一个节点是5
    if(newNode->link() == nullptr) {//if we inserted at the end, update tail
        tail = newNode;
	}
}