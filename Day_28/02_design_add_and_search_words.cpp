// Day 28 — Trie
// Problem: Design Add and Search Words Data Structure
//
// My notes:
// Pattern: Trie + DFS / Backtracking
// Idea: Store every word in a Trie.
//       Normal characters follow one specific Trie branch.
//       '.' can represent any character, so try all 26 possible children using DFS.
//       dfs() returns true if the remaining part of the word can be matched.
//       At the end of the word, check endOfWord to make sure it is a complete word.
// Time: O(L) without '.'
//       O(26^L) in the worst case with many '.' characters.
//       L = length of the search word.
// Space: O(N × L) for the Trie + O(L) recursion stack.
//        N = number of words, L = average word length.

class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode() {
        // Initially, no children exist.
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        // Initially, no word ends at this node.
        endOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs(TrieNode* cur, string& word, int index) {
        // If we reached the end of the word, check if a word ends here.
        if (index == word.size()) {
            return cur->endOfWord;
        }
        char c = word[index];
        // '.' can represent any character, so try all 26 children.
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                // Only explore existing Trie branches.
                if (cur->children[i] != NULL) {
                    // If any branch matches, the search is successful.
                    if (dfs(cur->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            // No branch matched the remaining word.
            return false;
        }

        // Convert the character into an index from 0 to 25.
        int i = c - 'a';
        // Required character does not exist.
        if (cur->children[i] == NULL) {
            return false;
        }
        // Move to the next Trie node.
        return dfs(cur->children[i], word, index + 1);
    }

public:
    WordDictionary() {
        // Create the root node of the Trie.
        root = new TrieNode();
    }

    void addWord(string word) {
        // Start from the root.
        TrieNode* cur = root;
        // Insert the word character by character.
        for (char c : word) {
            int i = c - 'a';
            // Create the node if this character path doesn't exist.
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
        // Start DFS from the root.
        return dfs(root, word, 0);
    }
};
