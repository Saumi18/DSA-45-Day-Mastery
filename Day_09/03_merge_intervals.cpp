// Day 09 — Prefix + Intervals
// Problem: Merge Intervals
//
// My notes:
// Pattern: Sort + Merge Intervals
// Idea: Sort by start time, then compare with last interval in ans.
// If overlap → merge using max ending time.
// If no overlap → push current interval.
//
// Time: O(n log n) → sorting + O(n) merge
// Space: O(n) → output


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[0] = min(ans.back()[0],intervals[i][0]);
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};

