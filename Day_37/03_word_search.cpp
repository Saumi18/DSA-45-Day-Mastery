// Day 38 — Backtracking
// Problem: Word Search
//
// My notes:
// Pattern: Backtracking + DFS + Matrix
// Time: O(ROWS * COLS * 4^L)
// Space: O(L) auxiliary space, excluding input
//
// Approach:
// 1. Start DFS from every cell matching the first character.
// 2. Check whether the current cell matches word[i].
// 3. Mark the cell as visited using '#'.
// 4. Explore all four adjacent directions.
// 5. Restore the original character while backtracking.
//
// Key points:
// - Each cell can be used only once in a path.
// - '#' marks a visited cell temporarily.
// - Restore the cell after exploring all directions.
// - i == word.size() means the entire word was found.
// - No separate visited matrix is required.


class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(dfs(board, word, r, c, 0)) return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        // Entire word has been matched
        if(i == word.size()) return true;

        // Check boundaries, visited cells, and character mismatch
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS ||
           board[r][c] == '#' || board[r][c] != word[i]) {
            return false;
        }

        // Mark the current cell as visited
        board[r][c] = '#';

        // Explore all four adjacent directions
        for(auto& d : dirs) {
            if(dfs(board, word, r + d[0], c + d[1], i + 1)) {
                board[r][c] = word[i];
                return true;
            }
        }

        // Backtrack: restore the original character
        board[r][c] = word[i];

        return false;
    }
};
