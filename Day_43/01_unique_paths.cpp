// Day 43 — DP 2D
// Problem: Unique Paths
//
// 1. Math Method
// Pattern: Binomial coefficient C(m + n - 2, n - 1), choosing where the down/right moves go.
// Time: O(min(m, n))
// Space: O(1)
//
// 2. Optimized Bottom-Up DP
// Pattern: paths[r][c] = paths[r - 1][c] + paths[r][c - 1].
// Use a 1D array; dp[c] stores paths from above, and dp[c - 1] stores paths from the left.
// Time: O(m * n)
// Space: O(n)
//
// 3. Matrix BFS
// Pattern: Traverse the grid level by level, adding each cell's path count to its right and lower neighbors.
// Time: O(m * n)
// Space: O(m * n)

// APPROACH 1: MATH
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        if (m < n) swap(m, n);

        long long res = 1;
        int j = 1;
        for (int i = m; i < m + n - 1; i++) {
            res *= i;
            res /= j;
            j++;
        }
        return res;
    }
};

// APPROACH 2: DP optimised

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

// APPROACH 3: MATRIX BFS

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        ways[0][0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r + 1 < m) {
                if (ways[r + 1][c] == 0) q.push({r + 1, c});
                ways[r + 1][c] += ways[r][c];
            }
            if (c + 1 < n) {
                if (ways[r][c + 1] == 0) q.push({r, c + 1});
                ways[r][c + 1] += ways[r][c];
            }
        }
        return ways[m - 1][n - 1];
    }
};
