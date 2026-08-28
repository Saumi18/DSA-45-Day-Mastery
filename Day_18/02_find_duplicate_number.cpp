// Day 18 — Linked List Adv.
// Problem: Find Duplicate Number
//
// My notes:
// Pattern: Negative Marking / Visited Array
// Time: O(n)
// Space: O(1)
//
// Approach 1: Negative Marking
// Use each number as an index and mark nums[x] as negative.
// If nums[x] is already negative, x is the duplicate.
// Use abs() because values may have already been made negative.
//
// Approach 2: Floyd's Cycle Detection
// Treat the array like a linked list:
// index -> nums[index]
// here the pointers slow and fast represent nodes which themsef are the numbers in nums.
// The duplicate creates a cycle.
// Use slow (1 step) and fast (2 steps) pointers to find the cycle.
// First find the meeting point, then reset slow to nums[0].
// Move both fast and slow one step until they meet again — that node is the duplicate.
// Return the slow pointer.
// Time: O(n)
// Space: O(1)

// Approach 1: Negative Marking
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            // Take the absolute value because nums[i]
            // may have been made negative earlier.
            int x = abs(nums[i]);
            // If nums[x] is already negative,
            // x has been visited before -> duplicate found.
            if (nums[x] < 0)
                return x;
            // Mark x as visited by making nums[x] negative.
            nums[x] *= -1;
        }
        return -1;
    }
};

// Approach 2: Floyd's Cycle Detection
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Treat the array like a linked list:
        // current node -> nums[current]
        int slow = nums[0];
        int fast = nums[0];
        // Phase 1: Find the meeting point inside the cycle.
        do {
            slow = nums[slow];           // Move slow by 1 step
            fast = nums[nums[fast]];     // Move fast by 2 steps
        } while (slow != fast);
        // Phase 2: Find the entrance of the cycle.
        // The entrance represents the duplicate number.
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];           // Move 1 step
            fast = nums[fast];           // Move 1 step
        }
        // Both pointers meet at the duplicate.
        return slow;
    }
};
