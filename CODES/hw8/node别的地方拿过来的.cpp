// Implementations of linked list functionality declared in node.h
// Sara Krehbiel, 11/10/25-11/12/25

#include "node.h"

// note: untemplatized linked list toolkit functions were defined here

/*
Function 1. Write a function to recursively compute the nth item in the following sequence:
a0 = 1,a1 = 1, a2 = 2, a3 = 3, a4 = 5, a5 = 7, a6 = 10, a7 = 13, ..., where an = an−2 + n − 1 for n ≥ 2.
Your function must be recursive.
*/
int sequence(int n) {
	if (n == 0 || n == 1) {
		return 1;
	} else {
		return sequence(n - 2) + (n - 1);
	}
}

/*
Function 2. Write a function to recursively reverse the order of the elements in an array of integers.
The function will be called on an array, specifying the first and last index of the array to reverse.
Your array reversal should be in-place, meaning you should not allocate any additional arrays on the stack or on the heap.
Your function must be recursive.
*/
void reverseArray(int arr[], int first, int last) {
	if(first >= last) {
		return;
	}
	else {
		int temp = arr[first];
		arr[first] = arr[last];
		arr[last] = temp;
		reverseArray(arr, first + 1, last - 1);
	}
}

/*
Function 3. Write a function to recursively construct a linked list with contents as specified by an array with specified length.
Assume the initial recursive call is made with both head and tail set to null.
When it returns, the head pointer should be point to a node with data a[0] that links to a node with data a[1], and so on,
with the tail pointer pointing to a node with data a[n-1]. Your function must be recursive.
*/
template <typename T>
void arrayToList(const T a[], int n, node<T>*& head, node<T>*& tail) {
	if (n <= 0) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		// recursive call to construct the linked list of the rest of the array(n-1 elements)
		arrayToList(a, n - 1, head, tail);//a是数组，n-1是数组长度
		//create a new node for the n-1 element of the array(index n-1)
		node<T>* newNode = new node<T>;//创建一个新节点
		newNode->set_data(a[n - 1]);//设置新节点的数据为数组的第n-1个元素（也就是最后一个元素）
		newNode->set_link(nullptr);//新节点的链接指向nullptr，因为它是最后一个节点
		//if this is the first node
		if (head == nullptr) {
			head = newNode;
		}
		else {
			tail->set_link(newNode);
		}
		tail = newNode;
	}
}

/*
 Function 4. Write a function to recursively delete the memory for all nodes in a dynamically allocated
 linked list with head pointing to the first and tail pointing to the last node. The head and tail pointers should
 be null when the function is complete, and no memory should be orphaned. Your function must be recursive.
*/
template <typename T>
void deleteList(node<T>*& head, node<T>*& tail) {
	if (head == nullptr) {
		tail = nullptr;
		return;
	}
	else {
		node<T>* temp = head;//用temp保存head指针，防止丢失
		head = head->link();//head指向下一个节点
		delete temp;
		deleteList(head, tail);
	}
}