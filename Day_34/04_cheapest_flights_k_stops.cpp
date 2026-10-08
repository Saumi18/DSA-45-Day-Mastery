// Day 34 — Union Find + Dijkstra
// Problem: Cheapest Flights K Stops
//
// My notes:
// Pattern: Bellman-Ford / Shortest Path with K Stops
//
// Idea:
// Find the cheapest price from src to dst using at most k stops.
// Relax all flights k + 1 times.
// Use a temporary array so each iteration adds only one flight.
//
// Time: O(K * E)
// Space: O(V)

// Easy Solution
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(int i = 0; i <= k; i++){
            vector<int> temp = dist;

            for(auto& flight : flights){
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if(dist[u] != INT_MAX){
                    temp[v] = min(temp[v], dist[u] + price);
                }
            }

            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};


// Optimized Solution
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto& f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, src, 0});

        vector<int> stops(n, INT_MAX);

        while(!pq.empty()){
            auto [cost, node, stop] = pq.top();
            pq.pop();

            if(node == dst) return cost;
            if(stop > k) continue;
            if(stop >= stops[node]) continue;

            stops[node] = stop;

            for(auto [nei, price] : adj[node]){
                pq.push({cost + price, nei, stop + 1});
            }
        }

        return -1;
    }
};
