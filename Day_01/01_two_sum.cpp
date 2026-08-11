// Day 01 — Arrays
// Problem: Two Sum
//
// My notes: Two pointer works when array is sorted and hence O(nlogn) T.C., Dont sort the array directly or duplicate array 
//           Also when you sort array make array of pairs of value and index to keep track of index and not to loose the actual index
// Pattern: Hash Map
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> subMap;
        for(int i=0;i<n;i++){
            int diff = target - nums[i];
            if(subMap.count(diff)){
                return {subMap[diff], i}; // subMap[diff] gives 2nd part of map which is the index
            }
            subMap.insert({nums[i],i});
        }
        return {};
    }
};


// TWO PTR + SORTING SOLUTION:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) {
                return {arr[left].second, arr[right].second};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return {};
    }
};

