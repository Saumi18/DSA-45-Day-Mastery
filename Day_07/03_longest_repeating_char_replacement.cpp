// Day 08 — Sliding Window
// Problem: Longest Repeating Character Replacement
//
// My notes:
// Pattern: Sliding Window + Frequency Array
// Time: O(n)
// Space: O(1)  // 26 characters

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int maxFreq = 0; // Frequency of most common char in current window
        int l = 0;
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++) {
            // Add current char to window
            freq[s[i] - 'A']++;
            // Track most frequent char in window
            maxFreq = max(maxFreq, freq[s[i] - 'A']);
            // If replacements needed > k, shrink window
            while(i + 1 - l - maxFreq > k) {
                freq[s[l] - 'A']--; // Remove leftmost char
                l++;
            }
            // Current valid window length
            res = max(res, i + 1 - l);
        }
        return res;
    }
};
