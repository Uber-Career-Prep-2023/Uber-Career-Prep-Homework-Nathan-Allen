#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node_t;

class DoublyLinkedList
{
private:
    node_t* head;
public:
    DoublyLinkedList() { head = nullptr;};
    node_t* insertAtFront(node_t* head, int val); // creates new node_t* with data val at front; returns new head
    void insertAtBack(node_t* head, int val); // creates new node_t* with data val at end
    void insertAfter(node_t* head, int val, node_t* loc); // creates new node_t* with data val after node_t* loc
    node_t* deleteFront(node_t* head); // removes first node_t*; returns new head
    void deleteBack(node_t* head); // removes last node_t*
    node_t* deleteNode(node_t* head, node_t* loc); // deletes node_t* loc; returns head
    int length(node_t* head); // returns length of the list
    node_t* reverseIterative(node_t* head); // reverses the linked list iteratively
    node_t* reverseRecursive(node_t* head); // reverses the linked list recursively (Hint: you will need a helper function)

    // test case purposes
    void printList(node_t* head);
};

#endif