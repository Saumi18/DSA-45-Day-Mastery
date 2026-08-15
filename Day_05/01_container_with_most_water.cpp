// Day 05 — Two Pointers
// Problem: Container With Most Water
//
// My notes:
// Pattern: Two Pointers — start from both ends and move the shorter height inward.
// The shorter height limits the area, so moving it may find a taller boundary.
// Time: O(n)
// Space: O(1)


class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0;
        int r = heights.size()-1;
        while(l<r){
            int area = (r-l)*min(heights[l],heights[r]);
            res = max(area,res);
            // Move the pointer whose height is lower
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return res;
    }
};

