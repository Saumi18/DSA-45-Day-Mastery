// Day 39 — DP 1D
// Problem: House Robber
//
// My notes:
// Pattern: We cannot rob two adjacent houses. At each house, choose to skip it
//          or rob it and add its money to the best result from two houses back.
//
// Recurrence: dp[i] = max(dp[i-1], nums[i] + dp[i-2])
//             dp[i] stores the maximum money rob-able from houses 0 to i.
//
// 1. Top-down: Recursively consider robbing or skipping each house.
//              Memoization stores results to avoid repeated calculations.
// 2. Bottom-up: Fill the DP array from left to right using the recurrence.
// 3. Space optimized: Keep only the results from the previous two houses,
//                     since earlier DP values are no longer needed.
//
// Time: O(n) for all three approaches.
// Space: O(n) for top-down memoization and bottom-up DP;
//        O(1) for the space-optimized approach.

// 1.TOP DOWN APPROACH (MEMOIZATION)
class Solution {
    int solve(vector<int>& nums, int i, vector<int>& memo) {
        if (i < 0) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = max(solve(nums, i - 1, memo),
                            nums[i] + solve(nums, i - 2, memo));
    }

public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, nums.size() - 1, memo);
    }
};

// 2. BOTTOM UP DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int robCurrent = nums[i] + (i >= 2 ? dp[i - 2] : 0);
            dp[i] = max(dp[i - 1], robCurrent);
        }

        return dp[n - 1];
    }
};

// 3. BOTTOM UP SPACE OPTIMISED APPROACH
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;

        for (int money : nums) {
            int current = max(prev1, money + prev2);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
