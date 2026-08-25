// Day 15 — Binary Search (cont.)
// Problem: Time-Based Key-Value Store
//
// My notes:
// Pattern: Binary Search on sorted timestamps
// Time: set() O(1), get() O(log n)
// Space: O(n)
//
// Key Idea:
// For each key, store {value, timestamp} pairs.
// Timestamps are strictly increasing, so we can binary search.
//
// For get(key, timestamp), find the value corresponding to the
// largest timestamp <= the given timestamp.
//
// Binary Search:
// - If v[mid].timestamp <= timestamp:
//      Valid answer → store it and search right for a better answer.
// - If v[mid].timestamp > timestamp:
//      Search left.
//
// Why search right after finding a valid answer?
// We need the LARGEST timestamp <= target, not just any valid timestamp.
//
// Edge Cases:
// - Key doesn't exist → return ""
// - No timestamp <= target → return ""

class TimeMap {
public:
    // key -> {value, timestamp}
    unordered_map<string, vector<pair<string, int>>> mp;

    TimeMap() {} // initialise constructor
    void set(string key, string value, int timestamp) {
        // Timestamps are increasing, so append directly.
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";

        vector<pair<string, int>>& v = mp[key];

        int l = 0;
        int r = v.size() - 1;
        string res = "";

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(v[mid].second <= timestamp) {
                // Valid timestamp.
                // Search right for a larger valid timestamp.
                res = v[mid].first;
                l = mid + 1;
            }
            else {
                // Timestamp is too large.
                r = mid - 1;
            }
        }
        return res;
    }
};
