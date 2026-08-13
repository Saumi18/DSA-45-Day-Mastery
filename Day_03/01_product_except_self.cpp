// Day 03 — Arrays Deep
// Problem: Product Except Self
//
// My notes:
// Pattern: prefix & suffix sum/prod or prestoring the product/sum
// Time: o(n)
// Space: o(n) + O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int product = 1;
        int zeroCnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeroCnt++;
            if(nums[i]!=0) product *= nums[i];
        }
        if(zeroCnt>1) return vector<int> (nums.size(),0);

        for(int i=0;i<nums.size();i++){
            if(zeroCnt>0){
                if(nums[i]==0){
                    result[i] = product;
                }
                else result[i] = 0;
            }
            else{
                result[i] = product/nums[i];
            }
        }
        return result;
    }
};

// Below is using prefix and suffix product so we bypass division and also whole product doesnt exceed limit

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> result(n, 1);

    // Prefix product
    int prefix = 1;
    for(int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Suffix product
    int suffix = 1;
    for(int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
    }
};
