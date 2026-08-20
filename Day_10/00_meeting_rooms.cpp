// Day 09 — Prefix + Intervals
// Problem: Meeting Rooms
//
// My notes:
// Pattern: Sort + Adjacent Interval Check
// Why sort? Put meetings in chronological order so we only compare neighbors.
// Overlap if: previous.end > current.start → return false.
//
// Sorting:
// vector<vector<int>> → default sort works (lexicographically by [0], then [1])
// vector<Interval> → custom comparator needed because Interval is a custom class.
// Comparator: sort by start time → a.start < b.start
//
// Time: O(n log n) → sorting
// Space: O(1) extra (excluding sorting internals)

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // Sort custom Interval objects by start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        
        // Check adjacent meetings for overlap
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i-1].end > intervals[i].start)
                return false;
        }
        return true;
    }
};
