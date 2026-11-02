// Day 41 — DP 1D (cont.)
// Problem: Maximum Product Subarray
//
// My notes:
// Pattern: Modified Kadane's DP
// At each index, track the max and min product of a subarray ending here.
// Keep the minimum too: multiplying it by a negative number may make it the maximum.
// If current number x is negative, swap maxEnd and minEnd.
// maxEnd = max(x, maxEnd * x)  // start fresh or extend
// minEnd = min(x, minEnd * x)
// Update answer with maxEnd. A zero resets both states naturally.
// Initialize maxEnd, minEnd, and answer to nums[0].
//
// Time: O(n) — visit each number once
// Space: O(1) — keep only a few variables

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i];
            if (x < 0) {
                swap(maxEnding, minEnding);
            }

            maxEnding = max(x, maxEnding * x);
            minEnding = min(x, minEnding * x);
            answer = max(answer, maxEnding);
        }
        return answer;
    }
};
