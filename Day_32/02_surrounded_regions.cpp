// Day 32 — Graphs contd.
// Problem: Surrounded Regions
//
// Pattern: Boundary DFS
// Idea: Instead of finding surrounded 'O' regions directly, first find all 'O's
//       connected to the boundary. These cells can never be surrounded.
//       Mark all boundary-connected 'O's as '#' temporarily.
//       Then scan the board:
//       'O' → 'X' because it is surrounded
//       '#' → 'O' because it is safe
//
// Why boundary DFS?
//       Any 'O' connected to the boundary has a path to the outside,
//       so it cannot be surrounded.
//
// Steps:
//       1. Run DFS from every boundary 'O'.
//       2. Mark all reachable 'O's as '#'.
//       3. Convert remaining 'O's to 'X'.
//       4. Convert '#' back to 'O'.
//
// Time: O(m × n)
// Space: O(m × n) worst case due to recursion stack
//
// Key Pattern:
// Boundary → DFS → Mark Safe → Flip Remaining
//
// Important:
// Do not flip 'O' during the first DFS.
// First identify all safe 'O's, then flip the remaining ones.

class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O'){
            return;
        }

        board[r][c] = '#';

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c - 1);
        dfs(board, r, c + 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int c = 0; c < n; c++){
            dfs(board, 0, c);
            dfs(board, m - 1, c);
        }

        for(int r = 0; r < m; r++){
            dfs(board, r, 0);
            dfs(board, r, n - 1);
        }

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
                else if(board[r][c] == '#'){
                    board[r][c] = 'O';
                }
            }
        }
    }
};
