// Day 28 — Trie
// Problem: Implement Trie
//
// My notes:
// Pattern: Trie / Prefix Tree
// Idea: Store strings character by character in a tree.
//       Each node has 26 children, one for each lowercase letter.
//       endOfWord tells whether a complete word ends at that node.
//       insert() creates missing nodes and marks the last node.
//       search() checks the complete path and endOfWord.
//       startsWith() only checks whether the prefix path exists.
// Time: O(L) for insert, search, and startsWith
//       where L = length of the word/prefix.
// Space: O(N × L)
//        where N = number of inserted words and L = average word length.


class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        // Initially, no character paths exist.
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        // This node does not represent the end of a word.
        endOfWord = false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        // Create the root node.
        root = new TrieNode();
    }
    void insert(string word) {
        // Start from the root.
        TrieNode* cur = root;
        // Process every character of the word.
        for (char c : word) {
            int i = c - 'a';
            // Create the node if this character path does not exist.
            if (cur->children[i] == NULL) {
                cur->children[i] = new TrieNode();
            }
            // Move to the next node.
            cur = cur->children[i];
        }
        // Mark the last node as the end of a complete word.
        cur->endOfWord = true;
    }
    bool search(string word) {
        // Start from the root.
        TrieNode* cur = root;
        // Follow the path of the word.
        for (char c : word) {
            int i = c - 'a';
            // Path does not exist.
            if (cur->children[i] == nullptr) {
                return false;
            }
            // Move to the next node.
            cur = cur->children[i];
        }
        // Path exists, but it must also represent a complete word.
        return cur->endOfWord;
    }

    bool startsWith(string prefix) {
        // Start from the root.
        TrieNode* cur = root;
        // Follow the path of the prefix.
        for (char c : prefix) {
            int i = c - 'a';
            // Prefix path does not exist.
            if (cur->children[i] == nullptr) {
                return false;
            }
            // Move to the next node.
            cur = cur->children[i];
        }
        // Entire prefix path exists.
        return true;
    }
};
