// Day 41 — DP 1D (cont.)
// Problem: Word Break
//
// My notes:
// Pattern: 1D DP on suffixes
// dp[i] = true if s[i...end] can be split into dictionary words.
// Base case: dp[s.size()] = true (the empty suffix is already complete).
// Work backward from the end. For each i, try each dictionary word w.
// If w matches s starting at i, then dp[i] = dp[i + w.size()].
// Stop checking words once dp[i] becomes true.
// Return dp[0].
//
// Time: O(n * D * L) worst case
//       n = s.size(), D = wordDict.size(), L = maximum word length.
//       Comparing s.substr(i, w.size()) with w can take O(L).
// Space: O(n) for dp (plus a temporary substring of up to O(L)).


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (const auto& w : wordDict) {
                if ((i + w.size()) <= s.size() &&
                     s.substr(i, w.size()) == w) {
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
    }
};
