#include <iostream>
#include "node.h"
using namespace std;

int main() {
    node* head = new node(4, nullptr);
    node* tail(head);
    node* temp;
    temp = new node(1, nullptr);
    tail->set_link(temp);
    tail = temp;
    head = new node(1, head);
    head = new node(3, head);
    temp = new node(5, nullptr);
    tail->set_link(temp);
    tail = temp;
	//3 1 4 1 5

    // test list_index()
    cout << "list_index" << endl;
	cout << list_index(head, 1) << endl;  //output: 1

    cout << "\nlist_at" << endl;

    // test list_at()
    node* temp0 = list_at(head, 0);
	cout << "index 0: " << temp0->data() << endl;    //output: 3 

    return 0;
}