// Day 37 — Backtracking (cont.)
// Problem: Combination Sum II
//
// My notes:
// Pattern: Backtracking + Sorting + Duplicate Skipping
// Time: O(2^n) worst case, excluding sorting
// Space: O(n) auxiliary space, excluding output
//
// Key points:
// 1. Sort to skip duplicates and break when nums[j] > target.
// 2. target - nums[j] updates the remaining target.
// 3. j + 1 ensures each element is used only once.
// 4. j > i skips duplicates at the same recursion level.
// 5. push_back() chooses; recursive call explores; pop_back() undoes.
// 6. The for loop explores the next choice, so no extra recursive
//    call is needed after pop_back().
// 7. Check target == 0 before other stopping conditions.

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        backtrack(candidates, cur, target, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, int target, int i) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        if(target < 0 || i >= nums.size()) return;

        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j - 1]) continue;
            
            // Array is sorted, so later elements will also be too large
            if(nums[j] > target) break;
            // Choose nums[j]
            cur.push_back(nums[j]);
            // Reduce target and move to j + 1 because each element
            // can be used only once
            backtrack(nums, cur, target - nums[j], j + 1);
            // Undo the choice to explore other combinations
            cur.pop_back();
        }
    }
};
