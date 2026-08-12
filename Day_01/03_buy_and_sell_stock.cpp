// Day 01 — Arrays
// Problem: Buy & Sell Stock
//
// My notes:
// Pattern: Two pointer or one pass (Greedy)
// Time: O(n)
// Space: O(1)

// This is two pointer approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int l=0, r=1;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int profit = prices[r]-prices[l];
                max_profit = max(profit,max_profit);
            }
            else l = r;
            r++;
        }
        return max_profit;
    }
};

// One Pass Greedy approach we maintin the minimum buy price and sell price is the iterator

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        int minBuy = prices[0];
        int maxProfit = 0;
        for(int sell=0;sell<n;sell++){
            int profit = prices[sell] - minBuy;
            minBuy = min(minBuy,prices[sell]);
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
    }
};

