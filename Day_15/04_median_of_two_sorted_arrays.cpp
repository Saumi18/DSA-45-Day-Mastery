// Day 15 — Binary Search (cont.)
// Problem: Median of Two Sorted Arrays
//
// My notes:
// Pattern: Binary Search on partition
// Time: O(log(min(n, m)))
// Space: O(1)
//
// Key Idea:
// Binary search on the smaller array to find the correct partition.
// i = elements taken from A for the left half
// j = half - i = elements taken from B for the left half
//
// Correct partition when:
// Aleft <= Bright && Bleft <= Aright
//
// For odd total:
// Median = max(Aleft, Bleft)
//
// For even total:
// Median = (max(Aleft, Bleft) + min(Aright, Bright)) / 2
//
// Boundary handling:
// No element on left  -> INT_MIN
// No element on right -> INT_MAX
//
// Why (total + 1) / 2?
// For odd total, the extra element is kept on the left.
// Example: 13 → 7 left, 6 right.
//
// Key takeaway:
// Binary search A's partition; B's partition is automatically
// determined by j = half - i.


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        // Number of elements that should be on the left side.
        // For odd total, extra element goes to the left.
        int half = (total + 1) / 2;
        // We always binary search on the smaller array.
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if(B.size() < A.size()) {
            swap(A, B);
        }
        // i = number of elements taken from A for the left half.
        // Partition can be before the first element or after the last.
        int l = 0;
        int r = A.size();
        while(l <= r) {
            // Partition position in A
            int i = l + (r - l) / 2;
            // Since total left elements must be 'half',
            // j is automatically determined.
            int j = half - i;
            // Elements immediately around the partition in A.
            // If partition is at the beginning, there is no Aleft.
            int Aleft = (i > 0) ? A[i - 1] : INT_MIN;
            // If partition is at the end, there is no Aright.
            int Aright = (i < A.size()) ? A[i] : INT_MAX;
            // Same idea for B.
            int Bleft = (j > 0) ? B[j - 1] : INT_MIN;
            int Bright = (j < B.size()) ? B[j] : INT_MAX;
            // Correct partition:
            // Every element on the left <= every element on the right.
            //
            // Because both arrays are sorted, we only need to check
            // the two boundary conditions.
            if(Aleft <= Bright && Bleft <= Aright) {
                // Odd number of elements:
                // The median is the largest element on the left.
                if(total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                // Even number of elements:
                // Median = average of the largest left
                // and smallest right elements.
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            // Too many elements taken from A.
            // Move A's partition to the left.
            else if(Aleft > Bright) {
                r = i - 1;
            }
            // Too few elements taken from A.
            // Move A's partition to the right.
            else {
                l = i + 1;
            }
        }
        return -1;
    }
};
