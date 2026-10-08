// Day 34 — Union Find + Dijkstra
// Problem: Graph Valid Tree
//
// My notes:
// Pattern: DSU / Union Find
//
// Idea:
// A valid tree must be connected and have no cycle.
// Initially every node is a separate component.
// For every edge, find the roots of both nodes.
// If roots are same, adding the edge creates a cycle.
// Otherwise merge the two components.
// At the end, there must be exactly one component.
//
// Time: O(E log V)
// Space: O(V)

class Solution {
    vector<int> parent;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto& edge : edges){
            int a = find(edge[0]);
            int b = find(edge[1]);

            if(a == b) return false;

            parent[b] = a;
        }

        return true;
    }
};
