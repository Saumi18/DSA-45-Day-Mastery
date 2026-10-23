/*
Day 40 — Longest Palindromic Substring

Pattern:
- DP: dp[i][j] is true if the substring s[i...j] is a palindrome.
  The first and last characters must match, and the inside substring
  must also be a palindrome. Single characters and matching pairs are
  the base cases.
- Manacher: Adds separators between characters so odd- and even-length
  palindromes can be handled uniformly. It stores each center's palindrome
  radius and reuses earlier results to avoid repeated comparisons.

Time and space:
- DP:       O(n^2) time, O(n^2) space
- Manacher: O(n) time,   O(n) space
*/

// 1. DP Approach
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLen = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    int len = j - i + 1;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// 2. MANACHER'S ALGORITHM
class Solution {
private:
    vector<int> manacher(const string& s) {
        string t = "#";

        for (char c : s) {
            t += c;
            t += '#';
        }

        int n = t.size();
        vector<int> p(n, 0);
        int left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            if (i < right) {
                p[i] = min(right - i, p[left + right - i]);
            }

            while (i - p[i] - 1 >= 0 &&
                   i + p[i] + 1 < n &&
                   t[i - p[i] - 1] == t[i + p[i] + 1]) {
                p[i]++;
            }

            if (i + p[i] > right) {
                left = i - p[i];
                right = i + p[i];
            }
        }

        return p;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        vector<int> p = manacher(s);
        int bestCenter = 0;
        int bestLen = 0;

        for (int i = 0; i < p.size(); i++) {
            if (p[i] > bestLen) {
                bestLen = p[i];
                bestCenter = i;
            }
        }

        int start = (bestCenter - bestLen) / 2;
        return s.substr(start, bestLen);
    }
};
