// Day 34 — Union Find + Dijkstra
// Problem: Redundant Connection
//
// My notes:
// Pattern: DSU / Union Find
//
// Idea:
// Maintain connected components using DSU.
// `find(x)` gives the root of x's component.
// `unite(a,b)` merges two different components.
// If two nodes already have the same root,
// adding their edge creates a cycle.
// Return the first edge that connects nodes
// already belonging to the same component.
//
// Time: O(E α(V)) ≈ O(E)
// Space: O(V)

//THIS CAN BE SOLVED WITHOUT THE "UNITE AND RANK" part
// then without RANK it will be O(E logV)
class Solution {
    vector<int> parent;
    vector<int> rank;
public:
    int find(int x) {
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(auto& edge : edges){
            if(!unite(edge[0], edge[1])){
                return edge;
            }
        }
        return {};
    }
};
