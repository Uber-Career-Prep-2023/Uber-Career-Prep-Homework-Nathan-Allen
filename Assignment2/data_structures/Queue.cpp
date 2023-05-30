#include <iostream>
using namespace std;

typedef struct node {
  int data;
  struct node *next;
} node_t;

class Queue {
    private:
        node_t *front;
        node_t *back;
    
    public:
        Queue(){
            front = back = nullptr;
        }
        // Time complexity: O(1) - constant time for front retrieval
        int peek() {
            if (front == nullptr) {
                return -1;
            }
            return front->data;
        }
        // Time complexity: O(1) - constant time for insertion
        void enqueue(int x) {
            node_t *ins = new node_t;
            ins->data = x;
            ins->next = nullptr;
            if (front == nullptr) {
                front = back = ins;
            } else {
                back->next = ins;
                back = ins;
            }
        }
        // Time complexity: O(1) - constant time for deletion
        int dequeue() {
            if (front == nullptr) {
                return -1;
            }
            node_t *temp = front;
            front = front->next;
            int val = temp->data;
            delete temp;
            return val;
        }
        // Time complexity: O(1) - constant time for checking if queue is empty
        bool isEmpty() {
            return front == nullptr;
        }

};