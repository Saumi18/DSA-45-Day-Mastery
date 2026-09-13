// Day 30 — Heaps
// Problem: Task Scheduler
//
// My notes:
// Approach 1: Max-Heap + Cooldown Queue
// Pattern: Max-Heap + Queue / Greedy
// Idea: Count the frequency of each task and put the frequencies in a max-heap.
//       Always execute the task with the highest remaining frequency.
//       After execution, put it into a cooldown queue with the time when it becomes available.
//       Once the cooldown expires, push it back into the max-heap.
// Time: O(n)
// Space: O(1)
//       Only 26 different task types are possible.
//
// Approach 2: Greedy Formula
// Pattern: Greedy / Frequency Counting
// Idea: The most frequent task creates the minimum required schedule length.
//       Arrange the most frequent task with n idle positions between occurrences.
//       Formula = max(total tasks, (maxFreq - 1) * (n + 1) + countMaxFreq)
// Time: O(n)
// Space: O(1)


// Approach 1: Max-Heap + Cooldown Queue

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task : tasks){
            freq[task - 'A']++;
        }
        priority_queue<int> maxHeap;

        for(int f : freq){
            if(f > 0){
                maxHeap.push(f);
            }
        }

        queue<pair<int,int>> q;
        int time = 0;
        while(!maxHeap.empty() || !q.empty()){
            time++;
            if(!maxHeap.empty()){
                int f = maxHeap.top();
                maxHeap.pop();
                f--;
                if(f > 0){
                    q.push({f, time + n});
                }
            }
            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};


// Approach 2: Greedy Formula
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task : tasks){
            freq[task - 'A']++;
        }
        
        int maxFreq = 0;
        int countMaxFreq = 0;
        for(int f : freq){
            maxFreq = max(maxFreq, f);
        }
        
        for(int f : freq){
            if(f == maxFreq){
                countMaxFreq++;
            }
        }
        return max( (int)tasks.size(), (maxFreq - 1) * (n + 1) + countMaxFreq );
    }
};
