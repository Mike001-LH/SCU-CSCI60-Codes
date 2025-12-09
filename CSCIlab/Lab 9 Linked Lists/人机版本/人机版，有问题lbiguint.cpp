/*
Part A.  We’ll be working with the biguint class again.
You’ll be given a biguint class that uses a static array of fixed size,
and you’ll be changing it so that it uses a linked list.
You’ll be given the class definition of the linked list biguint class.  Write the following member functions
*/
/*1:
Make two files called lbiguint.h and lbiguint.cpp. 
To start, fill them in with the header for linked list biguint above, and the .cpp file for the regular biguint above.
Start by commenting out everything in both files except the constructors and member variables.
*/
#include "lbiguint.h"

#include <cassert>
#include <sstream>
using namespace std;

//2: Do the default constructor first (which initializes your lbiguint to 0).  Be sure to get your work checked before moving on.
lbiguint::lbiguint() {
	node* newN = new node(0,nullptr);
	head = tail = newN;
}
//3: Now do the string constructor.  
// They should allocate exactly as many nodes as is needed for the number of digits, with no leading zeros. 
// It should they store the biguint’s digits in a linked list, with the ones digit at the head of the list.
lbiguint::lbiguint(const string& s) {
    if (s.size() == 0) {
        head = tail = new node(0, nullptr);
        return;
    }

    // 忽略前导0
    int start = 0;
    while (start < s.size() && s[start] == '0') start++;
    if (start == s.size()) {
        head = tail = new node(0, nullptr);
        return;
    }

    head = tail = nullptr;

    // 从右向左插入：保证 head = ones digit
    for (int i = s.size() - 1; i >= start; --i) {
        int digit = s[i] - '0';
        node* newN = new node(digit, nullptr);
        if (head == nullptr) {
            head = tail = newN;
        }
        else {
            tail->set_link(newN);
            tail = newN;
        }
    }
}



//4: Write the destructor ~lbiguint(). 
lbiguint::~lbiguint() {
    while (head != nullptr) {
        node* curr = head->link();
        delete head;
        head = curr;
    }
}

//5: Modify the definitions for size(), the [] operator, and the non-member operator << from biguint to work for lbiguint.
//  Test your functions in your main(). 
int lbiguint::size() const {
    int count = 0;
    node* curr = head;
    while (curr != nullptr) {
        curr = curr->link();
        count++;
    }
    return count;
}

int lbiguint::operator [](int pos) const {
    int count = 0;
    node* curr = head;
    while (curr != nullptr) {
        if(count==pos){
            return curr->data();
        }
        else {
            curr = curr->link();
        }
        count++;
    }
    return 0;
}

ostream& operator << (ostream& o, const lbiguint& l) {
    for(int i=l.size()-1; i>=0; i--){
        o << l[i];
    }
    return o;
}

//6: Write the = operator and the copy constructor. Test your functions in your main().
void lbiguint::operator =(const lbiguint& l) {
    if (this == &l) return;  // 修复 1：自赋值保护

    // 清空旧链表
    while (head != nullptr) {
        node* curr = head->link();
        delete head;
        head = curr;
    }
    tail = nullptr;

    if (l.head == nullptr) { // 防御性
        head = tail = new node(0, nullptr);
        return;
    }

    // 正确深拷贝：按链表顺序复制
    head = new node(l.head->data(), nullptr);
    tail = head;

    const node* cur = l.head->link();
    while (cur != nullptr) {
        node* newNode = new node(cur->data(), nullptr);
        tail->set_link(newNode);
        tail = newNode;
        cur = cur->link();
    }
}

//lbiguint::lbiguint(const lbiguint& b) {
//    head = nullptr;
//    tail = nullptr;
//    node* temp = b.head;
//    while (temp != nullptr) {
//        node* newN = temp;
//        head->set_link(newN);
//        head = newN;
//        temp = temp->link();
//    }
//}
lbiguint::lbiguint(const lbiguint& b) {
	//first create a temperary node to represent 0, so that we can easily add new nodes after it
	node* newN = new node(0, nullptr);
	head = tail = newN;
	//now we will copy everything from b.head to this linked list
	node* temp = b.head;
    while (temp != nullptr) {
		node* newNode = new node(temp->data(), nullptr);
		tail->set_link(newNode);//link the new node to the end of the list
		tail = newNode;
		temp = temp->link();
    }
	//finally, we need to remove the first node (the temporary 0 node)
	node* first = head->link();
	delete head;
    if (first != nullptr) {
		head = first;
    }
    else {
		head = tail = new node(0, nullptr);//if b was 0, we need to make sure this linked list is also 0
    }
}


