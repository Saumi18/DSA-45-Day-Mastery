// Day 34 — Union Find + Dijkstra
// Problem: Network Delay Time
//
// My notes:
// Pattern: Dijkstra + Min Heap
//
// Idea:
// Start from node k and find the shortest time to reach every node.
// Use a min heap to always process the node with the smallest distance.
// If we find a shorter path to a neighbor, update its distance.
//
// After Dijkstra, the answer is the maximum shortest distance,
// because the signal must reach every node.
// If any node is unreachable, return -1.
//
// Time: O(E log V)
// Space: O(V + E)


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto& t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto [nei, wt] : adj[node]){
                if(d + wt < dist[nei]){
                    dist[nei] = d + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
