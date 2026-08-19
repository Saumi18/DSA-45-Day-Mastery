// Day 09 — Prefix + Intervals
// Problem: Range Sum Query - Immutable
//
// My notes:
// Pattern: Prefix Sum
//
// Idea:
// Store cumulative sum up to every index.
// prefixSum[i] = nums[0] + nums[1] + ... + nums[i]
//
// For sum from left to right:
// If left == 0:
//     sum = prefixSum[right]
// Else:
//     sum = prefixSum[right] - prefixSum[left-1]
//
// Why?
// prefixSum[right] contains everything from 0 → right.
// Subtracting prefixSum[left-1] removes everything before left.
//
// Time: O(n) preprocessing, O(1) per query
// Space: O(n)
//
// Important:
// Prefix Sum is useful when we have MANY range-sum queries
// on an array that does NOT change.
//
// Example:
// nums = [2, 4, 1, 5, 3]
// prefixSum = [2, 6, 7, 12, 15]
//
// sumRange(1,3)
// = prefixSum[3] - prefixSum[0]
// = 12 - 2
// = 10
//
//
// Alternative cleaner approach:
// Store prefixSum with an initial 0:
// [0, 2, 6, 7, 12, 15]
// Then every query can use:
// prefixSum[right+1] - prefixSum[left]


class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefixSum.push_back(sum);
        }
    }
    int sumRange(int left, int right) {
        if(left == 0) {
            return prefixSum[right];
        }
        else {
            return prefixSum[right] - prefixSum[left-1];
        }
    }
};
