// Day 08 — Sliding Window (cont.)
// Problem: Minimum Window Substring
//
// My notes:
// Pattern: Variable-size sliding window + frequency maps
// Key idea: Expand r until the window contains all required characters,
//           then shrink l while the window remains valid.
// have = number of distinct characters whose required frequency is satisfied
// need = total number of distinct characters required by t
// When have == need → current window is valid.
// Time: O(n)
// Space: O(k) where k = number of distinct characters in t

class Solution {
public:
    string minWindow(string s, string t) {
        // If t is larger than s, or t is empty, no valid window exists
        if(t.size() > s.size() || t.empty()){
            return "";
        }
        string res = "";
        int minLen = INT_MAX;
        // requiredFreq → frequency required from t
        // windowFreq   → frequency currently present in window
        unordered_map<char,int> requiredFreq, windowFreq;
        // Store frequency of each character required by t
        for(int i = 0; i < t.size(); i++){
            requiredFreq[t[i]]++;
        }
        // have = number of distinct characters currently satisfied
        // need = total number of distinct characters required
        int have = 0, need = requiredFreq.size();
        // Stores indices of the best (minimum) window
        pair<int,int> ind;
        int l = 0;
        // r expands the window
        for(int r = 0; r < s.length(); r++){
            // Add current character to the window
            windowFreq[s[r]]++;
            // Requirement for this character is satisfied for the first time
            if(requiredFreq[s[r]] &&
               windowFreq[s[r]] == requiredFreq[s[r]]){
                have++;
            }
            // Window contains all required characters
            while(have == need){
                // Update minimum window
                if(r + 1 - l < minLen){
                    minLen = r + 1 - l;
                    ind = {l, r};
                }
                // Remove leftmost character while shrinking
                windowFreq[s[l]]--;
                // Removing this character broke a requirement
                if(requiredFreq[s[l]] &&
                   windowFreq[s[l]] < requiredFreq[s[l]]){
                    have--;
                }

                l++;
            }
        }
        // No valid window found
        if(minLen == INT_MAX)
            return "";
        // Construct the minimum window
        else{
            for(int i = ind.first; i < ind.second + 1; i++){
                res += s[i];
            }
            return res;
        }
    }
};
