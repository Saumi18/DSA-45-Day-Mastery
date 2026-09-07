// Day 26 — BST
// Problem: Validate Binary Search Tree
//
// My notes:
// Pattern: DFS + Range Validation
// Idea: Keep a valid range (left, right) for every node.
//       Left subtree must contain values smaller than the current node.
//       Right subtree must contain values greater than the current node.
//       Update the range while moving down the tree.
//
// Time: O(n)
// Space: O(h)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode* node, long left, long right){
        if(!node) return true;
        if(!(left<node->val && right>node->val)){
            return false;
        }
        // Update the range: left child gets [left, node->val), right child gets (node->val, right)
        return valid(node->left,left,node->val) && valid(node->right,node->val,right);
    }
};

