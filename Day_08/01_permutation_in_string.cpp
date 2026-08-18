// Day 08 — Sliding Window (cont.)
// Problem: Permutation in String
//
// My notes:
// Pattern: Fixed-size sliding window + frequency array
// Key idea: Maintain character frequencies instead of recounting every window.
// When window moves: remove the left character, add the new right character.
// Edge case: If s1 is larger than s2, return false.
// Time: O(n) — comparing 26 characters is O(1)
// Space: O(1) — only two arrays of size 26

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // s1 cannot fit inside s2
        if(s1.size() > s2.size()) return false;
        int k = s1.size();
        int l = 0;
        int r = k - 1;
        // Frequency of characters in s1
        vector<int> check1(26, 0);
        // Frequency of characters in current s2 window
        vector<int> check2(26, 0);
        for(int i = 0; i < k; i++){
            check1[s1[i] - 'a']++;
        }
        // Initialize the first window of size k
        for(int j = 0; j < k; j++){
            check2[s2[j] - 'a']++;
        }

        while(r < s2.size()){
            // Same frequency => current window is a permutation
            if(check1 == check2){
                return true;
            }
            // Slide window by 1
            l++;
            r++;
            // Remove character that left the window
            check2[s2[l - 1] - 'a']--;
            // Add new character entering the window
            if(r < s2.size()){
                check2[s2[r] - 'a']++;
            }
        }

        return false;
    }
};
