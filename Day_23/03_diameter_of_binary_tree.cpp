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
// Day 23 — Trees
// Problem: Diameter of Binary Tree
//
// My notes:
// Pattern: Recursive DFS + Height Calculation
// Idea: For every node, calculate the height of its left and right subtrees.
// The diameter passing through that node is left height + right height.
// Keep the maximum diameter in res while calculating heights.
// Return the height of the current node so the parent can use it.
//
// Time: O(n)
// Space: O(h)
class Solution {
public:
    int res = 0;
    int heightOfTree(TreeNode* root){
        if(root == NULL) return 0;
        int right = heightOfTree(root->right);
        int left = heightOfTree(root->left);
        res = max(res,left+right);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root){
        heightOfTree(root);
        return res;
    }
};
