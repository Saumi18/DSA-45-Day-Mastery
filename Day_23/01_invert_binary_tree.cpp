// Day 23 — Trees
// Problem: Invert Binary Tree
//
// My notes:
// Pattern: Recursive DFS
// Idea: For every node, swap its left and right children, then recursively
// invert both subtrees. Base case is when root is NULL.
//
// Time: O(n)
// Space: O(h)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
         if(root == NULL) return NULL;
         TreeNode* temp = root->left;
         root->left = root->right;
         root->right = temp;
         invertTree(root->right);
         invertTree(root->left);
         return root;
    }
};

