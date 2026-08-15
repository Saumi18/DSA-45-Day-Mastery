// Day 04 — Two Pointers
// Problem: 3Sum
//
// My notes:
// Pattern: Sort + Fix one element + Two Pointers; skip duplicates for unique triplets.
// Time: O(n²)
// Space: O(1) extra space (excluding output)


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue; // THis is to avoid duplicates
            int target = -nums[i];
            int l =i+1;
            int r = nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r] == target){
                    res.push_back({nums[i],nums[l],nums[r]});
                    // Skip duplicate left/right values
                    while(l < r && nums[l] == nums[l + 1])
                        l++;

                    while(l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r] > target) r--;
                else l++;
            }
        }
        return res;
    }
};
