// Day 30 — Heaps
// Problem: Last Stone Weight
//
// Approach 1:
// Pattern: Max-Heap
// Idea: Keep all stones in a max-heap so the two heaviest stones are always available.
//       Remove the two largest stones. If they differ, push their difference back.
// Time: O(n log n)
// Space: O(n)
//
// Approach 2:
// Pattern: Frequency Array / Bucket
// Idea: Store frequencies of each stone weight.
//       Start from the largest weight and find the next largest available stone.
//       Equal stones cancel in pairs; otherwise, insert their difference back.
// Time: O(n + W), where W = maximum stone weight
// Space: O(W)


// 1. MaxHeap solution
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone : stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if(x != y){
                maxHeap.push(x - y);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

// 2. Bucket Sort
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxStone = 0;
        for(int stone : stones){
            maxStone = max(maxStone, stone);
        }

        vector<int> bucket(maxStone + 1, 0);
        for(int stone : stones){
            bucket[stone]++;
        }

        int first = maxStone;
        int second = maxStone;

        while(first > 0){
            if(bucket[first] % 2 == 0){
                first--;
                continue;
            }
            int j = min(first - 1, second);

            while(j > 0 && bucket[j] == 0){
                j--;
            }
            if(j == 0){
                return first;
            }

            second = j;
            bucket[first]--;
            bucket[second]--;
            bucket[first - second]++;
            first = max(first - second, second);
        }
        return first;
    }
};
