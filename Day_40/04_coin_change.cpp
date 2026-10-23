/*
Day 41 — DP (cont.)
Problem: Coin Change

Given coin denominations and an amount, return the minimum number
of coins needed to make that amount. Return -1 if it is impossible.
Each coin can be used unlimited times.

Approach 1: Top-Down DFS + Memoization
Pattern: Try each coin and memoize the minimum coins needed for each
         remaining amount.
Time: O(amount * number of coins)
Space: O(amount) for memoization and recursion stack.

Approach 2: BFS
Pattern: Treat each amount as a node. Adding one coin is one step.
         BFS finds the fewest steps (coins) needed to reach the target.
Time: O(amount * number of coins)
Space: O(amount)

Approach 3: Bottom-Up 1D DP (Space-Optimized)
Pattern: dp[a] stores the minimum coins needed to make amount a.
         Process amounts upward so each coin can be reused.
Time: O(amount * number of coins)
Space: O(amount)
*/

// Approach 1: Top-Down DFS + Memoization
class CoinChangeTopDown {
private:
    int dfs(int remaining, const vector<int>& coins, vector<int>& memo,
            int impossible) {
        if (remaining == 0) return 0;
        if (memo[remaining] != -1) return memo[remaining];

        int best = impossible;

        for (int coin : coins) {
            if (coin <= remaining) {
                int result = dfs(remaining - coin, coins, memo, impossible);

                if (result != impossible) {
                    best = min(best, result + 1);
                }
            }
        }

        return memo[remaining] = best;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int impossible = amount + 1;
        vector<int> memo(amount + 1, -1);

        int result = dfs(amount, coins, memo, impossible);
        return result == impossible ? -1 : result;
    }
};

// Approach 2: BFS
class CoinChangeBFS {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        queue<pair<int, int>> q; // {current amount, coins used}
        vector<bool> visited(amount + 1, false);

        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [currentAmount, coinsUsed] = q.front();
            q.pop();

            for (int coin : coins) {
                int nextAmount = currentAmount + coin;

                if (nextAmount == amount) {
                    return coinsUsed + 1;
                }

                if (nextAmount < amount && !visited[nextAmount]) {
                    visited[nextAmount] = true;
                    q.push({nextAmount, coinsUsed + 1});
                }
            }
        }

        return -1;
    }
};

// Approach 3: Bottom-Up 1D DP (Space-Optimized)
class CoinChangeOptimized {
public:
    int coinChange(vector<int>& coins, int amount) {
        int impossible = amount + 1;
        vector<int> dp(amount + 1, impossible);

        dp[0] = 0; // 0 coins are needed to make amount 0.

        for (int coin : coins) {
            // Go upward so this coin can be used multiple times.
            for (int currentAmount = coin;
                 currentAmount <= amount;
                 currentAmount++) {
                if (dp[currentAmount - coin] != impossible) {
                    dp[currentAmount] = min(
                        dp[currentAmount],
                        dp[currentAmount - coin] + 1
                    );
                }
            }
        }

        return dp[amount] == impossible ? -1 : dp[amount];
    }
};
