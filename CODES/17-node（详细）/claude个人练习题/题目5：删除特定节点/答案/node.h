// Node class definition with linked list toolkit functions
// Mike's practice problems for CSCI 60
#ifndef NODE_H
#define NODE_H
#include <iostream>
using std::ostream;

class node {
public:
    // constructors
    node() : data_(0), link_(nullptr) {}
    node(int initdata, node* initlink) : data_(initdata), link_(initlink) {}
    // accessors
    int data() const { return data_; }
    node* link() const { return link_; }
    // mutators
    void set_data(int val) { data_ = val; }
    void set_link(node* new_link) { link_ = new_link; }
private:
    int data_;
    node* link_;
};

// output operator
ostream& operator <<(ostream& o, const node* n);

// ============================================================================
// Basic Operations
// ============================================================================

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: t is the same, h points to a newly constructed first node
void list_insert_head(node*& h, node*& t, int val);

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: h is the same, t points to a newly constructed last node
void list_insert_tail(node*& h, node*& t, int val);

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: the list is unchanged, the #nodes in list is returned
size_t list_size(const node* h, const node* t);

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: the list is unchanged, return true iff val is in the list
bool list_search(const node* h, const node* t, int val);

// ============================================================================
// Intermediate Operations
// ============================================================================

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: first node with value val is removed, h and t are updated
// note: if val not found, list remains unchanged
void list_delete(node*& h, node*& t, int val);

// pre: h and t point to first and last node of a linked list (possibly empty)
// post: the list is reversed, h and t are updated
void list_reverse(node*& h, node*& t);

// ============================================================================
// Recursive Operations
// ============================================================================

// pre: n points to a node or nullptr
// post: list from n onwards is printed in forward order
void list_print_forward(const node* n);

// pre: n points to a node or nullptr
// post: list from n onwards is printed in reverse order
void list_print_backward(const node* n);

// pre: n points to a node or nullptr
// post: sum of all values in list from n onwards is returned
int list_sum(const node* n);

// pre: n points to a node or nullptr
// post: maximum value in list from n onwards is returned
// note: assumes list is not empty
int list_find_max(const node* n);

// ============================================================================
// Advanced Operations
// ============================================================================

// pre: h points to first node of a sorted linked list (possibly empty)
// post: all duplicate consecutive values are removed, h is updated
void list_remove_duplicates(node*& h);

// pre: h1 and h2 point to first nodes of sorted lists (possibly empty)
// post: the two lists are merged into one sorted list
// post: a new head pointer to merged list is returned
// note: modifies the original lists' pointers
node* list_merge(node* h1, node* h2);

// pre: h points to first node of a linked list (possibly empty)
// post: return true iff the list is a palindrome
bool list_is_palindrome(const node* h);

// pre: h points to first node of a linked list (possibly empty)
// post: the list is sorted in ascending order using bubble sort
void list_bubble_sort(node*& h);

// ============================================================================
// Tree Node and Tree Operations (for problem 15)
// ============================================================================

class tree_node {
public:
    // constructors
    tree_node() : data_(0), left_(nullptr), right_(nullptr) {}
    tree_node(int initdata, tree_node* initleft = nullptr, tree_node* initright = nullptr)
        : data_(initdata), left_(initleft), right_(initright) {
    }
    // accessors
    int data() const { return data_; }
    tree_node* left() const { return left_; }
    tree_node* right() const { return right_; }
    // mutators
    void set_data(int val) { data_ = val; }
    void set_left(tree_node* new_left) { left_ = new_left; }
    void set_right(tree_node* new_right) { right_ = new_right; }
private:
    int data_;
    tree_node* left_;
    tree_node* right_;
};

// pre: root points to tree node or nullptr
// post: tree is printed in preorder (root, left, right)
void tree_preorder(const tree_node* root);

// pre: root points to tree node or nullptr
// post: tree is printed in inorder (left, root, right)
void tree_inorder(const tree_node* root);

// pre: root points to tree node or nullptr
// post: tree is printed in postorder (left, right, root)
void tree_postorder(const tree_node* root);

// pre: root points to tree node or nullptr
// post: dynamically allocated tree is deleted
void tree_delete(tree_node* root);

#endif // NODE_H