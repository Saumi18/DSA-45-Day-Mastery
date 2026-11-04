// Day 43 — DP 2D
// Problem: Best Time to Buy and Sell Stock with Cooldown
//
// Goal: maximum profit from any number of buy/sell transactions, holding at most one
// share at a time, with a one-day cooldown after every sell (you cannot buy the day
// right after selling).
//
// State: (i, buying) = best profit from day i onward.
//   buying = true  -> we hold no stock and may buy today.
//   buying = false -> we hold a stock and may sell today.
// Base case: i >= n means no days left, so profit is 0.
// Transition:
//   buying = true:  max(buy today  -> solve(i + 1, false) - prices[i],
//                       skip today -> solve(i + 1, true))
//   buying = false: max(sell today -> solve(i + 2, true) + prices[i],   (i + 2 = cooldown day skipped)
//                       skip today -> solve(i + 1, false))
// The cooldown is handled by jumping to i + 2 after a sell.
//
// 1. Top-Down Memoization
// Pattern: Recursion on (i, buying) with a memo table; -1 is not safe here only if profit
// can be -1, but profit is never negative, so -1 works as "not computed yet".
// Each state is solved once, then reused.
// Time: O(n)
// Space: O(n) memo + O(n) recursion stack
//
// 2. Bottom-Up DP (2D)
// Pattern: dp[i][1] = best profit from day i if we may buy, dp[i][0] = best profit if we hold.
// Array has n + 2 rows so dp[i + 2] is valid for the cooldown jump; the extra rows stay 0.
// Fill i from n - 1 down to 0, so dp[i + 1] and dp[i + 2] are already known.
// Time: O(n)
// Space: O(n)
//
// 3. Optimized State Machine (O(1))
// Pattern: Go forward day by day, tracking the best profit ending in each of 3 states:
//   hold = currently holding a stock
//   sold = just sold today (so tomorrow is the cooldown)
//   rest = holding nothing and free to buy
// Transitions for price p:
//   sold = hold + p                    (sell the stock we held)
//   hold = max(hold, rest - p)         (keep holding, or buy from a free state)
//   rest = max(rest, prevSold)         (stay free, or finish the cooldown)
// Buying only comes from rest, never from sold, which is what enforces the cooldown.
// Answer is max(sold, rest), since ending while holding is never better.
// Time: O(n)
// Space: O(1)

// APPROACH 1: MEMOIZATION
class Solution {
public:
    vector<int> p;
    vector<vector<int>> memo;

    int solve(int i, int buying) {
        if (i >= p.size()) return 0;
        int &res = memo[i][buying];
        if (res != -1) return res;
        if (buying) {
            return res = max(solve(i + 1, 0) - p[i], solve(i + 1, 1));
        }
        return res = max(solve(i + 2, 1) + p[i], solve(i + 1, 0));
    }

    int maxProfit(vector<int>& prices) {
        p = prices;
        memo.assign(p.size(), vector<int>(2, -1));
        return solve(0, 1);
    }
};

// APPROACH 2: BOTTOM-UP DP (2D)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
            dp[i][0] = max(dp[i + 2][1] + prices[i], dp[i + 1][0]);
        }

        return dp[0][1];
    }
};

// APPROACH 3: STATE MACHINE (O(1) space)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0], sold = 0, rest = 0;

        for (int i = 1; i < prices.size(); i++) {
            int prevSold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prevSold);
        }

        return max(sold, rest);
    }
};
