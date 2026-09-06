// Topic: Dynamic Programming
// Problem: (115) Distinct Subsequences
//
// Pattern: 2D DP
// Idea: dp[i][j] = number of ways to form the first j characters of t
//       using the first i characters of s.
//       If characters match, either use s[i-1] or skip it.
//       If they don't match, skip s[i-1].
//
// Base Case:
//       dp[i][0] = 1  → empty t can always be formed by choosing nothing
//       dp[0][j] = 0  → non-empty t cannot be formed from empty s
//
// Time: O(n * m)
// Space: O(n * m)
//
// Optimized:
//       Since dp[i][j] only depends on the previous row,
//       we can reduce the space to O(m).
//       Iterate j from right to left to preserve dp[j-1].
//
// Time: O(n * m)
// Space: O(m)

class Solution {
public:
    // Approach 1: 2D DP
    int numDistinct2D(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(
            n + 1, vector<unsigned long long>(m + 1, 0)
        );
        // Empty t can be formed in exactly one way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    // Two choices:
                    // 1. Use s[i-1] to match t[j-1]
                    // 2. Skip s[i-1]
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    // Characters don't match, so skip s[i-1]
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }

    // Approach 2: 1D Space Optimized DP
    int numDistinct(string s, string t) {
        int m = t.size();
        vector<unsigned long long> dp(m + 1, 0);
        // Empty t can always be formed by choosing nothing
        dp[0] = 1;
        for (char ch : s) {
            // Traverse backwards so dp[j-1] is still
            // the value from the previous iteration
            for (int j = m; j >= 1; j--) {
                if (ch == t[j - 1]) {
                    // Use current character to form t[j-1]
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[m];
    }
};
