// Day 03 — Arrays Deep
// Problem: Longest Consecutive
//
// My notes:
// Pattern: 
// Time: 
// Space: 

// This is sorting approach in O(nlogn) T.c.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> temp;
        if (nums.size() == 0) return 0;
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(),temp.end());
        int cnt = 1;
        int ans = 1;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i+1]-temp[i] == 1) cnt++;
            else if(temp[i+1]-temp[i] == 0) continue;
            else cnt = 1;
            ans = max(ans,cnt);
        }
        return ans;
    }
};

// This is O(n) T.C and S.C


