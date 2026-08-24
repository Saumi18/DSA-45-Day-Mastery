// Day 14 — Binary Search
// Problem: Search a 2D Matrix
//
// My notes:
// Pattern: Binary Search on 2D Matrix
// Logic: Treat the matrix as a sorted 1D array
// Convert 1D index to 2D using:
// row = mid / n
// col = mid % n
// If matrix[row][col] < target, search right half
// If matrix[row][col] > target, search left half
// Time: O(log(m*n))
// Space: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            // row = mid / n;
            // col = mid % n;
            if (matrix[mid / n][mid % n] == target)
                return true;
            if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
