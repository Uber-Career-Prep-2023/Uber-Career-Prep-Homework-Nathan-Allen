// Given a binary tree, determine if it is a binary search tree.
// Approach: Depth first search - In order traversal
// Time complexity: O(n)

// Time taken: ~30 minutes



#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;


bool isBST(node_t* root)
{
    // prev is static so that it retains its value across function calls
    node_t* prev = nullptr;
    if (root == nullptr) {
        return true;
    }
    // If left subtree is not a BST, then it is not a BST
    if ((isBST(root->left)) == false) {
        return false;
    }
    
    // If current node is smaller than the previous node, then it is not a BST
    if (prev != nullptr && root->val <= prev->val) {
        return false;
    }
    prev = root;
    return isBST(root->right);
}

int main()
{
    BinarySearchTree bst, bst2;
    bst.insert(9);
    bst.insert(3);
    bst.insert(12);
    bst.insert(2);
    bst.insert(10);
    bst.insert(17);
    bst.insert(20);

    cout << isBST(bst.getRoot()) << endl;
    // outputs true

    bst2.insert(9);
    bst2.insert(9);
    bst2.insert(9);
    bst2.insert(9);
    bst2.insert(9);
    bst2.insert(9);
    bst2.insert(9);

    cout << isBST(bst2.getRoot()) << endl;
    // outputs true
    return 0;
}