#include "node.h"

node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}

//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}

/*2:
Write a function
std::size_t list_index(node * head_ptr, int target);
that returns the index of the first occurrence  of target in the linked list stored at head_ptr.
Copy your code into your lab report.  Be sure to get your work checked before moving on.
*/
std::size_t list_index(node* head_ptr, int target) {
    size_t index = 0;
    const node* curr = head_ptr;
    while (curr != nullptr) {
        if (curr->data() == target) {
            return index;
        }
        else {
            index++;
            curr = curr->link();// 移动到下一个节点
        }
    }
    return -1;//it will wrap around to the max of size_t
}

/*3:
Write a function
node* list_at(node * head_ptr, std::size_t n);    that returns a pointer to the nth node.
*/
node* list_at(node* head_ptr, std::size_t n) {
	node* curr = head_ptr;
    size_t track = 0;
    while (curr != nullptr) {
        if (track == n) {
            return curr;
        }
        else {
            track++;
            curr = curr->link();
        }
    }
    return nullptr;
}

/*4: 
Look back at your functions from parts 2 and 3.  
Now that you’ve written list_at, and assuming you have a function list_size that gives you the number of nodes in the linked list,
you could loop over a linked list the way we loop over arrays:

for(int i=0; i<list_size(head); i++){
  node* temp = list_at(head, i);
  cout<<temp->data()<<endl;
}
*/
//answer:
//This is a silly way because it is inefficient, in the for loop, every time i++, list_size(head) and list_at(head, i) both works again, so inefficient.


/*5:
Which would be more efficient for a program that infrequently modifies its data (adding and deleting items)
but often accesses its data; an array (dynamic or static) or a linked list? 
Which would be more efficient for a program that frequently modifies its data (adding and deleting items) but infrequently accesses its data?
Type your answer into your lab report.  Be sure to get your work checked before moving on.
*/
//answer:
//link list would be more efficient in modifying elements because the new value can just be simply put after the tail with nullptr, for an array we have to increase size, reallocate array and copy the values to add one single value
//array would be more efficient in accessing elements because simply using [] can return the value, link list has to do extra work












