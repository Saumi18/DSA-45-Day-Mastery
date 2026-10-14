// Day 37 — Backtracking (cont.)
// Problem: Subsets II
//
// My notes:
// Pattern: Backtracking (Choose, Explore, Undo) + Sorting to handle duplicates.
// Steps:
// 1. Sort nums so duplicate elements are adjacent.
// 2. Add cur to res at every recursive call.
// 3. Loop from index i and skip duplicates using if(j > i && nums[j] == nums[j - 1]).
// 4. Choose nums[j], add it to cur, and recurse from j + 1.
// 5. Remove nums[j] using pop_back() to backtrack.
// Time: O(n * 2^n), including copying subsets.
// Space: O(n) auxiliary space for recursion and cur, excluding output.


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(),nums.end());
        backtrack(nums,cur,0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, int i){
        res.push_back(cur);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j] == nums[j-1]) continue;
            cur.push_back(nums[j]);
            backtrack(nums, cur, j+1);
            cur.pop_back();
        }
    }
};

