// Day 39 — DP 1D
// Problem: Min Cost Climbing Stairs
//
// My notes:
// Pattern: At each step, we can climb 1 or 2 steps. We may start at step 0
//          or step 1, and we need the minimum cost to reach the top.
//
// Top-down: dfs(i) gives the minimum cost to reach the top starting from step i.
//           Pay cost[i], then choose the cheaper of moving to i+1 or i+2.
//           The top is reached when i >= cost.size(); memoization avoids
//           recalculating the same step.
//
// Bottom-up: dp[i] is the minimum cost to reach step i. The top is step n,
//            so dp[n] = min(dp[n-1] + cost[n-1], dp[n-2] + cost[n-2]).
//            Build the values from step 2 through step n.
//
// In-place: Work backward, adding to cost[i] the cheaper value of cost[i+1]
//           and cost[i+2]. Then min(cost[0], cost[1]) is the cost of starting
//           from either allowed step. This modifies the input vector.
//
// Time: O(n) for all three approaches.
// Space: O(n) for top-down memoization and bottom-up DP; O(1) extra for in-place.

// 1. BOTTOM UP APPROACH
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            dp[i] = min(cost[i - 1] + dp[i - 1],
                        cost[i - 2] + dp[i - 2]);
        }

        return dp[n];
    }
};

// 2. TOP DOWN APPROACH
class Solution {
    vector<int> memo;

    int dfs(vector<int>& cost, int i) {
        if (i >= cost.size()) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = cost[i] + min(dfs(cost, i + 1),
                                       dfs(cost, i + 2));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        memo.assign(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }
};

// 3. IN PLACE APPROACH (SPACE OPTIMISED DP)
class Solution {
    vector<int> memo;

    int dfs(vector<int>& cost, int i) {
        if (i >= cost.size()) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = cost[i] + min(dfs(cost, i + 1),
                                       dfs(cost, i + 2));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        memo.assign(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }
};
