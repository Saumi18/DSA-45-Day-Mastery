// Day 09 — Prefix + Intervals
// Problem: Meeting Rooms II
//
// My notes:
// Pattern: Sweep Line / Two Pointers
// Idea: Sort starts and ends separately.
// start < end → new room needed
// start >= end → room is free → reuse it
// count = maximum rooms used at once
// Time: O(n log n)
// Space: O(n)
//
// Min-Heap:
// Sort by start; heap stores end times of active meetings.
// heap.top() = earliest room that becomes free.
// start >= heap.top() → reuse room; else new room.
// Time: O(n log n), Space: O(n)

class Solution {
public:
    // Two-Pointer / Sweep Line
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int rooms=0,count=0;
        vector<int> startInt,endInt;
        for(int i=0;i<intervals.size();i++){
            startInt.push_back(intervals[i].start);
            endInt.push_back(intervals[i].end);
        }
        sort(startInt.begin(),startInt.end());
        sort(endInt.begin(),endInt.end());
        int l=0,r=0;
        while(l<startInt.size() && r<endInt.size()){
            // Meeting starts before any room becomes free
            if(startInt[l]<endInt[r]){
                rooms++;
                l++;
                count=max(count,rooms);
            }
            // A room becomes free before/at the next start
            else{
                rooms--;
                r++;
            }
        }
        return count;
    }
};

// Min-Heap version
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b){
            return a.start<b.start;
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &interval:intervals){
            // Earliest room is free → reuse it
            if(!pq.empty() && interval.start>=pq.top())
                pq.pop();
            // Store current meeting's end time
            pq.push(interval.end);
        }
        return pq.size();
    }
};
