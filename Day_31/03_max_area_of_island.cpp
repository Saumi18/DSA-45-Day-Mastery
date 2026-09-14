// Day 33 — Graphs / Grid DFS-BFS
// Problem: Max Area of Island
//
// Approach 1: DFS
// Pattern: DFS / Connected Components
// Idea: Scan every cell. When an unvisited '1' is found, it represents a new island.
//       Run DFS to visit the complete island and return its area.
//       Mark every visited cell as '0' to avoid visiting it again.
//       Take the maximum area among all islands.
//
// Time: O(m × n)
// Space: O(m × n) worst case due to recursion stack
//
// Approach 2: BFS
// Pattern: BFS / Connected Components
// Idea: Scan every cell. When an unvisited '1' is found, start BFS.
//       Put the cell into a queue and mark it as '0'.
//       Visit all connected land cells using the 4 directions.
//       Count the number of cells visited for this island.
//       Take the maximum area among all islands.
//
// Time: O(m × n)
// Space: O(m × n) worst case due to the queue
//
// Key Pattern:
// Find '1' → explore complete island → calculate its area → update maximum.
//
// 4 directions:
// Down, Up, Right, Left


class Solution {
private:
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;

        for(int i = 0; i < 4; i++){
            area += dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
        return area;
    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({r, c});
        grid[r][c] = 0;
        int area = 0;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            area++;

            for(int i = 0; i < 4; i++){
                int nr = x + directions[i][0];
                int nc = y + directions[i][1];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        return area;
    }

public:
    int maxAreaOfIslandDFS(vector<vector<int>>& grid) {
        int ans = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    ans = max(ans, dfs(grid, r, c));
                }
            }
        }
        return ans;
    }

    int maxAreaOfIslandBFS(vector<vector<int>>& grid) {
        int ans = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    ans = max(ans, bfs(grid, r, c));
                }
            }
        }
        return ans;
    }
};
