// Day 24 — Trees (cont.)
// Problem: Lowest Common Ancestor of a Binary Search Tree
//
// My notes:
//
// Approach 1: Recursion
// Logic:
// Use the BST property.
// If both p and q are smaller than root -> LCA is in left subtree.
// If both are greater than root -> LCA is in right subtree.
// Otherwise, root is the LCA.
//
// Time: O(h)
// Space: O(h) due to recursion
//
// Approach 2: Iterative
// Logic:
// Start from root and repeatedly move left/right using the BST property.
// If both nodes are smaller -> move left.
// If both are greater -> move right.
// Otherwise, current root is the LCA.
//
// Time: O(h)
// Space: O(1)
//
// h = height of the BST


/**
 * Recursive Approach
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};


/**
 * Iterative Approach
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL) {
            if(p->val < root->val && q->val < root->val)
                root = root->left;
            else if(p->val > root->val && q->val > root->val)
                root = root->right;
            else
                return root;
        }
        return NULL;
    }
};
