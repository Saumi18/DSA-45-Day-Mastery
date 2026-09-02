// Day 22 — Bit Manipulation
// Problem: Number of 1 Bits
//
// My notes:
// Pattern: Bit Manipulation + Right Shift
// Idea: Check the last bit using (n & 1) also can be checked using (n%2). If it is 1, add it to the result.
// Right shift n by 1 to check the next bit. Continue until n becomes 0.
//
// Time: O(32) = O(1)
// Space: O(1)


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += n & 1;
            // instead of n&1 we can also do n % 2 -> both give same ans
            n = n >> 1;
        }
        return res;
    }
};
