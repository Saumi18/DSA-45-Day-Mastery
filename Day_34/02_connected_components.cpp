// Day 34 — Union Find + Dijkstra
// Problem: Connected Components
//
// My notes:
// Pattern: DSU / Union Find
//
// Idea:
// Initially every node is a separate component.
// find(x) gives the root of x's component.
// For every edge, find the roots of both nodes.
// If roots are different, merge the components and decrease cnt.
// If roots are same, they are already connected.
//
// Time: O(E log V)
// Space: O(V)

class Solution {
    vector<int> parent;

    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = n;
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        for(auto& edge: edges){
            int a = find(edge[0]);
            int b = find(edge[1]);
            if(a == b) continue;
            parent[b] = a;
            cnt--;
        }
        return cnt;
    }
};

