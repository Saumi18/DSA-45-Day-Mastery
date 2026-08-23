// Topic — String
// Problem: (28) Find the Index of the First Occurrence in a String 
//
// My notes:
// Pattern: KMP String Matching
// Logic: Match needle with haystack using two pointers
// LPS tells how much of the matched pattern can be reused after mismatch
// Instead of moving i back, move j using LPS and avoid rechecking characters
// LPS = Longest Proper Prefix which is also a Suffix
// Time: O(m+n) because each character is processed a constant number of times
// Space: O(m) for the LPS array

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m,0);
        int len = 0;
        // Build LPS array for the pattern
        for(int i=1;i<m;i++){
            while(len>0 && needle[i]!=needle[len])
                len=lps[len-1];
            if(needle[i]==needle[len])
                len++;
            lps[i]=len;
        }
        int i=0,j=0;
        // Search needle inside haystack
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==m)
                    return i-m;
            }
            else if(j>0){
                // Reuse the matched prefix instead of restarting
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        return -1;
    }
};


// Brute Force O(mn)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0;i<=n-m;i++){
            int j=0;
            while(j<m && haystack[i+j]==needle[j])
                j++;
            if(j==m)
                return i;
        }
        return -1;
    }
};
