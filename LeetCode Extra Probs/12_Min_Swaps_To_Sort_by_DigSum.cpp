// Topic: Sorting
// Problem: (3551) Minimum Swaps to Sort by Digit Sum
//
// My notes:
// Pattern: Custom Sorting + Cycle Detection
// Time: O(n log n)
// Space: O(n)
//
// Approach:
// 1. Copy nums into sortedNums and sort by digit sum.
// 2. If digit sums are equal, sort by the number itself.
// 3. Map each number to its target index in the sorted array.
// 4. Use visited[] to find cycles of misplaced elements.
// 5. A cycle of size k requires k - 1 swaps.
// 6. Add cycleSize - 1 for every cycle and return swaps.
//
// Key points:
// - digSum() calculates the sum of a number's digits.
// - targetIndex[x] stores the index where x belongs.
// - visited[] prevents processing a cycle more than once.
// - Already correctly placed elements are skipped.
// - Cycle detection gives the minimum number of swaps.
// - Assumes nums contains distinct elements, as required by the problem.

class Solution {
private:
    int digSum(int n) {
        int sum = 0;
        while(n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;

        sort(sortedNums.begin(), sortedNums.end(), [&](int a, int b) {
            if(digSum(a) != digSum(b)) {
                return digSum(a) < digSum(b);
            }
            return a < b;
        });

        unordered_map<int, int> targetIndex;
        for(int i = 0; i < n; i++) {
            targetIndex[sortedNums[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] || targetIndex[nums[i]] == i) {
                continue;
            }
            int cycleSize = 0;
            int j = i;

            while(!visited[j]) {
                visited[j] = true;
                j = targetIndex[nums[j]];
                cycleSize++;
            }
            swaps += cycleSize - 1;
        }
        return swaps;
    }
};
