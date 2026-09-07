// Day 25 — Trees BFS
// Problem: Binary Tree Right Side View
//
// My notes:
// Pattern: BFS / Level Order Traversal
// Idea: Traverse the tree level by level using a queue.
//       Push left child before right child so nodes in each level
//       are processed from left to right.
//       The last node of every level is the rightmost visible node,
//       so add it to the answer when i == 1.
//
// Time: O(n)
// Space: O(n)

class Solution {
public:
    // Return empty answer if tree is empty
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i=size;i>0;i--){
                TreeNode* node = q.front();
                q.pop();
                // Last node processed in each level is the rightmost node
                if(i==1) ans.push_back(node->val);
                // Push left child first so nodes are processed left to right
                if(node->left){
                    q.push(node->left);
                }
                // Push right child after left child
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
