// Main program to demonstrate all 15 problems
// Mike's practice problems for CSCI 60
#include "node.h"
#include <iostream>
using std::cout;
using std::endl;

// Helper function to print list
void print_list(const node* h) {
    cout << h;
    cout << endl;
}

// Helper function to delete entire list
void list_clear(node*& h, node*& t) {
    while (h != nullptr) {
        node* temp = h;
        h = h->link();
        delete temp;
    }
    t = nullptr;
}

// ============================================================================
// Problem 1: Create and print a simple linked list
// ============================================================================
void problem1_createAndPrint() {
    cout << "\n========== Problem 1: Create and Print ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    // Manually create nodes
    head = new node(1, nullptr);
    head->set_link(new node(2, nullptr));
    head->link()->set_link(new node(3, nullptr));
    tail = head->link()->link();

    cout << "List contents: ";
    print_list(head);

    list_clear(head, tail);
}

// ============================================================================
// Problem 2: Calculate list size
// ============================================================================
void problem2_getLength() {
    cout << "\n========== Problem 2: Calculate List Size ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 4);

    cout << "List contents: ";
    print_list(head);
    cout << "List size: " << list_size(head, tail) << endl;

    list_clear(head, tail);
}

// ============================================================================
// Problem 3: Search for a value
// ============================================================================
void problem3_findNode() {
    cout << "\n========== Problem 3: Search for Value ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 5);

    cout << "List contents: ";
    print_list(head);

    cout << "Searching for 3: " << (list_search(head, tail, 3) ? "Found" : "Not found") << endl;
    cout << "Searching for 4: " << (list_search(head, tail, 4) ? "Found" : "Not found") << endl;

    list_clear(head, tail);
}

// ============================================================================
// Problem 4: Insert at head and tail
// ============================================================================
void problem4_insertHeadAndTail() {
    cout << "\n========== Problem 4: Insert at Head and Tail ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    cout << "Inserting 2, 3, 4 at tail: ";
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 4);
    print_list(head);

    cout << "Inserting 1 at head: ";
    list_insert_head(head, tail, 1);
    print_list(head);

    cout << "Inserting 5 at tail: ";
    list_insert_tail(head, tail, 5);
    print_list(head);

    list_clear(head, tail);
}

// ============================================================================
// Problem 5: Delete node
// ============================================================================
void problem5_deleteNode() {
    cout << "\n========== Problem 5: Delete Node ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 4);

    cout << "Before deletion: ";
    print_list(head);

    list_delete(head, tail, 3);
    cout << "After deleting 3: ";
    print_list(head);

    list_clear(head, tail);
}

// ============================================================================
// Problem 6: Reverse list
// ============================================================================
void problem6_reverseList() {
    cout << "\n========== Problem 6: Reverse List ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 4);

    cout << "Before reversal: ";
    print_list(head);

    list_reverse(head, tail);
    cout << "After reversal: ";
    print_list(head);

    list_clear(head, tail);
}

// ============================================================================
// Problem 7: Print forward (recursive)
// ============================================================================
void problem7_printForward() {
    cout << "\n========== Problem 7: Print Forward (Recursive) ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 4);

    cout << "List contents (recursive): ";
    list_print_forward(head);
    cout << endl;

    list_clear(head, tail);
}

// ============================================================================
// Problem 8: Print backward (recursive)
// ============================================================================
void problem8_printBackward() {
    cout << "\n========== Problem 8: Print Backward (Recursive) ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 4);

    cout << "List contents (recursive backward): ";
    list_print_backward(head);
    cout << endl;

    list_clear(head, tail);
}

// ============================================================================
// Problem 9: Recursive sum
// ============================================================================
void problem9_sumList() {
    cout << "\n========== Problem 9: Recursive Sum ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 4);

    cout << "List contents: ";
    print_list(head);
    cout << "Sum of all values: " << list_sum(head) << endl;

    list_clear(head, tail);
}

// ============================================================================
// Problem 10: Find max (recursive)
// ============================================================================
void problem10_findMax() {
    cout << "\n========== Problem 10: Find Maximum (Recursive) ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 3);
    list_insert_tail(head, tail, 7);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 5);

    cout << "List contents: ";
    print_list(head);
    cout << "Maximum value: " << list_find_max(head) << endl;

    list_clear(head, tail);
}

// ============================================================================
// Problem 11: Remove duplicates
// ============================================================================
void problem11_removeDuplicates() {
    cout << "\n========== Problem 11: Remove Duplicates ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 3);

    cout << "Before removing duplicates: ";
    print_list(head);

    list_remove_duplicates(head);
    cout << "After removing duplicates: ";
    print_list(head);

    list_clear(head, tail);
}

