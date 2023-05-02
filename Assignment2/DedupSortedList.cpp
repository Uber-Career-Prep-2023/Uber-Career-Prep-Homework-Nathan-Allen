#include "SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

// Technique: Basic Linked List traversal
// Time complexity: O(N) - traverse entire list of N nodes to N-1 index
// Time taken: 25 minutes

void DedupList(node_t* head) {

  if (head == nullptr) {
    return;
  }
  node_t* curr = head;
  while (curr != nullptr && curr->next != nullptr) {
    if (curr->data == curr->next->data) {
      node_t* temp = curr->next;
      curr->next = temp->next;
      delete temp;
    }
    else {
      curr = curr->next;
    }
  }
  
}

int main() {
    SinglyLinkedList sll;
    node_t* head = nullptr;
    head = sll.insertAtFront(head, 1);
    sll.insertAtBack(head, 2);
    sll.insertAtBack(head, 2);
    sll.insertAtBack(head, 4);
    sll.insertAtBack(head, 5);
    sll.insertAtBack(head, 5);
    sll.insertAtBack(head, 5);
    sll.insertAtBack(head, 10);
    sll.insertAtBack(head, 10);

    DedupList(head);
    sll.printList(head); // prints 1 2 4 5 10

    SinglyLinkedList sll2;
    node_t* head2 = nullptr;
    head2 = sll2.insertAtFront(head2, 8);
    head2 = sll2.insertAtFront(head2, 8);
    head2 = sll2.insertAtFront(head2, 8);
    head2 = sll2.insertAtFront(head2, 8);

    DedupList(head2);
    sll2.printList(head2); // prints 8

}