#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;


// Time complexity: O(1) - reference to head already exist, constant insertion
node_t* DoublyLinkedList::insertAtFront(node_t *head, int val) {
  node_t *ins = new node_t;
  ins->data = val;
  ins->prev = nullptr;
  ins->next = head;
  if (head != nullptr) {
    head->prev = ins;
  }
  return ins;
}

// Time complexity: O(N) - traverse list of N nodes once, would only be O(1) if reference to tail existed
void DoublyLinkedList::insertAtBack(node_t *head, int val) {
  node_t *ins = new node_t;
  ins->data = val;
  ins->next = nullptr;

  // list is empty
  if (head == nullptr) {
    ins->prev = nullptr;
    head = ins;
    return;
  }

  node_t *curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = ins;
  ins->prev = curr;
  ins->next = nullptr;
}

// Time complexity: O(N) - traverse list of N nodes once, would only be O(1) if reference to tail existed
void DoublyLinkedList::insertAfter(node_t *head, int val, node_t *loc) {
  node_t *ins = new node_t;
  ins->data = val;

  node_t *prev = nullptr;
  node_t *cur = head;

  while (cur != loc && cur != nullptr) {
    prev = cur;
    cur = cur->next;
  }

  if (cur == nullptr) { // loc not found in list
    delete ins;
    return;
  }

  if (cur->next != nullptr) { // there is a node after loc
    cur->next->prev = ins;
    ins->next = cur->next;
  }

  ins->prev = cur;
  cur->next = ins;
}

// Time complexity: O(1) - constant deletion (no traversal
node_t* DoublyLinkedList::deleteFront(node_t *head) {
  if (head == nullptr) {
    return nullptr;
  }
  node_t *temp = head;
  head = head->next;

  if (head != nullptr) {
    head->prev = nullptr;
  }

  delete temp;
  return head;
}

// Time complexity: O(N) - traverse list of N nodes once, would only be O(1) if reference to tail existed
void DoublyLinkedList::deleteBack(node_t *head) {
  if (head == nullptr) {
    return;
  }

  if (head->next == nullptr) { // list has only one node
    delete head;
    head = nullptr;
  } else {
    node_t *temp = head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }
}

// Time complexity: O(N) - traverse list of N nodes once
node_t* DoublyLinkedList::deleteNode(node_t *head, node_t *loc) {
  if (head == nullptr) {
    return nullptr;
  }
  node_t *prev = nullptr;
  node_t *cur = head;

  while (cur != nullptr && cur != loc) {
    prev = cur;
    cur = cur->next;
  }

  if (cur == nullptr) {
    return head; // node not found, return original head
  }

  if (prev == nullptr) { // deleting first node
    head = cur->next;
  } else {
    prev->next = cur->next;
  }

  if (cur->next != nullptr) { // updating next node's prev pointer
    cur->next->prev = prev;
  }

  delete cur;
  return head;
}

// Time complexity: O(N) - traverse list of N nodes and increment count until
// cur == nullptr
int DoublyLinkedList::length(node_t *head) {
  if (head == nullptr) {
    return 0;
  }
  node_t *cur = head;
  int count = 0;

  while (cur != nullptr) {
    cur = cur->next;
    count += 1;
  }
  return count;
}

// Time complexity: O(N) - traverse list of N nodes only once, modifying
// pointers to nodes at each iteration
node_t* DoublyLinkedList::reverseIterative(node_t *head) {
  if (head == nullptr) {
    return nullptr;
  }

  node_t *prev = nullptr;
  node_t *cur = head;
  node_t *next = nullptr;

  while (cur != nullptr) {
    next = cur->next; // save next node
    cur->next = prev; // update next pointer
    cur->prev = next; // update prev pointer
    prev = cur;       // move prev and cur one node ahead
    cur = next;
  }

  return prev; // return new head
}

// reverses the linked list recursively (Hint:
// you will need a helper function)
node_t* DoublyLinkedList::reverseRecursive(node_t *head) {
  return nullptr;
}

void DoublyLinkedList::printList(node_t *head) {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }
  node_t *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}