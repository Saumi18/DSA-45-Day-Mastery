// Day 27 — Advanced Trees
// Problem: Binary Tree Maximum Path Sum
//
// My notes:
// Pattern: DFS + One-Sided Path + Global Maximum
// Idea: At each node, calculate the best path from left/right.
//       Use both sides to update the answer, but return only one side to the parent.
//       Ignore negative paths using max(..., 0).
// Time: O(n)
// Space: O(h)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        // Find the maximum path and update res.
        dfs(root, res);
        return res;
    }

private:
    // Returns the maximum one-sided path starting from root.
    int dfs(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }
        // Get the best contribution from the left and right.
        // Ignore negative paths because they would reduce the sum.
        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);
        // Current node is the splitting point.
        // Here we can take both left and right.
        res = max(res, root->val + leftMax + rightMax);
        // Return only one side to the parent,
        // because a path cannot split at two nodes.
        return root->val + max(leftMax, rightMax);
    }
};
