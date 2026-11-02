// Day 41 — DP 1D (cont.)
// Problem: Longest Increasing Subsequence
//
// My notes:
// Pattern: DP with patience sorting / tails array
// dp[k] = smallest possible ending value of an increasing subsequence
//         of length k + 1.
// For each x:
//   - If x > dp.back(), extend the longest subsequence.
//   - Otherwise, replace the first value >= x (lower_bound) with x.
// Replacing keeps a smaller tail, making future extensions easier.
// dp is not necessarily an actual subsequence; its size is the LIS length.
// Strictly increasing requires lower_bound.
// Time: O(n log n)
// Space: O(n) 


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        int LIS = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
                LIS++;
                continue;
            }

            int idx = lower_bound(dp.begin(),
                                  dp.end(), nums[i]) - dp.begin();
            dp[idx] = nums[i];
        }

        return LIS;
    }
};
