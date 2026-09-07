// Topic: Dynamic Programming
// Problem: (940) Distinct Subsequences II
//
// Pattern: DP + Last Occurrence
// Idea: For every character, append it to all existing distinct
//       subsequences to create new subsequences.
//       If the character appeared before, some of the new
//       subsequences are duplicates.
//       Store the number of subsequences that existed before
//       the previous occurrence of each character and subtract it.
//
//       total = total + total - dp[c]
//             = 2 * total - dp[c]
//
//       dp[c] stores the value of total before the previous
//       occurrence of character c.
//
// Base Case:
//       total = 1 → empty subsequence
//
// Answer:
//       total - 1 → remove the empty subsequence
//
// Time: O(n)
// Space: O(26) = O(1)

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(26, 0);
        long long total = 1; // Empty subsequence
        for (char c : s) {
            int x = c - 'a';
            long long newSubseq = total; // Add current character to all existing subsequences
            total = (total + newSubseq - dp[x] + MOD) % MOD; // Remove duplicates from previous occurrence
            dp[x] = newSubseq; // Store contribution of current character
        }
        return (total - 1 + MOD) % MOD; // Remove empty subsequence
    }
};
