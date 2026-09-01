// Day 21 — Strings
// Problem: Longest Palindromic Substring
//
// My notes:
// Pattern: Expand Around Center
// Idea: Every palindrome has a center. For each index, expand outward for
// both odd-length (i,i) and even-length (i,i+1) palindromes while characters match.
// Keep track of the longest palindrome found.
//
// Time: O(n²)
// Space: O(n)

// There is O(n) T.C. also called MANACHER'S Algorithm

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;

        for (int i = 0; i < s.size(); i++) {
// For Odd Palindrome
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
// For Even Palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return res;
    }
};

// MANACHER's ALGORITHM

// Idea: Transform the string so odd and even length palindromes are handled
// uniformly. Use p[i] to store the palindrome radius around each position.
// Maintain the current rightmost palindrome [l, r]. If i lies inside it,
// initialize p[i] using its mirror position and then expand further.
// Track the maximum radius and convert the center/radius back to the original string.
//
// Time: O(n)
// Space: O(n)

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;
        int bestCenter = 0, bestLen = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            if (i < right)
                p[i] = min(right - i, p[mirror]);
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
                p[i]++;
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
            if (p[i] > bestLen) {
                bestLen = p[i];
                bestCenter = i;
            }
        }
        int start = (bestCenter - bestLen) / 2;
        return s.substr(start, bestLen);
    }
};
