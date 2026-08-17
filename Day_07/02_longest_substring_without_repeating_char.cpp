// Day 07 — Sliding Window
// Problem: Longest Substring without repeating char
//
// My notes:
// Pattern: Sliding Window + Set
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int len = 0;
        unordered_set<char> check;
        int l = 0;
        for(int i = 0; i < s.size(); i++) {
            // Remove chars until current char is unique
            while(check.count(s[i])) {
                check.erase(s[l]);
                l++;
            }

            check.insert(s[i]);
            len = check.size();
            res = max(len, res);
        }
        return res;
    }
};
