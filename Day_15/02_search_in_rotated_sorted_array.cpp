// Day 15 — Binary Search (cont.)
// Problem: Search in Rotated Sorted Array
//
// My notes:
// Pattern: Binary Search on Rotated Sorted Array
// Time: O(log n)
// Space: O(1)
//
// Intuition:
// At every step, one half of the array is sorted.
//
// 1. Check which half is sorted:
//    nums[l] <= nums[mid] → left half is sorted
//    otherwise → right half is sorted
//
// 2. If left half is sorted:
//    If nums[l] <= target < nums[mid]:
//        target is in left half → r = mid - 1
//    Else:
//        target is in right half → l = mid + 1
//
// 3. If right half is sorted:
//    If nums[mid] < target <= nums[r]:
//        target is in right half → l = mid + 1
//    Else:
//        target is in left half → r = mid - 1
//
// Key idea:
// First identify the sorted half, then check whether target
// lies inside that sorted range.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};
