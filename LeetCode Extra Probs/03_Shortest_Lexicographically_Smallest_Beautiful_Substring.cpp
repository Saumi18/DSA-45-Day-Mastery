// Topic: Sliding Window
// Problem: (2904) Shortest Beautiful Substring
//
// Pattern: Sliding Window
// Idea: Expand right until the window has k ones, then shrink from the left
//       by removing leading zeroes and checking the shortest valid substring.
//       If lengths are equal, keep the lexicographically smaller one.
//
// Time: O(n)
// Space: O(n) — substring storage

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (count(s.begin(), s.end(), '1') < k)
            return "";
      
        string res = "";
        int l = 0, r = 0;
        int cnt = 0;
        int minLen = INT_MAX;

        while (r < s.size()) {
            // Add current character
            if (s[r] == '1')
                cnt++;
            r++;
            // We have k ones
            while (cnt == k) {
                // Remove leading zeroes
                if (s[l] == '0') {
                    l++;
                }
                else {
                    int len = r - l;
                    // Update answer
                    if (len < minLen) {
                        minLen = len;
                        res = s.substr(l, len);
                    }
                    else if (len == minLen) {
                        res = min(res, s.substr(l, len));
                    }
                    // Remove this '1'
                    cnt--;
                    l++;
                }
            }
        }
        return res;
    }
};
