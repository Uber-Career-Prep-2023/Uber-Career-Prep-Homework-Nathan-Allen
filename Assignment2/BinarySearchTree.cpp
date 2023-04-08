#include <iostream>
using namespace std;

typedef struct node {
  int val;
  struct node *left;
  struct node *right;
} node_t;

class BinarySearchTree {
private:
  // root of BST
  node_t *root;

public:
  // returns the minimum value in the BST
  int min() {
    if (root == nullptr) {
      return 0;
    }
    node_t *cur = root;
    while (cur->left != nullptr) {
      cur = cur->left;
    }
    return cur->val;
  }
  // returns the maximum value in the BST
  int max() {
    if (root == nullptr) {
      return 0;
    }
    node_t *cur = root;
    while (cur->right != nullptr) {
      cur = cur->right;
    }
    return cur->val;
  }
  // returns a boolean indicating whether val is present in the BST
  // For simplicity, do not allow duplicates. If val is already present, insert
  // is a no-op
  bool contains(int val) {
    if (root == nullptr) {
      return false;
    }
    node_t *cur = root;
    while (cur != nullptr && cur->val != val) {
      if (val < cur->val) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    return cur->val == val;
  }
  // creates a new Node with data val in the appropriate location
  void insert(int val);
  // deletes the Node with data val, if it exists
  int deleteNode(int val);
};
