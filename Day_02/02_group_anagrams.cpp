// Day 02 — Arrays + Hashing
// Problem: Group Anagrams

// My notes:
// Pattern: Group anagrams using a common key.
// Method 1: Sort each word → anagrams get the same sorted key.
// Method 2: Count 26 characters → anagrams get the same frequency key.
// Time: O(n*k) with counting, O(n*k log k) with sorting
// Space: O(n*k)

/*
===========================================================
GROUP ANAGRAMS — TWO WAYS TO CREATE THE MAP KEY
===========================================================

1. vector<int> AS KEY
---------------------

We create a 26-size frequency vector:

"eat" -> [1,0,0,0,1,0,...,1,...]
"tea" -> [1,0,0,0,1,0,...,1,...]

So anagrams have the same vector.

We can use:

unordered_map<vector<int>, vector<string>, VectorHash>

BUT unordered_map needs a HASH FUNCTION to quickly find
the key. C++ does not provide a default hash for vector<int>,
so we create our own VectorHash.

This gives average O(1) map lookup.


2. string AS KEY
----------------

We can convert the frequency vector into a string:

[1,0,0,1,...] -> "1#0#0#1#..."

Then use:

unordered_map<string, vector<string>>

String already has a built-in hash function in C++, so
NO custom hash function is required.

This is usually the simpler approach.


3. WHY NOT map<vector<int>, ...>?
---------------------------------

We CAN use map:

map<vector<int>, vector<string>> mp;

It works because map does not need hashing. It compares
keys to find the required key.

However, map is usually implemented using a balanced
binary search tree (Red-Black Tree).

Therefore lookup/insertion takes:

map           -> O(log n)
unordered_map -> O(1) average

So unordered_map is generally preferred when we don't need
the keys to be sorted.

FINAL CHOICE:

vector<int> + custom hash
    -> O(1) average
    -> More direct representation
    -> Requires custom hash

string + unordered_map
    -> O(1) average
    -> Simpler because string is already hashable
    -> Very commonly used for this problem

map + vector<int>
    -> O(log n)
    -> No custom hash needed
    -> Still completely valid
===========================================================
*/


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

class Solution {
public:

    // Custom hash because C++ does not provide a default hash
    // function for vector<int>.
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;

            for(int x : v) {
                hash = hash * 31 + x;
            }

            return hash;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<vector<int>, vector<string>, VectorHash> mp;
        vector<vector<string>> result;

        for(int i = 0; i < strs.size(); i++) {

            vector<int> count(26, 0);

            for(int j = 0; j < strs[i].length(); j++) {
                count[strs[i][j] - 'a']++;
            }

            // Frequency vector is the key.
            // All anagrams have the same frequency vector.
            mp[count].push_back(strs[i]);
        }

        for(auto& p : mp) {
            result.push_back(p.second);
        }

        return result;
    }
};
