// Day 01 — Arrays
// Problem: Contains Duplicate
//
// My notes: If space complexity is required o(1) do sorting and check consecutive elements - T.C = O(nlogn) ; S.C = O(1)
//           If Time Complexity is priority use Hash set  - T.C. = o(n) ; S.C. = o(n)
// Pattern: Sets are data structures that cannot have duplicates but arrays can have. So if duplicate exist then set has less elements all unique but array has more so length differ.
// Time: o(n)
// Space: o(n)


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        if(nums.size()==s.size()){
            return false;
        }
        else return true;
    }
};

// Sorting n checking successive elements

class Solution {
public:
    bool hasDuplicate(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};
