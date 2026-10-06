// Day 32 — Graphs (cont.)
// Problem: Rotting Oranges
//
// My notes:
// Pattern: Multi-source BFS / Level-order BFS
//
// Idea:
// Put all initially rotten oranges into the queue.
// They all start spreading simultaneously.
// Process the queue level by level, where each level = 1 minute.
// Whenever a fresh orange becomes rotten:
// 1. Mark it rotten
// 2. Add it to the queue
// 3. Decrease fresh count
//
// If fresh becomes 0, return the time.
// If BFS ends while fresh oranges remain, return -1.
//
// Time: O(m * n)
// Space: O(m * n)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0, time = 0;
        int rows = grid.size(), cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(fresh > 0 && !q.empty()) {
            int len = q.size();

            for(int i = 0; i < len; i++) {
                auto [r, c] = q.front();
                q.pop();

                for(auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                       grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
