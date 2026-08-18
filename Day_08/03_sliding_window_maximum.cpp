// Day 08 — Sliding Window (cont.)
// Problem: Sliding Window Maximum
//
// My notes:
// Pattern: Fixed-size sliding window + Monotonic Deque
//
// Why deque?
// Brute force scans the entire window every time → O(n*k).
// Deque keeps only elements that can potentially become the maximum.
//
// Deque stores INDICES, not values.
// Values corresponding to indices are kept in decreasing order:
// front → largest → smaller → smaller → back
//
// When a new element nums[r] comes:
// 1. Remove smaller elements from the BACK.
//    They can never become maximum while nums[r] is present.
//
// 2. Add r to the BACK.
//
// 3. Remove indices from the FRONT if they are outside the window.
//
// 4. dq.front() always gives the index of the maximum element.
//
// Important:
// pop_back() → remove useless smaller elements
// pop_front() → remove elements that left the window
//
// Time: O(n)
// Each index enters and leaves the deque at most once.
// Space: O(k)
//
// Example:
// nums = [1,3,-1], k = 3
//
// Process:
// 1 → deque [1]
// 3 → remove 1 → deque [3]
// -1 → deque [3,-1]
// front = 3 → maximum
//
// Key takeaway:
// Monotonic decreasing deque → front always contains maximum.
// ------------------------------------------------------------

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Answer will have n-k+1 windows
        vector<int> res(nums.size() - k + 1);

        // Stores indices of useful elements
        deque<int> dq;

        int l = 0;
        int r = 0;

        while(r < nums.size()){

            // Remove smaller elements from the BACK.
            // They can never be maximum because nums[r] is larger.
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }

            // Add current index
            dq.push_back(r);

            // Remove indices that are outside the current window
            while(!dq.empty() && dq.front() < l){
                dq.pop_front();
            }

            // Once window reaches size k,
            // front of deque is the maximum
            if(r + 1 >= k){
                res[l] = nums[dq.front()];
                l++;
            }

            r++;
        }

        return res;
    }
};
