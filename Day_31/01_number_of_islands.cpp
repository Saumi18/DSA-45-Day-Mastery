// Day 32 — Graphs / Grid DFS-BFS
// Problem: Number of Islands
//
// Approach 1: DFS
// Pattern: DFS / Connected Components
// Idea: Scan every cell. When an unvisited '1' is found, it represents a new island.
//       Increment the answer and use DFS to visit the entire connected island.
//       Mark visited land as '0' so it is not counted again.
// Time: O(m × n)
// Space: O(m × n) worst case due to recursion stack
//
// Approach 2: BFS
// Pattern: BFS / Connected Components
// Idea: Scan every cell. When an unvisited '1' is found, it represents a new island.
//       Increment the answer and use BFS to visit the entire connected island.
//       Mark cells as '0' when adding them to the queue to avoid revisiting.
// Time: O(m × n)
// Space: O(m × n) worst case due to the queue
//
// Key Pattern:
// Find '1' → count island → explore all 4 directions → mark visited as '0'.
// 4 directions: down, up, right, left.

class Solution {
private:
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';

        for(int i = 0; i < 4; i++){
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
    }

    void bfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = x + directions[i][0];
                int nc = y + directions[i][1];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == '1'){
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int numIslandsDFS(vector<vector<char>>& grid) {
        int ans = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    ans++;
                    dfs(grid, r, c);
                }
            }
        }
        return ans;
    }

    int numIslandsBFS(vector<vector<char>>& grid) {
        int ans = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    ans++;
                    bfs(grid, r, c);
                }
            }
        }
        return ans;
    }
};
