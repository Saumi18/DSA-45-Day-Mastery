// Day 14 — Binary Search
// Problem: Koko Eating Bananas
//
// My notes:
// Pattern: Binary Search on Answer
// Logic: Binary search the eating speed k from 1 to max(piles)
// For each k, calculate total hours needed to finish all piles
// If time <= h, k is valid → try a smaller speed
// If time > h, k is too slow → increase speed
// At the end, l = smallest valid eating speed
// Time: O(n log(max(piles)))
// Space: O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l <= r) {
            int k = l + (r - l) / 2;
            int time = 0;

            for (int i = 0; i < piles.size(); i++) {
                if (piles[i] % k == 0)
                    time += piles[i] / k;
                else
                    time += piles[i] / k + 1;
            }
            if (time <= h) {
                // k works, try a smaller speed
                r = k - 1;
            }
            else {
                // k is too slow
                l = k + 1;
            }
        }
        return l;
    }
};
