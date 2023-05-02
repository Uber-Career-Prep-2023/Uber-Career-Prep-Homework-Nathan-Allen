#include <iostream>
using namespace std;


// Time complexity: O(1) - constant time taken for insertion
node_t *insertAtFront(node_t *head, int val) {
  node_t *ins = new node_t;
  ins->data = val;
  ins->next = head;
  return ins;
}

// Time complexity: O(N) - entire list of N nodes traversed, insertion in
// constant time
void insertAtBack(node_t *head, int val) {
  node_t *ins = new node_t;
  ins->data = val;
  ins->next = nullptr;

  if (head == nullptr) {
    head = ins;
  } else {
    node_t *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = ins;
  }
}

// Time complexity: O(1) - reference to node loc already exists, constant time
// for insertion
void insertAfter(node_t *head, int val, node_t *loc) {
  if (loc == nullptr) {
    return;
  }

  node_t *ins = new node_t;
  ins->data = val;

  ins->next = loc->next;
  loc->next = ins;
}

// Time complexity: O(1) - constant time for head deletion since reference
// already exists
node_t *deleteFront(node_t *head) {
  if (head == nullptr) {
    return nullptr;
  }
  node_t *temp = head;
  head = head->next;
  delete temp;
  return head;
}

// Time complexity: O(N) - traverse entire list of N nodes to N-1 index,
// constant time for deletion
void deleteBack(node_t *head) {
  if (head == nullptr) {
    return;
  }
  if (head->next == nullptr) {
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

// Time complexity: O(N) - traverse entire list of N nodes to locate and delete
// node loc
node_t *deleteNode(node_t *head, node_t *loc) {
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
    return head;
  }
  if (prev == nullptr) {
    head = head->next;
  } else {
    prev->next = cur->next;
  }
  delete cur;
  return head;
}

// Time complexity: O(N) - traverse list of N nodes and increment count until
// cur == nullptr
int length(node_t *head) {
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
node_t *reverseIterative(node_t *head) {
  if (head == nullptr) {
    return nullptr;
  }
  node_t *prev = nullptr;
  node_t *cur = head;
  node_t *next;

  while (cur != nullptr) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

// reverses the linked list recursively (Hint:
// you will need a helper function)
node_t *reverseRecursive(node_t *head);
