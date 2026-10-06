// Day 33 — Graphs (cont.)
// Problem: Islands and Treasure
//
// My notes:
// Pattern: Multi-source BFS
//
// Idea:
// Start BFS from all treasure cells (0) at the same time.
// Each cell stores its shortest distance from the nearest treasure.
// When an unvisited empty cell (INT_MAX) is reached,
// set its distance = current cell's distance + 1.
//
// Why Multi-source BFS?
// We need the distance to the nearest treasure.
// Starting from all treasures simultaneously guarantees
// the first time we reach a cell is through its shortest path.
//
// Time: O(m * n)
// Space: O(m * n)


class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        vector<pair<int,int>> dirs = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto [dr, dc] : dirs) {
                int r = row + dr;
                int c = col + dc;

                if(r < 0 || r >= m || c < 0 || c >= n ||
                   grid[r][c] != INT_MAX)
                    continue;

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};
