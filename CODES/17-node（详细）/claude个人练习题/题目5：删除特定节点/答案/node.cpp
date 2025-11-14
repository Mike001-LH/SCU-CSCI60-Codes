// Implementation of node class and linked list toolkit functions
// Mike's practice problems for CSCI 60
#include "node.h"
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

// ============================================================================
// Output Operator
// ============================================================================

ostream& operator <<(ostream& o, const node* n) {
    while (n != nullptr) {
        o << n->data() << " ";
        n = n->link();
    }
    return o;
}

// ============================================================================
// Basic Operations
// ============================================================================

// Problem 4: Insert at head
void list_insert_head(node*& h, node*& t, int val) {
    node* new_node = new node(val, h);
    h = new_node;
    if (t == nullptr) {  // if list was empty
        t = new_node;
    }
}

// Problem 4: Insert at tail
void list_insert_tail(node*& h, node*& t, int val) {
    node* new_node = new node(val, nullptr);
    if (h == nullptr) {  // if list is empty
        h = new_node;
        t = new_node;
    }
    else {
        t->set_link(new_node);
        t = new_node;
    }
}

// Problem 2: Calculate list size
size_t list_size(const node* h, const node* t) {
    size_t count = 0;
    const node* current = h;
    while (current != nullptr) {
        count++;
        current = current->link();
    }
    return count;
}

// Problem 3: Search for value
bool list_search(const node* h, const node* t, int val) {
    const node* current = h;
    while (current != nullptr) {
        if (current->data() == val) {
            return true;
        }
        current = current->link();
    }
    return false;
}

// ============================================================================
// Intermediate Operations
// ============================================================================

// Problem 5: Delete node
void list_delete(node*& h, node*& t, int val) {
    // Case 1: Delete head node
    if (h != nullptr && h->data() == val) {
        node* temp = h;
        h = h->link();
        delete temp;
        if (h == nullptr) {  // list is now empty
            t = nullptr;
        }
        return;
    }

    // Case 2: Delete other nodes
    node* current = h;
    while (current != nullptr && current->link() != nullptr) {
        if (current->link()->data() == val) {
            node* temp = current->link();
            current->set_link(current->link()->link());
            delete temp;
            if (current->link() == nullptr) {  // updated tail
                t = current;
            }
            return;
        }
        current = current->link();
    }
}

// Problem 6: Reverse list
void list_reverse(node*& h, node*& t) {
    node* prev = nullptr;
    node* current = h;
    node* old_h = h;

    while (current != nullptr) {
        node* next = current->link();
        current->set_link(prev);
        prev = current;
        current = next;
    }

    h = prev;
    t = old_h;
}

// ============================================================================
// Recursive Operations
// ============================================================================

// Problem 7: Print forward (recursive)
void list_print_forward(const node* n) {
    if (n == nullptr) {
        return;
    }
    cout << n->data() << " ";
    list_print_forward(n->link());
}

// Problem 8: Print backward (recursive)
void list_print_backward(const node* n) {
    if (n == nullptr) {
        return;
    }
    list_print_backward(n->link());
    cout << n->data() << " ";
}

// Problem 9: Recursive sum
int list_sum(const node* n) {
    if (n == nullptr) {
        return 0;
    }
    return n->data() + list_sum(n->link());
}

// Problem 10: Find max (recursive)
int list_find_max(const node* n) {
	//assert(n != nullptr);  // assumes list is not empty //assert的意思是：当 condition 为 false 时，程序立刻停止运行并报错。
    if (n == nullptr) {
        // 空链表怎么办？
        // 通常可以抛异常、返回最小值、或者让调用者保证不空
        // 这里我们可以暂时选择 return INT_MIN;
        return INT_MIN;
    }

    if (n->link() == nullptr) {
        return n->data();
    }

	int max_of_rest = list_find_max(n->link());//递归调用，将max_of_rest设为从下一个节点开始的子链表中的最大值。
	return n->data() > max_of_rest ? n->data() : max_of_rest;//这个三目运算符的意思是，如果 n->data() 大于 max_of_rest，则返回 n->data()，否则返回 max_of_rest。
}

// ============================================================================
// Advanced Operations
// ============================================================================

// Problem 11: Remove duplicates (assumes sorted list)//移除重复节点（假设链表已排序）
void list_remove_duplicates(node*& h) {
	node* current = h;//先将 current 指向链表的头节点h，后面用来遍历链表。
	while (current != nullptr && current->link() != nullptr) {//当 current 不为空且 current 的下一个节点不为空时，继续循环。
		if (current->data() == current->link()->data()) {//如果当前节点的值等于下一个节点的值，说明有重复节点。
			node* temp = current->link();//将重复节点保存到 temp 变量中，以便后续删除。
			current->set_link(current->link()->link());//将 current 的链接指向下下个节点，跳过重复节点。
			delete temp;//删除重复节点，释放内存。
        }
        else {
			current = current->link();//如果没有重复，继续向后遍历。
        }
    }
}

// Problem 12: Merge two sorted lists (recursive)
node* list_merge(node* h1, node* h2) {
    if (h1 == nullptr) {
        return h2;
    }
    if (h2 == nullptr) {
        return h1;
    }

    node* merged;
    if (h1->data() <= h2->data()) {
        merged = h1;
        merged->set_link(list_merge(h1->link(), h2));
    }
    else {
        merged = h2;
        merged->set_link(list_merge(h1, h2->link()));
    }
    return merged;
}

// Problem 13: Check if palindrome
// Helper function for palindrome check
bool list_is_palindrome_helper(const node*& left, const node* right) {
    if (right == nullptr) {
        return true;
    }

    bool is_palin = list_is_palindrome_helper(left, right->link());
    if (!is_palin) {
        return false;
    }

    bool result = (left->data() == right->data());
    left = left->link();
    return result;
}

bool list_is_palindrome(const node* h) {
    return list_is_palindrome_helper(h, h);
}

// Problem 14: Bubble sort
void list_bubble_sort(node*& h) {
    if (h == nullptr || h->link() == nullptr) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        node* current = h;
        while (current != nullptr && current->link() != nullptr) {
            if (current->data() > current->link()->data()) {
                // Swap data
                int temp = current->data();
                current->set_data(current->link()->data());
                current->link()->set_data(temp);
                swapped = true;
            }
            current = current->link();
        }
    } while (swapped);
}

// ============================================================================
// Tree Operations
// ============================================================================

// Problem 15: Preorder traversal
void tree_preorder(const tree_node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data() << " ";
    tree_preorder(root->left());
    tree_preorder(root->right());
}

// Problem 15: Inorder traversal
void tree_inorder(const tree_node* root) {
    if (root == nullptr) {
        return;
    }
    tree_inorder(root->left());
    cout << root->data() << " ";
    tree_inorder(root->right());
}

// Problem 15: Postorder traversal
void tree_postorder(const tree_node* root) {
    if (root == nullptr) {
        return;
    }
    tree_postorder(root->left());
    tree_postorder(root->right());
    cout << root->data() << " ";
}

// Delete tree
void tree_delete(tree_node* root) {
    if (root == nullptr) {
        return;
    }
    tree_delete(root->left());
    tree_delete(root->right());
    delete root;
}