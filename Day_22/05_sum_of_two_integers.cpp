// Day 22 — Bit Manipulation
// Problem: Sum of Two Integers
//
// My notes:
// Pattern: Bit Manipulation + XOR + AND
// Idea: XOR gives addition without carry. AND finds the carry bits.
// Shift the carry left by 1 and repeat until there is no carry.
//
// Time: O(1)
// Space: O(1) 


class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
