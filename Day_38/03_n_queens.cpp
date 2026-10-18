// Day 38 — Backtracking Adv.
// Problem: N-Queens
//
// My notes:
// Pattern: Place one queen per row. For each column, check the column
//          and both upper diagonals. If safe, place a queen and recurse
//          to the next row. Remove it afterward to try other positions.
//          When all rows are filled, save the board.
// Time: O(n * n!) for searching; O(n²) to copy each solution.
// Space: O(n²) for the board and O(n) recursion, excluding output.


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(0, board, res);
        return res;
    }

    void backtrack(int r, vector<string>& board, vector<vector<string>>& res) {
        if (r == board.size()) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < board.size(); c++) {
            if (isSafe(r, c, board)) {
                board[r][c] = 'Q';
                backtrack(r + 1, board, res);
                board[r][c] = '.';
            }
        }
    }

    bool isSafe(int r, int c, vector<string>& board) {
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};
