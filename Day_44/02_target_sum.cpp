// Day 44 — DP 2D (cont.)
// Problem: Target Sum
//
// My notes:
//
// We assign either '+' or '-' to every number and count how many assignments
// produce target. The same total can be reached in multiple ways, so each DP
// state stores a count of assignments.
//
// Pattern: Dynamic programming over index and current sum.
//
// 1. 2D DP
// dp[i][s + total] = ways to get sum s using the first i numbers.
// The offset `total` lets us represent negative sums as array indices.
// For each number, add its count to both the '+' and '-' next-sum states.
// A zero contributes to both transitions, correctly doubling the number of ways.
//
// Time: O(n * total)
// Space: O(n * total)
//
// 2. Space-Optimized Bottom-Up DP
// Keep only the current and next sum-count arrays. Each number's transitions
// are built from the previous array, so the same number is used exactly once.
//
// Time: O(n * total)
// Space: O(total)
//
// 3. Knapsack Transformation
// Let positiveSum be the sum of numbers assigned '+', and negativeSum the sum
// assigned '-'. Then:
//   positiveSum - negativeSum = target
//   positiveSum + negativeSum = total
// So positiveSum = (total + target) / 2.
// The problem becomes counting subsets whose sum is positiveSum. Iterate sums
// backwards so each number is used at most once. If total + target is negative,
// too large, or odd, there are no valid assignments.
//
// Time: O(n * positiveSum)
// Space: O(positiveSum)

#include <bits/stdc++.h>
using namespace std;

// 1. 2D DP
class Solution2D {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, 0));
        dp[0][total] = 1;

        for (int i = 0; i < n; i++) {
            for (int index = 0; index <= 2 * total; index++) {
                if (dp[i][index] == 0) continue;

                int num = nums[i];
                dp[i + 1][index + num] += dp[i][index];
                dp[i + 1][index - num] += dp[i][index];
            }
        }

        return dp[n][target + total];
    }
};

// 2. Space-Optimized Bottom-Up DP
class SolutionOptimized {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total) return 0;

        vector<int> dp(2 * total + 1, 0);
        dp[total] = 1;

        for (int num : nums) {
            vector<int> nextDp(2 * total + 1, 0);

            for (int index = 0; index <= 2 * total; index++) {
                if (dp[index] == 0) continue;

                nextDp[index + num] += dp[index];
                nextDp[index - num] += dp[index];
            }

            dp = move(nextDp);
        }

        return dp[target + total];
    }
};

// 3. Knapsack Transformation
class SolutionKnapsack {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total || (total + target) % 2 != 0) return 0;

        int positiveSum = (total + target) / 2;
        vector<int> dp(positiveSum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int sum = positiveSum; sum >= num; sum--) {
                dp[sum] += dp[sum - num];
            }
        }

        return dp[positiveSum];
    }
};
