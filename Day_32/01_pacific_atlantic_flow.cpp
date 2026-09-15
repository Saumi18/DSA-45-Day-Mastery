// Day 35 — Graphs / Grid DFS
// Problem: Pacific Atlantic Water Flow
//
// Pattern: Reverse DFS / Graph Traversal
// Idea: Instead of starting from every cell and checking whether water can reach
//       an ocean, start DFS from the oceans and move towards the cells.
//       Normally water flows from high → low.
//       In reverse, we can move from low → high.
//       So we can move to a neighbour only when:
//       heights[nr][nc] >= heights[r][c].
//
// Pacific Ocean touches the top and left borders.
// Atlantic Ocean touches the bottom and right borders.
// Run DFS from both oceans and mark which cells can reach each ocean.
// Cells reachable from both oceans are added to the answer.
//
// Time: O(m × n)
// Space: O(m × n)
//
// Key Pattern:
// Reverse the direction of the problem.
// Pacific reachable ∩ Atlantic reachable = answer.
//
// Important:
// In normal water flow:
// high → low
//
// In reverse DFS:
// low → high
//
// Example:
// 5 → 4 → 3 → ocean is valid.
// 5 → 4 → 5 is not valid because water cannot flow from 4 → 5.
class Solution {
public:
    int m, n;
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    // DFS finds all cells that can reach the given ocean in reverse.
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean) {
        // Mark the current cell as reachable from this ocean.
        ocean[r][c] = true;
        // Explore all four directions.
        for(auto& d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];
            // Ignore cells outside the grid.
            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            // Do not visit the same cell again.
            if(ocean[nr][nc])
                continue;
            // In reverse, we can move from current to a cell
            // with equal or greater height.
            if(heights[nr][nc] < heights[r][c])
                continue;
            dfs(heights, nr, nc, ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        // pacific[r][c] = true if the cell can reach the Pacific Ocean.
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        // atlantic[r][c] = true if the cell can reach the Atlantic Ocean.
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        // Pacific: top row and left column.
        // Atlantic: bottom row and right column.
        for(int c = 0; c < n; c++) {
            dfs(heights, 0, c, pacific);
            dfs(heights, m - 1, c, atlantic);
        }
        for(int r = 0; r < m; r++) {
            dfs(heights, r, 0, pacific);
            dfs(heights, r, n - 1, atlantic);
        }
        vector<vector<int>> ans;
        // A cell must be reachable from both oceans.
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }
        return ans;
    }
};
