// Day 22 — Bit Manipulation
// Problem: Counting Bits
//
// My notes:
// Pattern: Dynamic Programming + Bit Manipulation
// Idea: For every number i, find the largest power of 2 <= i.
// i can be written as (i - offset) + offset, where offset has exactly one 1 bit.
// Therefore, bits[i] = bits[i - offset] + 1.
// Reuse previously calculated results instead of counting bits from scratch.
//
// Time: O(n)
// Space: O(n)


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int offset = 1;
        for(int i =1;i<=n;i++){
            if(i == offset*2){
                offset *= 2;
            }
            ans[i] = ans[i-offset] +1;
        }
        return ans;
    }
};

