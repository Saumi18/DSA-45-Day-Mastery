// Day 23 — Trees
// Problem: Balanced Binary Tree
//
// My notes:
// Pattern: Recursive DFS + Height Calculation
// Idea: Calculate the height of the left and right subtrees for every node.
// If their height difference is greater than 1, the tree is unbalanced.
// Use decision to remember if any node violates the balance condition.
// Return the height of the current node so the parent can use it.
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
    bool decision = true;
    int heightOfTree(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = heightOfTree(root->left);
        int right = heightOfTree(root->right);

        if(abs(left-right) > 1) decision = false;
        
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        heightOfTree(root);
        return decision;
    }
};

