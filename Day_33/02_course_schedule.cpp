// Day 33 — Graphs Adv.
// Problem: Course Schedule
//
// My notes:
// Pattern: DFS + Cycle Detection
//
// Idea:
// Convert prerequisites into a directed graph.
// preMap[course] = prerequisites of that course.
// Use DFS to detect circular dependencies.
// visited stores courses in the current DFS path.
// If we reach a course already in visited, there is a cycle.
// After checking a course, clear its prerequisites so we don't check it again.
//
// Time: O(V + E)
// Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++){
            preMap[i] = {};
        }
        for(const auto& prereq : prerequisites){
            preMap[prereq[0]].push_back(prereq[1]);
        }
        for(int c = 0; c < numCourses; c++){
            if(!dfs(c)){
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs){
        if(visited.count(crs)) return false;
        if(preMap[crs].empty()) return true;
        visited.insert(crs);
        for(int pre : preMap[crs]){
            if(!dfs(pre)){
                return false;
            }
        }
        
        visited.erase(crs);
        preMap[crs].clear();
        return true;
    }
};
