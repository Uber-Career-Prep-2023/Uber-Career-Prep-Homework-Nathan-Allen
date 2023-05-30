#include "../data_structures/SinglyLinkedList.hpp"
#include <iostream>
#include <unordered_map>
using namespace std;

// Technique: Hash the linked list nodes
// Time complexity: O(N)
// Time taken: 20 minutes


void DisconnectCycle(node_t *head)
{
    if (head == nullptr) {
        return;
    }
    unordered_map<node_t*, bool> visited;
    visited[head] = true;

    node_t* curr = head->next;
    while (curr != nullptr && curr->next != nullptr)
    {
        if (visited.find(curr->next) != visited.end()) {
            curr->next = nullptr;
            return;
        }
        visited[curr] = true;
        curr = curr->next;
    }
    
}

int main()
{
    
    SinglyLinkedList sll;
    node_t* head = nullptr;
    head = sll.insertAtFront(head, 10);
    sll.insertAtBack(head, 18);
    sll.insertAtBack(head, 12);
    sll.insertAtBack(head, 9);
    sll.insertAtBack(head, 11);
    sll.insertAtBack(head, 4);

    // create cycle
    head->next->next->next->next->next->next = head->next->next;
    //sll.printList(head); // infinite loop of 10 18 12 9 11 4 12 9 11 4....

    DisconnectCycle(head);
    sll.printList(head); // 10 18 12 9 11 4
    
    SinglyLinkedList sll2;
    node_t* head2 = nullptr;
    head2 = sll2.insertAtFront(head2, 10);
    sll2.insertAtBack(head2, 18);
    sll2.insertAtBack(head2, 12);
    sll2.insertAtBack(head2, 9);
    sll2.insertAtBack(head2, 11);
    sll2.insertAtBack(head2, 4);

    head2->next->next->next->next->next->next = head2->next->next->next->next->next;
    //sll2.printList(head2); // infinite loop of 10 18 12 9 11 4 4 4...

    DisconnectCycle(head2);
    sll2.printList(head2); // 10 18 12 9 11 4

    return 0;
}