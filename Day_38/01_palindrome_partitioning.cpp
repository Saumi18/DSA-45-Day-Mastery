// Day 38 — Backtracking Adv.
// Problem: Palindrome Partitioning
//
// My notes:
// Pattern: Backtracking + DFS + String
// Time: O(n * 2^n)
// Space: O(n) auxiliary space, excluding output
//
// Approach:
// 1. Start at index i and try every possible ending index j.
// 2. Check whether substring s[i...j] is a palindrome.
// 3. If palindrome, add it to the current partition.
// 4. Recursively partition the remaining string from j + 1.
// 5. Remove the substring using pop_back() to explore other partitions.
//
// Key points:
// - Every substring s[i...j] is a potential partition.
// - Only palindrome substrings are added to the current partition.
// - j + 1 moves to the first character after the chosen substring.
// - i >= s.length() means the entire string is partitioned.
// - pop_back() undoes the last choice during backtracking.
// - isPali() checks a substring using two pointers.
// - Every character must belong to exactly one substring.
//
// Example:
// Input: "aab"
// Output: [["a","a","b"],["aa","b"]]
//
// Complexity:
// - Time: O(n * 2^n), including palindrome checks.
// - Auxiliary space: O(n) for recursion and current partition,
//   excluding output.


class Solution {
private:
    void backtrack(int i, const string& s, vector<string>& part, vector<vector<string>>& res){
        if(i >= s.length()){
            res.push_back(part);
            return;
        }

        for(int j=i;j<s.length();j++){
            if(isPali(s,i,j)){
                part.push_back(s.substr(i,j-i+1));
                backtrack(j+1,s,part,res);
                part.pop_back();
            }
        }
    }

    bool isPali(const string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> part;
        vector<vector<string>> res;
        backtrack(0,s,part,res);
        return res;
    }
};

