// Topic: Greedy + Backtracking
// Problem: (3720)Lexicographically Smallest Permutation Greater Than Target
//
// My notes:
// Pattern: Frequency Array → Greedy Matching → Backtrack
// Idea: Match target as long as possible. If we can't continue,
//       choose the smallest greater character; otherwise backtrack
//       to an earlier position and increase it.
// Time: O(n * 26)
// Space: O(n)

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Store frequency of each character
        int freq[26] = {};
        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // If target character is available, keep the prefix equal
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            } 
            else {
                // Try to make the current position greater
                for (int c = x + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string result = ans;
                        result += char('a' + c);
                        freq[c]--;

                        // Fill remaining positions with smallest characters
                        for (int k = 0; k < 26; k++)
                            while (freq[k] > 0) {
                                result += char('a' + k);
                                freq[k]--;
                            }

                        return result;
                    }
                }

                // Current position cannot be increased, so backtrack
                for (int j = i - 1; j >= 0; j--) {
                    // Restore the character used at position j
                    freq[ans[j] - 'a']++;

                    // Try to increase this position
                    for (int c = target[j] - 'a' + 1; c < 26; c++) {
                        if (freq[c] > 0) {
                            string result = ans.substr(0, j);
                            result += char('a' + c);
                            freq[c]--;

                            // Fill the remaining positions minimally
                            for (int k = 0; k < 26; k++)
                                while (freq[k] > 0) {
                                    result += char('a' + k);
                                    freq[k]--;
                                }

                            return result;
                        }
                    }

                    // Remove the current character and try earlier position
                    ans.pop_back();
                }

                return "";
            }
        }

        // Entire target was matched, so we need to make it greater
        for (int j = n - 1; j >= 0; j--) {
            // Restore character at position j
            freq[ans[j] - 'a']++;

            // Try the smallest character greater than target[j]
            for (int c = target[j] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string result = ans.substr(0, j);
                    result += char('a' + c);
                    freq[c]--;

                    // Fill remaining positions with smallest characters
                    for (int k = 0; k < 26; k++)
                        while (freq[k] > 0) {
                            result += char('a' + k);
                            freq[k]--;
                        }

                    return result;
                }
            }
            // Try an earlier position
            ans.pop_back();
        }
        // No permutation is greater than target
        return "";
    }
};
