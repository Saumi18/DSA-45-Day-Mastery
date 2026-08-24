// Day 14 — Binary Search
// Problem: Binary Search
//
// My notes:
// Pattern: Binary Search / Divide and Conquer
// Logic: Check the middle element and eliminate half of the search space
// If nums[mid] > target, search left half
// If nums[mid] < target, search right half
// Use mid = l + (r-l)/2 to avoid integer overflow
// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
};
