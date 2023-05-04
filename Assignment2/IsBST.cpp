// Given a binary tree, determine if it is a binary search tree.
// Approach: Depth first search - In order traversal
// Time complexity: O(n)

// Time taken: ~40 minutes



#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;


bool isBST(node_t* root)
{
    node_t* prev = nullptr;
    if (root == nullptr) {
        return true;
    }
    if ((isBST(root->left)) == false) {
        return false;
    }
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