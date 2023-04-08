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
    BinarySearchTree() {
        root = nullptr;
    }
  // Time complexity: 
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

  // Time complexity: 
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

  // Time complexity: 
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

  // Time complexity: 
  void insert(int val);
  // Time complexity: 
  int deleteNode(int val);
};
