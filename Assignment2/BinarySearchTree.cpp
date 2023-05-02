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
  // Time complexity: O(n)
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

  // Time complexity: O(n)
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

  // Time complexity: O(n)
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

  // Time complexity: O(n)
  void insert(int val) {

    // if root is null, create new node and set as root
    if (root == nullptr) {
      root = new node_t;
      root->val = val;
      root->left = nullptr;
      root->right = nullptr;
      return;
    }

    node_t *cur = root;
    node_t* ins = new node_t;

    // find the correct place to insert the node
    while (cur != nullptr) {

      // if value less than current node's value
      if (val < cur->val) {
        if (cur->left == nullptr) {
          ins->val = val;
          ins->left = nullptr;
          ins->right = nullptr;
          cur->left = ins;
          return;
        }
        cur = cur->left;

      } else {

        // if value greater than current node's value
        if (cur->right == nullptr) {
          ins->val = val;
          ins->left = nullptr;
          ins->right = nullptr;
          cur->right = ins;
          return;
        }

        cur = cur->right;
      }
    }
  }
  // Time complexity: O(n)
  int deleteNode(int val);
};
