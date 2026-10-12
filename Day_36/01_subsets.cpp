// Day 36: Backtracking
// Problem: Subsets
//
// Pattern: For each element, explore two choices:
//          1. Include the element in the current subset.
//          2. Exclude the element from the current subset.
//          Use push_back() to include and pop_back() to undo the choice.
//          When all elements are processed, add the subset to the result.
//
// Time: O(n * 2^n) because there are 2^n subsets, each taking up to O(n) to copy.
// Space: O(n) auxiliary space for the recursion stack and current subset,
//        excluding the output.


class Solution {
private:
    void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res){
        if(i>=nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i+1,subset,res);
        subset.pop_back();
        dfs(nums,i+1,subset,res);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums,0,subset,res);
        return res;
    }
};

