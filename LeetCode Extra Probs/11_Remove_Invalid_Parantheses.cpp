// Topic: Backtracking
// Problem: (301) Remove Invalid Parentheses
//
// Pattern: Backtracking + Pruning
//
// My notes:
//
// Idea:
// First scan from left to right to find an invalid ')'
// When balance becomes negative, we have an extra ')'.
// Try removing each possible ')' in that invalid range.
//
// We skip consecutive ')' removals because removing either
// one gives the same result.
//
// Once the string has no invalid ')' from left to right,
// scan from right to left for invalid '('.
//
// When balance becomes negative in the reverse scan,
// we have an extra '('.
// Try removing each possible '('.
//
// Again, skip consecutive '(' removals.
//
// When both scans are valid, the current string is a valid answer.
//
// Why two passes?
// Forward pass removes extra ')'.
// Backward pass removes extra '('.
//
// Time: Exponential in the worst case O(n.2^p)
// Space: O(n) recursion depth + output

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;

        // Start by removing extra ')' from left to right
        forward(s, res, 0, 0);

        return res;
    }

private:

    // Remove extra ')' from the string
    //
    // li = starting index for scanning
    // lj = starting index from where we try removals
    void forward(string s, auto& res, int li, int lj) {
        int bal = 0;

        // Scan from left to right
        for (int i = li; i < s.length(); i++) {

            // '(' increases balance
            // ')' decreases balance
            bal += (s[i] == '(') - (s[i] == ')');

            // Balance is valid so far
            if (bal >= 0)
                continue;

            // Balance became negative
            // So we have an extra ')'
            for (int j = lj; j <= i; j++) {

                // Try removing this ')'
                //
                // Skip consecutive ')' because removing
                // any one of them gives the same result
                if (s[j] == ')' &&
                    (j == lj || s[j - 1] != ')')) {

                    // Remove s[j] and continue recursively
                    forward(
                        s.substr(0, j) + s.substr(j + 1),
                        res,
                        i,
                        j
                    );
                }
            }

            // We handled the first invalid ')'
            return;
        }

        // No extra ')' remains
        // Now check for extra '(' from right to left
        backward(s, res, s.length() - 1, s.length() - 1);
    }

    // Remove extra '(' from the string
    //
    // ri = starting index for reverse scanning
    // rj = starting index from where we try removals
    void backward(string s, auto& res, int ri, int rj) {
        int bal = 0;

        // Scan from right to left
        for (int i = ri; i >= 0; i--) {

            // ')' increases balance
            // '(' decreases balance
            bal += (s[i] == ')') - (s[i] == '(');

            // Balance is valid so far
            if (bal >= 0)
                continue;

            // Balance became negative
            // So we have an extra '('
            for (int j = rj; j >= i; j--) {

                // Try removing this '('
                //
                // Skip consecutive '(' because removing
                // any one of them gives the same result
                if (s[j] == '(' &&
                    (j == rj || s[j + 1] != '(')) {

                    // Remove s[j] and continue recursively
                    backward(
                        s.substr(0, j) + s.substr(j + 1),
                        res,
                        i - 1,
                        j - 1
                    );
                }
            }

            // We handled the first invalid '('
            return;
        }

        // No extra '(' remains
        // Therefore the string is valid
        res.push_back(s);
    }
};
