// Day 26 — BST
// Problem: Kth Smallest in BST
//
// My notes:
//
// Approach 1: Inorder Traversal + Stack
// Pattern: BST + Inorder Traversal
// Idea: Inorder traversal of a BST visits nodes in sorted order.
//       Use a stack to simulate inorder traversal iteratively.
//       Decrease k whenever a node is visited.
//       When k becomes 0, the current node is the kth smallest.
// Time: O(H + k) → O(n) worst case
// Space: O(H)
//
// Approach 2: Recursive Inorder Traversal
// Pattern: BST + Inorder Traversal
// Idea: Recursively traverse the left subtree first.
//       Since inorder traversal gives sorted order, decrease k
//       whenever a node is visited.
//       When k becomes 0, store the current node's value.
// Time: O(n)
// Space: O(H)
//
// Approach 3: Morris Inorder Traversal
// Pattern: BST + Morris Traversal
// Idea: Perform inorder traversal without using a stack or recursion.
//       Create temporary links from the inorder predecessor to the current node.
//       This allows us to return to the current node after processing its left subtree.
//       Remove the temporary link after using it to restore the original tree.
// Time: O(n)
// Space: O(1)

// APPROACH:1 - ITERATIVE DFS
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        // Continue while there are nodes to process or curr is not NULL
        while(!st.empty() || curr != NULL){
            // Keep moving left and store nodes for inorder traversal
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            // Process the smallest unprocessed node
            curr = st.top();
            st.pop();
            // Decrease k after visiting a node in sorted order
            k--;
            // Return when the kth smallest node is found
            if(k == 0) return curr->val;
            // Move to the right subtree
            curr = curr->right;
        }
        return -1;
    }
};

// APPROACH:2 - Recursive DFS
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tmp(2);
        // Store k in tmp[0] and use tmp[1] to store the answer
        tmp[0] = k;
        // Perform inorder traversal
        dfs(root, tmp);
        return tmp[1];
    }
    void dfs(TreeNode* node, vector<int>& tmp) {
        // Stop if node is NULL
        if(!node) return;
        // Visit the left subtree first
        dfs(node->left, tmp);
        // Stop if kth smallest element has already been found
        if(tmp[0] == 0) return;
        // Current node is the next smallest element
        tmp[0]--;
        // Store the answer when k becomes 0
        if(tmp[0] == 0){
            tmp[1] = node->val;
            return;
        }
        // Visit the right subtree
        dfs(node->right, tmp);
    }
};

// APPROACH:3 - MORRIS TRAVERSAL
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        // Continue while there are nodes to process or curr is not NULL
        while(!st.empty() || curr != NULL){
            // Keep moving left and store nodes for inorder traversal
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            // Process the smallest unprocessed node
            curr = st.top();
            st.pop();
            // Decrease k after visiting a node in sorted order
            k--;
            // Return when the kth smallest node is found
            if(k == 0) return curr->val;
            // Move to the right subtree
            curr = curr->right;
        }
        return -1;
    }
};
