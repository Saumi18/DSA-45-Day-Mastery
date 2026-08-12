// Day 02 — Arrays + Hashing
// Problem: Top K Frequent
//
// My notes:
// Pattern: HashMap to count frequency + Bucket Sort.
// bucket[freq] stores all numbers appearing 'freq' times.
// vector<vector<int>> is used because one frequency can have multiple numbers.
// Traverse buckets from highest frequency to lowest and take k elements.
// Time: O(n)
// Space: O(n)


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for (auto& p : mp) {
            int number = p.first;
            int frequency = p.second;

            bucket[frequency].push_back(number);
        }
        for (int freq = nums.size(); freq >= 1; freq--) {
            for (int i = 0; i < bucket[freq].size(); i++) {
                result.push_back(bucket[freq][i]);
                if (result.size() == k) return result;
                }
            }
            return result;
        }
};