// ============================================================================
// Problem 12: Merge two sorted lists
// ============================================================================
void problem12_mergeSortedLists() {
    cout << "\n========== Problem 12: Merge Sorted Lists ==========" << endl;

    node* list1 = nullptr;
    node* tail1 = nullptr;
    node* list2 = nullptr;
    node* tail2 = nullptr;

    // Create first list: 1 -> 3 -> 5
    list_insert_tail(list1, tail1, 1);
    list_insert_tail(list1, tail1, 3);
    list_insert_tail(list1, tail1, 5);

    // Create second list: 2 -> 4 -> 6
    list_insert_tail(list2, tail2, 2);
    list_insert_tail(list2, tail2, 4);
    list_insert_tail(list2, tail2, 6);

    cout << "List 1: ";
    print_list(list1);
    cout << "List 2: ";
    print_list(list2);

    node* merged = list_merge(list1, list2);
    cout << "Merged list: ";
    print_list(merged);

    // Clear merged list
    node* temp = nullptr;
    list_clear(merged, temp);
}

// ============================================================================
// Problem 13: Check if palindrome
// ============================================================================
void problem13_isPalindrome() {
    cout << "\n========== Problem 13: Check Palindrome ==========" << endl;

    // Test palindrome list: 1 -> 2 -> 2 -> 1
    node* list1 = nullptr;
    node* tail1 = nullptr;
    list_insert_tail(list1, tail1, 1);
    list_insert_tail(list1, tail1, 2);
    list_insert_tail(list1, tail1, 2);
    list_insert_tail(list1, tail1, 1);

    cout << "List 1: ";
    print_list(list1);
    cout << "Is palindrome: " << (list_is_palindrome(list1) ? "Yes" : "No") << endl;

    node* temp1 = nullptr;
    list_clear(list1, temp1);

    // Test non-palindrome list: 1 -> 2 -> 3
    node* list2 = nullptr;
    node* tail2 = nullptr;
    list_insert_tail(list2, tail2, 1);
    list_insert_tail(list2, tail2, 2);
    list_insert_tail(list2, tail2, 3);

    cout << "\nList 2: ";
    print_list(list2);
    cout << "Is palindrome: " << (list_is_palindrome(list2) ? "Yes" : "No") << endl;

    node* temp2 = nullptr;
    list_clear(list2, temp2);
}

// ============================================================================
// Problem 14: Bubble sort
// ============================================================================
void problem14_bubbleSortList() {
    cout << "\n========== Problem 14: Bubble Sort ==========" << endl;

    node* head = nullptr;
    node* tail = nullptr;

    list_insert_tail(head, tail, 4);
    list_insert_tail(head, tail, 2);
    list_insert_tail(head, tail, 5);
    list_insert_tail(head, tail, 1);
    list_insert_tail(head, tail, 3);

    cout << "Before sorting: ";
    print_list(head);

    list_bubble_sort(head);
    cout << "After sorting: ";
    print_list(head);

    list_clear(head, tail);
}

// ============================================================================
// Problem 15: Tree traversal
// ============================================================================
void problem15_treeTraversal() {
    cout << "\n========== Problem 15: Binary Tree Traversals ==========" << endl;

    // Create tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    tree_node* root = new tree_node(1);
    root->set_left(new tree_node(2));
    root->set_right(new tree_node(3));
    root->left()->set_left(new tree_node(4));
    root->left()->set_right(new tree_node(5));

    cout << "Preorder traversal: ";
    tree_preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    tree_inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree_postorder(root);
    cout << endl;

    tree_delete(root);
}

// ============================================================================
// Main function
// ============================================================================
int main() {
    cout << "================================" << endl;
    cout << "C++ Node Problems 1-15" << endl;
    cout << "CSCI 60 Practice" << endl;
    cout << "================================" << endl;

    // Run all problems
    problem1_createAndPrint();
    problem2_getLength();
    problem3_findNode();
    problem4_insertHeadAndTail();
    problem5_deleteNode();
    problem6_reverseList();
    problem7_printForward();
    problem8_printBackward();
    problem9_sumList();
    problem10_findMax();
    problem11_removeDuplicates();
    problem12_mergeSortedLists();
    problem13_isPalindrome();
    problem14_bubbleSortList();
    problem15_treeTraversal();

    cout << "\n================================" << endl;
    cout << "All problems completed!" << endl;
    cout << "================================" << endl;

    return 0;
}