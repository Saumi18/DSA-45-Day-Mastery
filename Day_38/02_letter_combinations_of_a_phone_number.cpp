// Day 38 — Backtracking Adv.
// Problem: Letter Combinations of a Phone Number
//
// My notes:
// Pattern: Backtracking + DFS
// Time: O(4^n * n), where n is the number of digits
// Space: O(n) auxiliary space, excluding output
//
// Approach:
// 1. Map each digit from 2 to 9 to its corresponding letters.
// 2. Start from index 0 with an empty string curStr.
// 3. Get all letters mapped to the current digit.
// 4. Try each letter by adding it to curStr and recursively process the next digit.
// 5. When curStr length equals digits length, add it to the result.
// 6. Explore all possible letter combinations using backtracking.
//
// Key points:
// - i represents the current digit's index.
// - curStr stores the combination being built.
// - digits[i] - '0' converts a character digit into an integer.
// - Each recursive call moves to the next digit using i + 1.
// - No pop_back() is needed because curStr is passed by value.
// - If digits is empty, return an empty result.
//
// Example:
// Input: "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
// Complexity:
// - Time: O(4^n * n), since each digit has at most 4 letters
//   and each combination takes O(n) to construct/store.
// - Space: O(n) for the recursion depth and current strings,
//   excluding the output.


class Solution {
private:
    vector<string> res;
    vector<string> digToChar = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        backtrack(0,"",digits);
        return res;
    }

    void backtrack(int i, string curStr, string& digits){
        if(curStr.size() == digits.size()){
            res.push_back(curStr);
            return;
        }
        string chars = digToChar[digits[i]-'0'];
        for(char c:chars){
            backtrack(i+1,curStr+c,digits);
        }
    }
};

