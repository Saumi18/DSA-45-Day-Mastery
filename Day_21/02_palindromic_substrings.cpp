// Day 21 — Strings
// Problem: Palindromic Substrings
//
// My notes:
// Pattern: Expand Around Center
// Idea: Every palindrome has a center. For each index, expand outward for
// both odd (i,i) and even (i,i+1) centers. Every successful expansion
// represents one palindromic substring, so increment count.
// Time: O(n²)
// Space: O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};

// MANACHER's Algorithm

// Idea: Transform the string to handle odd and even length palindromes
// uniformly. p[i] stores the palindrome radius at each center. Use the
// mirror of i within the current rightmost palindrome to avoid repeated work.
// Every radius contributes exactly that many palindromic substrings.
// So, add (p[i]+1)/2 to the answer for every center as p[i] will have radius with "#" char also.
// So, DONT directly add p[i]
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int countSubstrings(string s) {
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0;
        int right = 0;
        int ans = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            if (i < right){
                p[i] = min(right - i, p[mirror]);
            }
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]){
                p[i]++;
            }
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
            ans += (p[i]+1)/2;
        }
        return ans;
    }
};
