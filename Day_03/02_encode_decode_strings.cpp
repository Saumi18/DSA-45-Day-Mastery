// Day 03 — Arrays Deep
// Problem: Encode/Decode Strings
//
// My notes:
// Encode each string as: length + "#" + string.
// Decode by reading the length, skipping '#', then taking exactly n characters.
// stoi("5") converts string → int; manually: n = n*10 + (s[i]-'0').
// Mistakes: using only '#' as separator fails if '#' exists inside a string.
//          Confusing n (number of characters) with an index.
//          Changing i inside a for-loop can easily cause out-of-bounds errors.
// Important: i = current position, n = number of characters to read, j = count of characters read.
//
// Pattern: Length Encoding + Two-Pointer/String Traversal
// Time: O(n) — total characters processed once
// Space: O(n) — encoded/decoded output


class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for(int i=0;i<strs.size();i++){
            res += to_string(strs[i].size()) + "#" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> fin;
        int i = 0;
        while(i<s.size()){
            string len = "";
            int n=0;
            while(s[i]!='#'){
                n = n * 10 + (s[i] - '0'); // instead of doing stoi(len) we can do this if stoi isnt allowed
                i++;
            }
            i++;
            string word = "";
            for(int j=0;j<n;j++){
                word += s[i];
                i++;
            }
            fin.push_back(word);
        }
        return fin;
    }
};

