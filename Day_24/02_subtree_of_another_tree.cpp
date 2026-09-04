// Day 24 — Trees (cont.)
// Problem: Subtree of Another Tree
//
// My notes:
//
// Approach 1: Recursion + Same Tree
// Logic:
// At every node of root, check if the tree starting from that node
// is identical to subRoot using isSameTree().
// If not, recursively search in the left OR right subtree.
//
// Time: O(m*n) worst case
// Space: O(m+n) in worst case due to recursion
//
// Approach 2: Serialization + KMP Pattern Matching
// Logic:
// Serialize both trees using preorder traversal.
// Use a special marker for NULL nodes so that tree structure is preserved.
// Add separators to avoid false matches between node values.
// Then search for serialized subRoot inside serialized root using KMP.
//
// Time: O(m+n)
// Space: O(m+n)
//
// m = number of nodes in root
// n = number of nodes in subRoot

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

    // Approach 1: Recursion
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p!=NULL && q!=NULL && p->val != q->val) return false;
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL)) return false;
        if(p==NULL && q == NULL) return true;
        
        return (isSameTree(p->left,q->left)) &&
               (isSameTree(p->right,q->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        
        if(isSameTree(root,subRoot)) return true;
        
        return isSubtree(root->left,subRoot) ||
               isSubtree(root->right,subRoot);
    }


    // Approach 2: Serialization + KMP

// Serialize the tree into a string using preorder traversal
void serialize(TreeNode* root, string& s) {
    // NULL nodes preserve the tree structure
    if(root == NULL) {
        s += "#,";
        return;
    }
    // Store current node's value with a separator
    s += to_string(root->val) + ",";
    // Serialize left subtree
    serialize(root->left, s);
    // Serialize right subtree
    serialize(root->right, s);
}
// Build LPS (Longest Prefix Suffix) array for KMP
vector<int> buildLPS(string& pattern) {
    // lps[i] = longest proper prefix which is also a suffix
    vector<int> lps(pattern.size(), 0);
    int len = 0;
    int i = 1;
    while(i < pattern.size()) {
        // Characters match, extend prefix
        if(pattern[i] == pattern[len]) {
            lps[i] = ++len;
            i++;
        }
        else {
            // Try a shorter previous prefix
            if(len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
// KMP pattern matching
// Checks if pattern occurs inside text
bool KMP(string& text, string& pattern) {
    vector<int> lps = buildLPS(pattern);
    int i = 0;
    int j = 0;
    while(i < text.size()) {
        // Characters match
        if(text[i] == pattern[j]) {
            i++;
            j++;
            // Entire pattern matched
            if(j == pattern.size())
                return true;
        }
        else {
            // Use LPS to avoid unnecessary comparisons
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}
// Check if subRoot is a subtree using serialization + KMP
bool isSubtreeKMP(TreeNode* root, TreeNode* subRoot) {
    // Empty tree is a subtree of every tree
    if(subRoot == NULL) return true;
    // Non-empty subtree cannot exist in an empty tree
    if(root == NULL) return false;
    string rootString = "";
    string subString = "";
    // Serialize both trees
    serialize(root, rootString);
    serialize(subRoot, subString);
    // Check if subRoot serialization occurs in root serialization
    return KMP(rootString, subString);
}
