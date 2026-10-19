// Day 39 — DP 1D
// Problem: House Robber II
//
// Pattern: Houses are arranged in a circle, so the first and last houses
//          cannot both be robbed. Split the problem into two linear cases:
//          1. Rob houses 0 to n-2 (exclude the last house).
//          2. Rob houses 1 to n-1 (exclude the first house).
//          The answer is the maximum of these two cases. If there is only
//          one house, return its value directly.
//
// Recurrence: best[i] = max(best[i+1], nums[i] + best[i+2])
//             At each house, either skip it or rob it and skip the next one.
//
// Top-down: Recursively solve each choice and memoize results to avoid
//           recalculating the same house.
// Bottom-up: Fill a DP array from right to left for each linear range.
// Space optimized: Track only the results for the next two houses, since
//                  earlier DP values are no longer needed.
//
// Time: O(n) for all three approaches.
// Space: O(n) for top-down memoization and bottom-up tabulation;
//        O(1) extra space for the optimized approach.


// 1. TOP DOWN APPROACH (MEMOIZATION)
class Solution {
    int solve(vector<int>& nums, int i, int end, vector<int>& memo) {
        if (i > end) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = max(solve(nums, i + 1, end, memo),
                             nums[i] + solve(nums, i + 2, end, memo));
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> memo1(n, -1), memo2(n, -1);
        return max(solve(nums, 0, n - 2, memo1),
                   solve(nums, 1, n - 1, memo2));
    }
};

// 2. BOTTOM UP APPROACH DP
class Solution {
    int solveRange(vector<int>& nums, int start, int end) {
        vector<int> dp(nums.size() + 2, 0);

        for (int i = end; i >= start; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }

        return dp[start];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(solveRange(nums, 0, n - 2),
                   solveRange(nums, 1, n - 1));
    }
};

// 3. BOTTOM UP SPACE OPTIMISED
class Solution {
    int solveRange(vector<int>& nums, int start, int end) {
        int next1 = 0, next2 = 0;

        for (int i = end; i >= start; i--) {
            int current = max(next1, nums[i] + next2);
            next2 = next1;
            next1 = current;
        }

        return next1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(solveRange(nums, 0, n - 2),
                   solveRange(nums, 1, n - 1));
    }
};
