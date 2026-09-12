// Day 30 — Heaps
// Problem: Kth Largest Element in an Array
//
// My notes:
// Approach 1: Min-Heap
// Pattern: Top K / Kth Largest
// Idea: Keep only the k largest elements in a min-heap.
//       If heap size becomes greater than k, remove the smallest element.
//       The smallest element among the k largest elements is the kth largest.
// Time: O(n log k)
// Space: O(k)
//
// Approach 2: Quickselect
// Pattern: Quickselect / Partition
// Idea: Convert kth largest into index n - k.
//       Partition the array around a pivot.
//       After partitioning, the pivot is in its correct sorted position.
//       If pivot index == n - k, return it.
//       Otherwise, search only the left or right part.
// Time: O(n) average, O(n²) worst case
// Space: O(1)

//Approach 1: min heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int num: nums){
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

// Approach 2: Quickselect
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int pivot = nums[right];
            int i = left;

            for(int j = left; j < right; j++){
                if(nums[j] <= pivot){
                    swap(nums[i], nums[j]);
                    i++;
                }
            }

            swap(nums[i], nums[right]);
            if(i == target){
                return nums[i];
            }
            else if(i < target){
                left = i + 1;
            }
            else{
                right = i - 1;
            }
        }
        return -1;
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TODO: Implement Kth Largest in Array
};
