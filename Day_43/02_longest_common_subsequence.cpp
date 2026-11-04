// Day 43 — DP 2D
// Problem: Longest Common Subsequence
//
// Goal: length of the longest sequence of characters that appears in both strings
// in the same relative order (characters need not be contiguous).
//
// State: lcs(i, j) = LCS length of text1[i:] and text2[j:] (suffixes).
// Base case: if i or j reaches the end of its string, the answer is 0.
// Transition:
//   text1[i] == text2[j] -> 1 + lcs(i + 1, j + 1)             (take the match, move both)
//   otherwise            -> max(lcs(i + 1, j), lcs(i, j + 1)) (skip one char from either string)
// Why taking the match is always safe: matching the first equal pair never makes the
// answer worse, so there is no need to also try skipping it.
//
// 1. Top-Down Memoization
// Pattern: Recursion on (i, j) with a memo table; -1 means "not computed yet".
// Each state is solved once, then reused. Easiest to derive, but uses recursion stack
// of depth up to m + n.
// Time: O(m * n)
// Space: O(m * n) memo + O(m + n) recursion stack
//
// 2. Bottom-Up DP (2D)
// Pattern: dp[i][j] = LCS of text1[i:] and text2[j:]; table is (n + 1) x (m + 1) so the
// last row and column are the zero base cases.
// Fill i and j from the end to the start, so dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]
// are already known.
// Time: O(m * n)
// Space: O(m * n)
//
// 3. Optimized Bottom-Up DP (1D)
// Pattern: Row i only needs row i + 1, so keep a single row dp[0..m].
// While processing dp[j] (going right to left):
//   dp[j]     (before update) = dp[i + 1][j]     -> cell below
//   dp[j + 1] (already updated) = dp[i][j + 1]   -> cell to the right
//   prev                       = dp[i + 1][j + 1] -> diagonal, saved before it gets overwritten
// After updating dp[j], set prev = old dp[j] (temp) so it becomes the diagonal for j - 1.
// Swap so text2 is the shorter string; the row length is then min(m, n).
// Time: O(m * n)
// Space: O(min(m, n))

// APPROACH 1: MEMOIZATION
class Solution {
public:
    string a, b;
    vector<vector<int>> memo;

    int solve(int i, int j) {
        if (i == a.size() || j == b.size()) return 0;
        int &res = memo[i][j];
        if (res != -1) return res;
        if (a[i] == b[j]) return res = 1 + solve(i + 1, j + 1);
        return res = max(solve(i + 1, j), solve(i, j + 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        a = text1;
        b = text2;
        memo.assign(a.size(), vector<int>(b.size(), -1));
        return solve(0, 0);
    }
};

// APPROACH 2: BOTTOM-UP DP (2D)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

// APPROACH 3: DP optimised (1D)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) {
            swap(text1, text2);
        }

        vector<int> dp(text2.size() + 1, 0);

        for (int i = text1.size() - 1; i >= 0; --i) {
            int prev = 0;
            for (int j = text2.size() - 1; j >= 0; --j) {
                int temp = dp[j];
                if (text1[i] == text2[j]) {
                    dp[j] = 1 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j + 1]);
                }
                prev = temp;
            }
        }

        return dp[0];
    }
};
