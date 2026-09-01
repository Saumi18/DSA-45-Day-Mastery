// Day 21 — Strings
// Problem: Find All Anagrams in a String
//
// My notes:
// Pattern: Fixed-Size Sliding Window + Frequency Array
// Idea: Store the required frequency of each character in p. Maintain a
// window of the same size in s and store its character frequencies. Compare
// both frequency arrays; if they match, the current window is an anagram.
// Slide the window by removing the left character and adding the next character.
// Time: O(n)
// Space: O(1)


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return {};
        vector<int> req(26,0);
        vector<int> act(26,0);
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            req[p[i]-'a']++;
        }
        int l=0,r=p.size()-1;
        for(int i=l;i<r+1;i++){
                act[s[i]-'a']++;
        }
        while(r<s.size()-1){
            if(req==act) ans.push_back(l);
            act[s[l]-'a']--;
            l++;
            r++;
            act[s[r]-'a']++;
        }
        if(req == act) ans.push_back(l);
        return ans;
    }
};
