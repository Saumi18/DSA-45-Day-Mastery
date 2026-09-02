// Day 22 — Bit Manipulation
// Problem: Missing Number
//
// My notes:
// Pattern: XOR
// Idea: XOR all numbers from 0 to n with all elements of nums.
// Every number that appears twice cancels because x ^ x = 0.
// Only the missing number remains.
//
// Time: O(n)
// Space: O(1)


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;
        for (int i = 0; i < n; i++) {
            xorr ^= i ^ nums[i];
        }
        return xorr;
    }
};
