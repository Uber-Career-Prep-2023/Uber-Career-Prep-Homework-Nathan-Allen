// Given a binary tree, create a deep copy. Return the root of the new tree
// Approach: Recursive preorder traversal
// Time complexity: O(n)
// Space complexity: O(n)

#include "BinarySearchTree.hpp"
#include <iostream>
using namespace std;


node_t* copyTree(node_t* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    node_t* newRoot = new node_t;
    newRoot->val = root->val;
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

int main(){

    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    
    bst.printLevelOrder(); // 5 3 7

    node_t* newroot = copyTree(bst.getRoot());
    BinarySearchTree copy;
    copy.setRoot(newroot);

    copy.printLevelOrder(); // 5 3 7

    return 0;

}