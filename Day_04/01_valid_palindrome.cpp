// Day 04 — Two Pointers
// Problem: Valid Palindrome
//
// My notes:
// Pattern: Two Pointers + skip non-alphanumeric characters + case normalization.
//          Simple approach: clean string first, then check palindrome.
//          Optimized: compare directly from both ends without creating temp.
//          isalnum() → checks letter/digit; tolower() → handles case.
//
// Time: O(n) for both approaches
// Space: O(n) simple approach; O(1) two-pointer approach

// This is a simple approach where extra O(n) space required for temp
class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0;i<s.size();i++){
            if((s[i]-'a' >=0 && s[i]-'a' < 26) || (s[i]-'A' >=0 && s[i]-'A' <26) || (s[i]-'0' >=0 && s[i]-'0' < 10)){
                temp += tolower(s[i]); // case sensitivity can be a problem
            }
        }
        int n = temp.size();
        for(int i=0;i<n;i++){
            if(temp[i] != temp[n-1-i]) return false;
        }
        return true;
    }
};

// Two pointer approach where no extra space for temp required

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() -1;
        // isalnum() is a function used to check whether the char is alphanumeric 
        while(l<r){
            while(l<r && !isalnum(s[l])){
                l++;
            }
            while(l<r && !isalnum(s[r])){
                r--;
            }
            if(tolower(s[l])!=tolower(s[r])) return false;
            
            l++;
            r--;
        }
        return true;
    }
};
