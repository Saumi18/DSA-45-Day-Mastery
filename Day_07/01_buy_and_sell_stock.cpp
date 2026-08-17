// Day 07 — Sliding Window
// Problem: Buy & Sell Stock
//
// My notes:
// Pattern: Two ptrs
// Time: O(n)
// Space: O(n)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = 1;
        int maxProfit = 0;
        while(r<n){
            if(prices[l]<prices[r]){
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit,profit);
                r++;
            }
            else if(prices[l]>=prices[r]){
                l = r;
                r++;
            }
        }
        return maxProfit;
    }
};

