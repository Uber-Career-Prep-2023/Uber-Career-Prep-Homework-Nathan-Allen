#include "../data_structures/DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

// Technique: Doubly Linked List forward-backward two pointer
// Traverse linked list twice:
// once to place pointer to last node, twice for forward and backward traversal 

// Time complexity: O(N) - traverse entire list of N nodes to N-1 index,
// Time taken: 20 minutes

bool isPalindrome(node_t* head) {
    if (head  == nullptr) {
        return true;
    }
    node_t* back = head;
    while (back != nullptr && back->next != nullptr) {
        back = back->next;
    }
    node_t* front = head;

    while (front != back) {
        if (front->data != back->data) {
            return false;
        }
        front = front->next;
        back = back->prev;
    }
    return true;
}

int main() {

    DoublyLinkedList dll;
    node_t* head = nullptr;

    head = dll.insertAtFront(head, 9);
    dll.insertAtBack(head, 2);
    dll.insertAtBack(head, 4);
    dll.insertAtBack(head, 2);
    dll.insertAtBack(head, 9);

    cout << "Is palindrome: " << isPalindrome(head) << endl;
    // prints 1 for True

    DoublyLinkedList dll2;
    node_t* head2 = nullptr;

    head2 = dll2.insertAtFront(head2, 9);
    dll2.insertAtBack(head2, 12);
    dll2.insertAtBack(head2, 4);
    dll2.insertAtBack(head2, 2);
    dll2.insertAtBack(head2, 9);

    cout << "Is palindrome: " << isPalindrome(head2) << endl;
    // prints 0 for False

    return 0;
}