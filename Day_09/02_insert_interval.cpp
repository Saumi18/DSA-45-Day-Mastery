// Day 09 — Prefix + Intervals
// Problem: Insert Interval
//
// My notes:
// Pattern: Intervals + Merge
// Idea: 3 cases → Before, Overlap, After
// Before  → push current
// Overlap → expand newInterval using min/max
// After   → push newInterval + remaining intervals
//
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++){
            // Current interval is AFTER newInterval
            if(intervals[i][0] > newInterval[1]){
                ans.push_back(newInterval);
                while(i < intervals.size()){
                    ans.push_back(intervals[i]);
                    i++;
                }
                return ans;
            }
            // Current interval is BEFORE newInterval
            else if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            }
            // Overlap → merge
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        // Add newInterval if not already added
        ans.push_back(newInterval);
        return ans;
    }
};
