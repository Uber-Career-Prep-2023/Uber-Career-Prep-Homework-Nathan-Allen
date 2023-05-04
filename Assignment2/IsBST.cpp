// Given a binary tree, determine if it is a binary search tree.
// Approach: Depth first search - In order traversal
// Time complexity: O(n)

// Time taken: ~30 minutes



#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;


bool isBST(node_t* root)
{
    if (root == nullptr) {
        return true;
    }
    if (root->left != nullptr) {
        if (root->left->val > root->val) {
            return false;
        }
    }
    if (root->right != nullptr) {
        if (root->right->val < root->val) {
            return false;
        }
    }
    return isBST(root->left) && isBST(root->right);
}

int main()
{
    // constructing two binary trees to compare output: an "incorrect" and correct tree structure
    BinarySearchTree bst, bst2;
    node_t* root = bst.createNode(7);
    root->left = bst.createNode(10);
    root->right = bst.createNode(5);
    root->left->left = bst.createNode(8);
    root->right->right = bst.createNode(12);
    root->left->left->right = bst.createNode(15);
    root->right->right->left = bst.createNode(11);
    
    cout << "Valid BST: " << isBST(root) << endl;
    // outputs 0 (false)
    node_t* root2 = bst2.createNode(1);
    root->left = bst2.createNode(2);
    root->right = bst2.createNode(3);
    root->left->left = bst2.createNode(4);
    root->left->right = bst2.createNode(5);
    root->right->left = bst2.createNode(6);
    
    cout << "Valid BST: " << isBST(root2) << endl;
    // outputs 1 (true)

}