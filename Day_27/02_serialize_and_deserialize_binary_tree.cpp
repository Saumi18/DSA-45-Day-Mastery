// Day 27 — Advanced Trees
// Problem: Serialize and Deserialize Binary Tree
//
// My notes:
// Pattern: Tree Traversal + Encoding/Decoding
//
// Approach 1: DFS (Preorder)
// Idea: Serialize using root -> left -> right.
//       Store "#" for NULL nodes so the tree structure is preserved.
//       During deserialization, read values in the same preorder order
//       and recursively rebuild the tree.
//
// Time: O(n)
// Space: O(h) recursion stack + O(n) serialized string
//
// Approach 2: BFS (Level Order)
// Idea: Serialize level by level using a queue.
//       Store "#" for NULL children.
//       During deserialization, take one node from the queue and
//       attach the next two values as its left and right children.
//
// Time: O(n)
// Space: O(n) queue + O(n) serialized string

//Approach 1: DFS preorder
class Codec {
public:
    void serializeHelper(TreeNode* root, string& s) {
        if (!root) {
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        // Preorder: Root -> Left -> Right
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string val;
        getline(ss, val, ',');
        // "N" represents a NULL node
        if (val == "N")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(val));
        // Rebuild in the same order: Left -> Right
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

//Approach 2: BFS+Queues
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                s += "N,";
                continue;
            }

            s += to_string(node->val) + ",";

            // Add both children, including NULLs
            q.push(node->left);
            q.push(node->right);
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string val;

        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Build left child
            getline(ss, val, ',');
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            // Build right child
            getline(ss, val, ',');
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};
