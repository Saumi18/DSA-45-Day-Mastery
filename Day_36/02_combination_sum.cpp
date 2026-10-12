// Day 36 — Backtracking
// Problem: Combination Sum
//
// Steps:
// 1. If target == 0, store the current combination in res.
// 2. If target < 0 or i >= nums.size(), stop exploring this path.
// 3. Include nums[i] in cur and recursively reduce target by nums[i], keeping i unchanged to reuse the number.
// 4. Remove nums[i] from cur to backtrack and undo the choice.
// 5. Skip nums[i] by recursively moving to i + 1.
// 6. Repeat until all valid combinations are found.
//
// Pattern: Backtracking (Choose, Explore, Undo). Each number can be reused unlimited times.
// Time: Exponential, approximately O(2^(target/min(nums)) * target/min(nums)), including copying combinations.
// Space: O(target/min(nums)) auxiliary space for the recursion stack and current combination, excluding output.

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(nums, target, cur, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& cur, int i){
        if(target ==0){
            res.push_back(cur);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        
        cur.push_back(nums[i]);
        backtrack(nums,target-nums[i],cur,i);
        cur.pop_back();
        backtrack(nums,target,cur,i+1);
    }
};

