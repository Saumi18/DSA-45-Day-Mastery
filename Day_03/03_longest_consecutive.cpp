// Day 03 — Arrays Deep
// Problem: Longest Consecutive
//
// My notes:
// Pattern: Hash Set — check if current number is the START (num-1 not present),
//           then keep checking num+1, num+2... to find sequence length.
//           Sorting approach: sort first, then count consecutive numbers;
//           skip duplicates.
//
// Time: O(n log n) sorting approach; O(n) average Hash Set approach
// Space: O(n) for temp in sorting approach; O(n) for unordered_set approach

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

// This is O(n) T.C and S.C by using a Hash Set lookup in Set is O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(numSet.find(nums[i]-1)==numSet.end()){
                // The condition means nums[i] - 1 NOT exist in set
                int len = 1;
                while(numSet.find(nums[i]+len) != numSet.end()){
                    //The condition means nums[i]+len EXIST in set
                    len++;
                }
                ans = max(len,ans);
            }
        }
        return ans;
    }
};




