// Day 15 — Binary Search (cont.)
// Problem: Find Minimum in Rotated Sorted Array
//
// Pattern: Binary Search on Rotated Sorted Array
// Time: O(log n)
// Space: O(1)
//
// Intuition:
// Compare nums[mid] with nums[r].
// 1. nums[mid] > nums[r]:
//    Minimum is on the right side → l = mid + 1
//
// 2. nums[mid] <= nums[r]:
//    Minimum is at mid or on the left side → r = mid
//
// We use r = mid (not mid - 1) because mid itself
// can be the minimum.
//
// When l == r, that index contains the minimum.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                // Minimum is to the right of mid
                l = mid + 1;
            }
            else {
                // Minimum is at mid or to the left
                r = mid;
            }
        }
        return nums[l]; // we can also return nums[r] as l==r exit condn
    }
};
