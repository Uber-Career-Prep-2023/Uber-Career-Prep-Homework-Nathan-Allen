#include <iostream>
using namespace std;

typedef struct node {
  int data;
  struct node *next;
} node_t;


class Stack {
    private:
        node_t *top;
    public:
        Stack() {
            top = nullptr;
        }
        // Time complexity: O(1) - constant time for top retrieval
        int top() {
            if (top == nullptr) {
                return -1;
            }
            return top->data;
        }
        // Time complexity: O(1) - constant time for insertion
        void push(int val) {
            node_t *ins = new node_t;
            ins->data = val;
            ins->next = top;
            top = ins;
        }
        
        // Time complexity: O(1) - constant time for deletion
        int pop() {
            if (top == nullptr) {
                return -1;
            }
            node_t *temp = top;
            top = top->next;
            int val = temp->data;
            delete temp;
            return val;
        }
        
        // Time complexity: O(1) - constant time for checking if stack is empty
        bool isEmpty() {
            return top == nullptr;
        }

};