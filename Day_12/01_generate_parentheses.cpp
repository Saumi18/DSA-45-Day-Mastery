// Day 11 — Backtracking
// Problem: Generate Parentheses
//
// My notes:
// Pattern: Backtracking + Recursion
// open < n → add '('
// close < open → add ')'
// open == close == n → store answer
// push → explore → pop (backtrack)
// Time: O(4^n / sqrt(n)) approximately
// Space: O(n) recursion + O(n) current string


class Solution {
public:
    vector<string> ans;
    
    // Generates all valid parenthesis combinations using backtracking
    void backtrack(string& s, int open, int close, int n){
        // All brackets used → valid combination
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        // Add '(' if opening brackets are still available
        if(open < n){
            s.push_back('(');
            backtrack(s, open + 1, close, n);
            s.pop_back(); // Backtrack
        }

        // Add ')' only when there is an unmatched '('
        if(close < open){
            s.push_back(')');
            backtrack(s, open, close + 1, n);
            s.pop_back(); // Backtrack
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        backtrack(s, 0, 0, n);
        return ans;
    }
};
