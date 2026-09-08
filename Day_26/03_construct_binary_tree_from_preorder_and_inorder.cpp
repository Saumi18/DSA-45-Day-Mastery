// Day 26 — Binary Tree
// Problem: Construct Binary Tree from Preorder and Inorder
//
// Pattern: Preorder + Inorder + DFS with Boundary
//
// Idea:
// Preorder gives the root first.
// Inorder tells us when the current subtree is complete.
// Use a limit value to define the boundary of each subtree.
//
// For each node:
// 1. Take the next value from preorder as the root.
// 2. Recursively build the left subtree with root->val as the limit.
// 3. Recursively build the right subtree with the current limit.
//
// Time: O(n)
// Space: O(n) — recursion stack + tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int preIdx = 0;
    int inIdx = 0;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        // No more nodes to process
        if(preIdx >= preorder.size())
            return NULL;

        // Current subtree ends when we reach its inorder boundary
        if(inorder[inIdx] == limit) {
            inIdx++;
            return NULL;
        }

        // Preorder gives us the next root
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        // Build left subtree
        // It must stop when we reach the current root in inorder
        root->left = dfs(preorder, inorder, root->val);
        // Build right subtree
        // It uses the same boundary as the current subtree
        root->right = dfs(preorder, inorder, limit);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};
