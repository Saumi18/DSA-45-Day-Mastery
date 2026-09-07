// Day 25 — Trees BFS
// Problem: Binary Tree Level Order Traversal
//
// My notes:
// Pattern: BFS / Level Order Traversal
// Idea: Use a queue to process nodes level by level.
//       At the start of each level, store the current queue size.
//       Process exactly those nodes and add their children to the queue.
//       The newly added children are then processed in the next level.
//
// Time: O(n)
// Space: O(n)


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            
            for (int i = size; i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
