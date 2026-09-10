// Topic: Binary Tree + Postorder Traversal
// Problem: (2265) Count Nodes Equal to Average of Subtree
//
// My notes:
// Pattern: Postorder DFS + Subtree Sum + Subtree Count
//
// Idea:
// For every node, we need to find the sum and number of nodes
// present in its entire subtree.
//
// Postorder traversal is used because before processing a node,
// we first need the information from its left and right subtrees.
// The helper function returns a pair:
// pair.first  -> sum of all nodes in the subtree
// pair.second -> number of nodes in the subtree
//
// For the current node:
// nodeSum = leftSum + rightSum + root->val
// nodeCount = leftCount + rightCount + 1
//
// The +1 in nodeCount represents the current node itself.
//
// After calculating the subtree sum and count, we calculate the
// integer average using nodeSum / nodeCount.
// If this average is equal to root->val, we increment res.
//
// The important idea is that every subtree's sum and count are
// calculated once and then passed to its parent.
//
// Time: O(n)
// Each node is visited exactly once.
//
// Space: O(h)
// O(h) recursion stack, where h is the height of the tree.
// Worst case: O(n) for a completely skewed tree.

class Solution {
public:
    int res = 0;
    pair<int, int> postOrder(TreeNode* root) {
        if (!root) return {0, 0};
        // Get sum and count of the left subtree.
        pair<int, int> left = postOrder(root->left);
        // Get sum and count of the right subtree.
        pair<int, int> right = postOrder(root->right);
      
        // Calculate sum of the current subtree.
        int nodeSum = left.first + right.first + root->val;
        // Calculate number of nodes in the current subtree.
        int nodeCount = left.second + right.second + 1;
        // Check if the current node equals the subtree average.
      
        if (root->val == nodeSum / nodeCount) {
            res++;
        }
        // Return sum and count to the parent.
        return {nodeSum, nodeCount};
    }

    int averageOfSubtree(TreeNode* root) {
        // Process the entire tree using postorder DFS.
        postOrder(root);
        return res;
    }
};
