// Day 44 — DP 2D (cont.)
// Problem: Coin Change II
//
// My notes:
//
// We are given coin denominations and an amount. We need to count the number
// of different combinations that make the amount. Each coin can be used
// unlimited times, but different orders of the same coins count as one
// combination. For example, using 1 then 2 is the same combination as 2 then 1.
//
// Pattern:
// Unbounded Knapsack + counting combinations.
// At each coin, either skip it or use it. If we use it, we can use that same
// coin again, which is why the recurrence stays at the same coin index.
//
// 1. Recursion + Memoization
// State: solve(i, amount) = number of ways to make amount using coins from
// index i onward.
// Choices:
//   - Skip coin i: solve(i + 1, amount)
//   - Use coin i: solve(i, amount - coins[i])
// Base cases:
//   - amount == 0: one valid way (use no more coins)
//   - i == coins.size(): no coins remain, so there are no ways
// Memoization stores each state so it is not recalculated.
//
// Time: O(n * amount)
// Space: O(n * amount) for the memo table, plus recursion stack
//
// 2. 2D Bottom-Up Tabulation
// dp[i][a] stores the number of ways to make amount a using coins from index i
// onward.
// Base case: dp[i][0] = 1 for every i, since amount 0 has one way: choose no coins.
// Transition:
//   - Skip coin i: dp[i + 1][a]
//   - Use coin i: dp[i][a - coins[i]]
// The second term uses row i again because the same coin can be reused.
// Fill coin indices backwards so the next row is already computed.
//
// Time: O(n * amount)
// Space: O(n * amount)
//
// 3. Space-Optimized Bottom-Up Tabulation
// dp[a] stores the number of ways to make amount a using the coins processed so far.
// Start with dp[0] = 1.
// For each coin, update amounts from coin to amount:
//   dp[a] += dp[a - coin]
// The amount loop goes forward because each coin can be reused.
// Keeping the coin loop on the outside counts combinations and avoids counting
// different orders of the same coins as separate answers.
//
// Time: O(n * amount)
// Space: O(amount)

// 1. Recursion + Memoization
class SolutionMemo {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return solve(0, amount, coins, memo);
    }

private:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& memo) {
        if (amount == 0) return 1;
        if (i == coins.size()) return 0;

        if (memo[i][amount] != -1) return memo[i][amount];

        int ways = solve(i + 1, amount, coins, memo);

        if (coins[i] <= amount) {
            ways += solve(i, amount - coins[i], coins, memo);
        }

        return memo[i][amount] = ways;
    }
};

// 2. 2D Bottom-Up Tabulation
class Solution2D {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {
                dp[i][a] = dp[i + 1][a];

                if (coins[i] <= a) {
                    dp[i][a] += dp[i][a - coins[i]];
                }
            }
        }

        return dp[0][amount];
    }
};

// 3. Space-Optimized Bottom-Up Tabulation
class Solution1D {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int a = coin; a <= amount; a++) {
                dp[a] += dp[a - coin];
            }
        }

        return dp[amount];
    }
};
