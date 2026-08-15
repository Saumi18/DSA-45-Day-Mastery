// Day 05 — Two Pointers
// Problem: Trapping Rain Water
//
// My notes:
// Pattern: Two Pointers + track maximum height from both sides.
// Move the shorter side because it determines the limiting water level.
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        int maxLeft = height[l];
        int maxRight = height[r];

        while(l < r) {
            if(height[l] < height[r]) {
                // Right side is high enough, so left max limits water
                maxLeft = max(maxLeft, height[l]);
                res += maxLeft - height[l];
                l++;
            }
            else {
                // Left side is high enough, so right max limits water
                maxRight = max(maxRight, height[r]);
                res += maxRight - height[r];
                r--;
            }
        }

        return res;
    }
};
