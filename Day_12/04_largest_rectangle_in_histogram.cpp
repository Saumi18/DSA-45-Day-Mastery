// Day 12 — Stack (cont.)
// Problem: Largest Rectangle in Histogram
//
// My notes:
// Pattern: Monotonic Increasing Stack
// Store: {start index, height}
// Pop when current height < stack top
// Carry start index after popping
// Extra 0 acts as cleanup for remaining bars
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int areaMax = 0;
        int area = 0;
        stack<pair<int,int>> st;
        for(int i=0;i<=heights.size();i++){
            int currHeight = (i==heights.size()) ? 0 : heights[i];
            // 0 at the end forces all remaining bars to be processed
            int start = i;
            // Current smaller bar stops taller bars in the stack
            while(!st.empty() && currHeight<st.top().second){
                start = st.top().first;
                area = (i-st.top().first)*st.top().second;
                areaMax = max(areaMax,area);
                st.pop();
            }
            // Store the earliest start with the current height
            st.push({start,currHeight});
        }
        return areaMax;
    }
};

