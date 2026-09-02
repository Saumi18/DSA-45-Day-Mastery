// Day 22 — Bit Manipulation
// Problem: Reverse Bits
//
// My notes:
// Pattern: Bit Extraction + Bit Shifting
// Idea: Extract the i-th bit using (n >> i) & 1, then place it at the
// reversed position (31 - i) in the result.
//
// Time: O(32) = O(1)
// Space: O(1)


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res =0;
        for(int i=0;i<32;i++){
            uint32_t bit = (n>>i)&1;
            res += (bit<<(31-i));
        }
        return res;
    }
};


