// Topic: Parity & Bit Manipulation
// Problem: Construct Uniform Parity Array II

// My notes:
// Pattern: Parity + Minimum Element
//
// Idea:
// We want all elements to have the same parity.
//
// The key is the smallest element (mn), because we can only subtract
// a smaller number from an element.
//
// If mn is odd:
// Every element can be made odd. For an even element, subtracting an
// appropriate smaller odd number changes its parity to odd.
// Odd elements can simply remain unchanged.
//
// If mn is even:
// An odd element cannot be changed to even because there is no smaller
// odd element available to subtract. Therefore, all elements must
// already be even.
//
// So:
// - Minimum odd -> always possible
// - Minimum even -> possible only if there are no odd elements
//
// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool hasOdd = false;
        for (int v : nums1) {
            if (v < mn) {
                mn = v;
            }
            if (v & 1) {
                hasOdd = true;
            }
        }
        if (mn & 1) {
            return true;
        }
        return !hasOdd;
    }
};
