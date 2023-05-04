// Given a binary tree, create an array of the left view (leftmost elements in each level) of the tree.
// Approach: Breadth first search - push the first node at every level, whether leftmost or rightmost node
// At every level of tree, it's intuitive that the first node is the leftmost node, regardless of whether it's the left/right child of its parent node
// Time complexity: O(N)

// Time taken: 30 minutes
// unsure of whether 

#include <iostream>
#include <queue>
#include "BinarySearchTree.hpp"
using namespace std;


vector<int> LeftView(node_t* root)
{
    vector<int> res;
    queue<node_t*> q;
    if (root == nullptr) {
        return res;
    }

    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 1; i <= n; i++) {
            node_t* temp = q.front();
            q.pop();

            if (i == 1) {
                res.push_back(temp->val);
            }

            if (temp->left != nullptr) {
                q.push(temp->left);
            }

            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }
    return res;
}

int main()
{
    BinarySearchTree bst;
    bst.insert(40);
    bst.insert(30);
    bst.insert(50);
    bst.insert(25);
    bst.insert(35);
    bst.insert(45);
    bst.insert(60);

    vector<int> res = LeftView(bst.getRoot());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // outputs 40, 30, 25 for a complete binary tree
    return 0;
}