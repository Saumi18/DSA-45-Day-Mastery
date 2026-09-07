// Day 25 — Trees BFS
// Problem: Count Good Nodes in Binary Tree
//
// My notes:
// Pattern: BFS + Path Maximum
// Idea: For every node, keep track of the maximum value among its ancestors.
//       A node is good if its value is greater than or equal to this maximum.
//       When pushing a child, update the maximum using the current node.
//
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        // Store each node along with the maximum value seen on its path
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        while(!q.empty()){
            // Get the current node and maximum value among its ancestors
            pair<TreeNode*, int> current = q.front();
            TreeNode* node = current.first;
            int maxVal = current.second;
            q.pop();
            // Current node is good if its value is at least the path maximum
            if(node->val >= maxVal){
                res++;
            }
            
            // Pass the updated maximum to the left child
            if(node->left){
                q.push({node->left, max(node->val, maxVal)});
            }
            // Pass the updated maximum to the right child
            if(node->right){
                q.push({node->right, max(node->val, maxVal)});
            }
        }
        return res;
    }
};
