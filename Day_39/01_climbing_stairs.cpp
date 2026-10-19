// Day 39 — DP 1D
// Problem: Climbing Stairs
//
// My notes:
// Pattern: At each step, we can climb either 1 or 2 steps.
//          To reach step i, we must come from step i-1 or i-2.
//          Therefore, dp[i] = dp[i-1] + dp[i-2].
//
// Base cases: dp[1] = 1, dp[2] = 2.
// Top-down: Use recursion to try both choices and memoize each result
//           so the same step is not calculated repeatedly.
// Bottom-up: Start with the base cases and fill the DP array up to n.
//
// Time: O(n) for both approaches.
// Space: O(n) for the memo/DP array; top-down also uses O(n) recursion stack.

// BOTTOM UP APPROACH
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// TOP DOWN APPROACH
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }

    int solve(int n, vector<int>& memo) {
        if (n <= 2) return n;
        if (memo[n] != -1) return memo[n];

        return memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    }
};
