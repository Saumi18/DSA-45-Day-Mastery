// Day 33 — Graphs Adv.
// Problem: Course Schedule II
//
// My notes:
// Pattern: Topological Sort + DFS
//
// Idea:
// Build a directed graph where prerequisite -> course.
// indegree[i] = number of prerequisites of course i.
// Start DFS from courses with indegree 0.
// When a course is completed, reduce the indegree of its neighbors.
// If a neighbor's indegree becomes 0, it is ready to be completed.
//
// The output stores the valid course order.
// If output.size() != numCourses, there is a cycle.
//
// Time: O(V + E)
// Space: O(V + E)


class Solution {
    vector<int> output;
    vector<int> indegree;
    vector<vector<int>> adj;
    void dfs(int node) {
        output.push_back(node);
        indegree[node]--;
        for(int nei : adj[node]){
            indegree[nei]--;
            if(indegree[nei] == 0){
                dfs(nei);
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        indegree = vector<int>(numCourses, 0);
        for(auto& pre : prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                dfs(i);
            }
        }
        if(output.size() != numCourses) return {};
        return output;
    }
};
