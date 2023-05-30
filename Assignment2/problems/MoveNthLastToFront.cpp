#include "../data_structures/SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

// Technique: Traverse linked list twice to calculate length 
//and then traverse again to find nth node from end

// Time complexity: O(N) - traverse entire list of N nodes to N-1 index,
// Time taken: ~30 minutes


node_t* MoveNthLastToFront(node_t* head, int k)
{
    if (head == nullptr) {
        return head;
    }
    node_t* curr = head;
    int length = 0;

    // calculate length of list
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }

    // if k is greater than length of list, do nothing
    if (length == 1 || k > length) {
        return head;
    }
    curr = head;

    // traverse to node before kth node from end
    for (int i = 1; i < length - k; i++) {
        curr = curr->next;
    }

    
    node_t* tmp = curr->next;
    curr->next = tmp->next;
    tmp->next = head;
    return tmp;
}

int main() {
    SinglyLinkedList sll;
    node_t* head = nullptr;

    head = sll.insertAtFront(head, 15);
    sll.insertAtBack(head, 2);
    sll.insertAtBack(head, 8);
    sll.insertAtBack(head, 7);
    sll.insertAtBack(head, 20);
    sll.insertAtBack(head, 9);
    sll.insertAtBack(head, 11);
    sll.insertAtBack(head, 6);
    sll.insertAtBack(head, 19);

    head = MoveNthLastToFront(head, 2);
    sll.printList(head); // prints 6 15 2 8 7 20 9 11 19
}