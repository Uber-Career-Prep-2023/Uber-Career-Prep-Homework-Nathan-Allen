// Given a target numeric value and a binary search tree, return the floor (greatest element less than or equal to the target) in the BST.
// Approach: Depth first search - In order traversal
// Time complexity: O(n)

// Time taken:

#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;


int FloorInBST(node_t* root, int k)
{
}

int main()
{
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(8);
    bst.insert(16);
    bst.insert(9);
    bst.insert(13);
    bst.insert(17);
    bst.insert(20);

    cout << FloorInBST(bst.getRoot(), 15) << endl;
    // outputs 13
    return 0;
}