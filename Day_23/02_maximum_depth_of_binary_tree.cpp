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

// ============================================================
// Day 23 — Trees
// Problem: Maximum Depth of Binary Tree
//
// Approach 1: BFS
// Pattern: Level Order Traversal
// Idea: Use a queue to process the tree level by level.
// Each completed level increases the depth by 1.
//
// Time: O(n)
// Space: O(n)
// ============================================================

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr){
            q.push(root);
        }
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            level++;
        }
        return level;
    }
};


// ============================================================
// Approach 2: Recursive DFS
// Pattern: Recursion / DFS
// Idea: The depth of a node is 1 + the maximum depth of its
// left and right subtrees. An empty tree has depth 0.
//
// Time: O(n)
// Space: O(h), where h is the height of the tree
// ============================================================

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->right), maxDepth(root->left));
    }
};
