/*
Day 40 — DP (cont.)
Problem: Decode Ways

A digit maps to a letter: 1 -> A, ..., 26 -> Z.
A '0' cannot be decoded alone; it is valid only in 10 or 20.

Approach 1: Top-Down DFS + Memoization
Pattern: Try taking one digit or a valid pair; memoize each index.
Time: O(n)
Space: O(n) for memoization and recursion stack.

Approach 2: Bottom-Up DP Array
Pattern: dp[i] stores the number of ways to decode s[i...n-1].
Time: O(n)
Space: O(n)

Approach 3: Bottom-Up Space-Optimized
Pattern: Keep only the next two DP values instead of the full array.
Time: O(n)
Space: O(1)
*/

// Approach 1: Top-Down DFS + Memoization
class DecodeWaysTopDown {
private:
    int dfs(int i, const string& s, vector<int>& memo) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;

        if (memo[i] != -1) return memo[i];

        int ways = dfs(i + 1, s, memo); // Take one digit

        // Take two digits if they form a number from 10 to 26
        if (i + 1 < s.size() &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ways += dfs(i + 2, s, memo);
        }

        return memo[i] = ways;
    }

public:
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return dfs(0, s, memo);
    }
};

// Approach 2: Bottom-Up DP Array
class DecodeWaysBottomUp {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 1; // One way to finish after reaching the end

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') continue;

            dp[i] = dp[i + 1]; // Take one digit

            // Take two digits if they form a number from 10 to 26
            if (i + 1 < n &&
                (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};

// Approach 3: Bottom-Up Space-Optimized
class DecodeWaysOptimized {
public:
    int numDecodings(string s) {
        int n = s.size();

        int dp1 = 1; // Ways from the next index; initially dp[n]
        int dp2 = 0; // Ways from two indices ahead

        for (int i = n - 1; i >= 0; i--) {
            int dp = 0;

            if (s[i] != '0') {
                dp = dp1; // Take one digit
                // Take two digits if they form a number from 10 to 26
                if (i + 1 < n &&
                    (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    dp += dp2;
                }
            }
            dp2 = dp1;
            dp1 = dp;
        }

        return next1;
    }
};
