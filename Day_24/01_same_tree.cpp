// Day 24 — Trees (cont.)
// Problem: Same Tree
//
// My notes:
// Pattern: Recursion / DFS
// Logic: If both NULL -> true; if one NULL or values differ -> false;
//        otherwise recursively compare left and right subtrees.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p!=NULL && q!=NULL && p->val != q->val) return false;
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL)) return false;
        if(p==NULL && q == NULL) return true;
        
        return (isSameTree(p->left,q->left))&&(isSameTree(p->right,q->right));
    }
};

