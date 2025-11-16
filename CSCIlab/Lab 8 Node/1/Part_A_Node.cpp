#include <iostream>

#include "node.h"

using namespace std;

int main(){
	node* head = new node(4, nullptr);// create the first node // head -> [4 | nullptr]
	node* tail(head);// make tail point to head // head -> [4 | nullptr] <- tail
	node* temp;//create a temp pointer // temp is uninitialized
	temp = new node(1, nullptr); // head -> [4 | nullptr] <- tail   temp -> [1 | nullptr]
	tail->set_link(temp);// link tail to temp // head -> [4 | *-] -> [1 | nullptr] <- temp
	                                          //            ↑
	                                          //          tail
	tail = temp;// move tail to point to temp // head -> [4 | *-] -> [1 | nullptr] <- tail
	head = new node(1, head);// insert new node at head // head -> [1 | *-] -> [4 | *-] -> [1 | nullptr] <- tail
	head = new node(3, head);// insert new node at head // head -> [3 | *-] -> [1 | *-] -> [4 | *-] -> [1 | nullptr] <- tail
	temp = new node(5, nullptr);// create new node // head -> [3 | *-] -> [1 | *-] -> [4 | *-] -> [1 | nullptr] <- tail   temp -> [5 | nullptr]
	tail->set_link(temp);// link tail to temp // head -> [3 | *-] -> [1 | *-] -> [4 | *-] -> [1 | *-] -> [5 | nullptr] <- temp
											  //                                              ↑
											  //                                            tail
	tail = temp;// move tail to point to temp // head -> [3 | *-] -> [1 | *-] -> [4 | *-] -> [1 | *-] -> [5 | nullptr] <- tail

	for (const node* p = head; p != nullptr; p = p->link())
		cout << p->data() << " ";
	cout << endl;
	return 0;
}
