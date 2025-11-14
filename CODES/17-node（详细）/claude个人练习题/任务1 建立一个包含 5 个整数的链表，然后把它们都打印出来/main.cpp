#include <iostream>
#include "practise.h"
using namespace std;

int main() {
	// Create 5 nodes with data 6, 4, 2, 8, 10
	node* n1 = new node(6, nullptr);
	node* n2 = new node(4, nullptr);
	node* n3 = new node(2, nullptr);
	node* n4 = new node(8, nullptr);
	node* n5 = new node(10, nullptr);
	// Link the nodes together to form a linked list
	n1->set_link(n2);// 6 -> 4
	n2->set_link(n3);// 4 -> 2
	n3->set_link(n4);// 2 -> 8
	n4->set_link(n5);// 8 -> 10
	//最后是n5指向nullptr，表示链表结束，完整的链表是：6 -> 4 -> 2 -> 8 -> 10 -> nullptr
	// Print the linked list
	node* current = n1; // Start from the head node
	while (current != nullptr) {
		cout << current->data(); // Print the data of the current node
		current = current->link(); // Move to the next node
	}
}