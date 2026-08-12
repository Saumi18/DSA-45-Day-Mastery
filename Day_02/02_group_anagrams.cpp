// Day 02 — Arrays + Hashing
// Problem: Group Anagrams

// My notes:
// Pattern: Group anagrams using a common key.
// Method 1: Sort each word → anagrams get the same sorted key.
// Method 2: Count 26 characters → anagrams get the same frequency key.
// Time: O(n*k) with counting, O(n*k log k) with sorting
// Space: O(n*k)


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> result;
        
        for(int i=0;i<strs.size();i++){
            vector<int> count(26,0);
            for(int j=0;j<strs[i].length();j++){
                count[strs[i][j]-'a']++;
            }
            string key ="";
            for(int i=0;i<26;i++){
                key += to_string(count[i]) + ",";
                // adding a delimiter is required like "," as if there are 1 b and 10 d the "01010.." and 10 b and 1 c then "01010.." these keys become same but arent so delimiter gives "0,1,0,10,..." and "0,10,1,0,..." so different
            }
            mp[key].push_back(strs[i]);
            //we cant use mp[key] = strs[i] as it will overwrite instead of taking all
        }
        for(auto& pair : mp){
            result.push_back(pair.second);
        }
        return result;
    }
};
