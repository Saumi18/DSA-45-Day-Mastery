// Day 22 — Bit Manipulation
// Problem: Reverse Integer
//
// My notes:
// Pattern: Digit Extraction + Overflow Check
// Idea: Extract the last digit using x % 10 and remove it using x / 10.
// Build the reversed number using res * 10 + digit. Before multiplying
// res by 10, check whether the result would exceed the 32-bit integer range.
//
// Time: O(log n)
// Space: O(1)


class Solution {
public:
    int reverse(int x) {
        const int MIN = -2147483648; // -2^31
        const int MAX = 2147483647;  // 2^31 - 1

        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
                return 0;
            if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
                return 0;
            res = (res * 10) + digit;
        }
        return res;
    }
};
