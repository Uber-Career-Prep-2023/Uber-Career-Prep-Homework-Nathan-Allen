// Given a binary tree, create an array of the left view (leftmost elements in each level) of the tree.
// Approach: Breadth first search - push the first node at every level, whether leftmost or rightmost node
// At every level of tree, it's intuitive that the first node is the leftmost node, regardless of whether it's the left/right child of its parent node
// Time complexity: O(N)

// Time taken: 20 minutes


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
    node_t* root = bst.createNode(7);
    root->left = bst.createNode(8);
    root->right = bst.createNode(3);
    root->right->left = bst.createNode(9);
    root->right->right = bst.createNode(13);
    root->right->left->left = bst.createNode(20);
    root->right->right->left = bst.createNode(14);
    root->right->right->left->right = bst.createNode(15);

    vector<int> res = LeftView(root);
    for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
    }
    // outputs 7 8 9 20 15
}