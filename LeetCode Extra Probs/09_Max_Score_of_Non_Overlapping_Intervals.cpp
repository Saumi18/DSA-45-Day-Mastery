// Topic: Dynamic Programming + Binary Search
// Problem: (3414) Maximum Score of Non-Overlapping Intervals
//
// Pattern: Weighted Interval Scheduling + DP
// Idea: Sort intervals by their starting time.
//       For every interval, use binary search to find the first
//       interval that starts after the current interval ends.
//       From each interval, we have two choices: skip it and move
//       to the next interval, or take it, add its weight, and jump
//       to the next non-overlapping interval.
//       Use DP to store the maximum weight for each position and
//       number of intervals selected (up to 4).
//       If two choices give the same weight, choose the smaller
//       set of original indices lexicographically.
//
// Time: O(n log n * 4)
// Space: O(n * 4)

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // Store start, end, weight and original index
        vector<array<int,4>> a;
        for(int i=0;i<n;i++) a.push_back({intervals[i][0],intervals[i][1],intervals[i][2],i});
        sort(a.begin(),a.end());
        // Find the first non-overlapping interval for each interval
        vector<int> nxt(n);
        for(int i=0;i<n;i++){
            int l=i+1,r=n;
            while(l<r){
                int m=(l+r)/2;
                if(a[m][0]>a[i][1]) r=m;
                else l=m+1;
            }
            nxt[i]=l;
        }
        // dp[i][k] = maximum weight from i onwards using at most k intervals
        vector<vector<long long>> dp(n+1,vector<long long>(5,-1));
        // Store the indices that give the best answer
        vector<vector<vector<int>>> ans(n+1,vector<vector<int>>(5));
        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=4;k++){
                // Option 1: Skip the current interval
                dp[i][k]=dp[i+1][k];
                ans[i][k]=ans[i+1][k];
                // Option 2: Take the current interval
                long long take=a[i][2]+dp[nxt[i]][k-1];
                vector<int> cur=ans[nxt[i]][k-1];
                cur.push_back(a[i][3]);
                sort(cur.begin(),cur.end());
                // Take it if weight is better, or indices are lexicographically smaller
                if(take>dp[i][k]||(take==dp[i][k]&&cur<ans[i][k])){
                    dp[i][k]=take;
                    ans[i][k]=cur;
                }
            }
        }
        return ans[0][4];
    }
};
