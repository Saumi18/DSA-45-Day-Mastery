// Day 10 — Intervals
// Problem: Minimum Interval to Include Each Query
//
// My notes:
// Pattern: Sort + Two Pointers + Min Heap
// Time: O((n + q) log n)
// Space: O(n + q)
//
// Key idea:
// Sort queries and intervals.
// For each query:
// 1. Add intervals with start <= query.
// 2. Remove intervals with end < query.
// 3. Min heap top = smallest valid interval.
//
// Heap stores: {interval length, interval end}
// length → find smallest interval
// end → remove expired intervals
//
// Since queries are sorted, each interval is added once
// and removed at most once.
//
// Important:
// Store {query, original_index} because sorting queries
// changes their original order.


class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // ans[i] = answer for queries[i]
        // Keep original size because queries will be sorted later
        vector<int> ans(queries.size(), 0);
        // Store {query value, original index}
        // This lets us sort queries but return answers in original order
        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        // Sort queries by value and intervals by start
        sort(q.begin(), q.end());
        sort(intervals.begin(), intervals.end());
        int i = 0; // pointer for intervals
        int j = 0; // pointer for queries
        // Min heap stores {interval length, interval end}
        // Smallest interval length stays at the top
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> minHeap;

        while(j < q.size()) {
            // Add every interval that has started by this query
            // start <= query means the interval MAY contain the query
            while(i < intervals.size() && intervals[i][0] <= q[j].first) {
                int length = intervals[i][1] - intervals[i][0] + 1;

                // Store {length, end}
                // length -> used to find smallest interval
                // end    -> used to remove expired intervals
                minHeap.push({length, intervals[i][1]});
                i++;
            }
            // Remove intervals that have already ended
            // end < query means the interval CANNOT contain the query
            while(!minHeap.empty() && minHeap.top().second < q[j].first) {
                minHeap.pop();
            }
            // Heap top is now the smallest valid interval
            // Store answer at the query's ORIGINAL index
            if(minHeap.empty()) {
                ans[q[j].second] = -1;
            }
            else {
                ans[q[j].second] = minHeap.top().first;
            }
            j++;
        }
        return ans;
    }
};
