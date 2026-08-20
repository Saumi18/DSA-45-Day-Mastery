// Day 09 — Prefix + Intervals
// Problem: Non-overlapping Intervals
//
// My notes:
// Pattern: Greedy + Sort by start
// Overlap → remove interval with larger end
// min(end) → keep interval ending earlier
// Time: O(n log n)
// Space: O(1) extra

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res=0;
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1][1]>intervals[i][0]){
                res++;
                // Keep the interval that ends earlier for future intervals
                intervals[i][1]=min(intervals[i-1][1],intervals[i][1]);
            }
        }
        return res;
    }
};
