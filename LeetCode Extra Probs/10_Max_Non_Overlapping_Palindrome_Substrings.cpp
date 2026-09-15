// TOPIC: Dynamic Programming / Strings
// Problem: (2472)Maximum Number of Non-Overlapping Palindrome Substrings
//
// Pattern: Palindrome DP + 1D DP
// Idea: First determine whether every substring is a palindrome using 2D DP.
//       p[i][j] is true if s[i...j] is a palindrome.
//       Then use dp[i] to store the maximum number of non-overlapping
//       palindromes that can be selected from index i onwards.
//       At every index, either skip s[i] or take a valid palindrome s[i...j].
//       If we take s[i...j], the next available position is j+1.
//
// Palindrome condition:
//       s[i] == s[j] and the inside substring is also a palindrome.
//       A substring of length 1 or 2 is handled by j-i < 2.
//
// DP:
//       dp[i] = maximum palindromes possible from s[i...n-1]
//       Skip current index → dp[i+1]
//       Take palindrome [i...j] → 1 + dp[j+1]
//
// Time: O(n²)
// Space: O(n²)
//
// Key Pattern:
// 2D DP → identify valid palindromes
// 1D DP → choose maximum non-overlapping palindromes
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> p(n,vector<bool>(n));
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1];
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<2 || p[i+1][j-1])){
                    p[i][j]=1;
                    if(j-i+1 >= k) dp[i] = max(dp[i],1+dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};
