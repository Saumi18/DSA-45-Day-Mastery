// Day 36 — Backtracking
// Problem: Permutations
//
// My notes:
// Steps:
// 1. Use cur to build the current permutation and used[] to track selected elements.
// 2. If cur.size() == nums.size(), store the permutation in res and return.
// 3. Loop through all elements and skip those already used.
// 4. Choose an unused element, add it to cur, and mark used[j] = true.
// 5. Recursively explore the next position.
// 6. Backtrack by removing the element and resetting used[j] = false.
//
// Pattern: Backtracking (Choose, Explore, Undo). Each element can be used exactly once per permutation.
// Time: O(n * n!), since there are n! permutations and copying each takes O(n).
// Space: O(n) auxiliary space for cur, used[], and the recursion stack, excluding output.

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        backtrack(nums, cur, used);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, vector<bool>& used) {
        if(cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for(int j = 0; j < nums.size(); j++) {
            if(used[j]) continue;
            
            cur.push_back(nums[j]);
            used[j] = true;
            
            backtrack(nums, cur, used);
            
            cur.pop_back();
            used[j] = false;
        }
    }
};
