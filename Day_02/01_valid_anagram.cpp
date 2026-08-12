// Day 02 — Arrays + Hashing
// Problem: Valid Anagram
//
// My notes: This solution is only valid for strings whose case sensitivity is same like lowercase or uppercase but if mixed first convert to one of these
// Pattern: string can be stored in new temp string and then sorted and compared but this takes TC O(nlogn) and SC O(n)
// Time: O(n+m)
// Space: O(1) as only 26 alphabets so 26 elements mapping


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        string s_new = s;
        string t_new = t;
        sort(s_new.begin(),s_new.end());
        sort(t_new.begin(),t_new.end());
        return s_new == t_new;
    }
};

// Hash Map solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mapS,mapT;
        for(int i=0;i<s.length();++i){
            mapS[s[i]]++;
        }
        for(int i=0;i<t.length();++i){
            mapT[t[i]]++;
        }
        return mapT == mapS;
    }
};

