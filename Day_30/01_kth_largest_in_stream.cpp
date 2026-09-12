// Day 30 — Heaps
// Problem: Kth Largest in Stream
//
// My notes:
// Pattern: Min-Heap / Top K Elements
// Idea: Keep only the k largest elements in a min-heap.
//       If the heap size becomes greater than k, remove the smallest element.
//       Therefore, the smallest element among the k largest elements is the kth largest.
//       add() follows the same process and returns minHeap.top().
// Time: O(n log k) for initialization, O(log k) for each add()
// Space: O(k)


class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n: nums){
            minHeap.push(n);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

