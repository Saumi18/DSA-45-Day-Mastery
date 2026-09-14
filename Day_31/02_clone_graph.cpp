// Day 34 — Graphs / DFS-BFS
// Problem: Clone Graph
//
// Approach 1: DFS
// Pattern: DFS + Hash Map
// Idea: Create a clone for each original node and store the mapping
//       original node → cloned node in a hash map.
//       Before cloning a node, check if it is already present in the map.
//       This handles cycles and prevents cloning the same node multiple times.
//       Recursively clone all neighbors and add them to the cloned node.
//
// Time: O(V + E)
// Space: O(V) for the map + O(V) recursion stack
//
// Approach 2: BFS
// Pattern: BFS + Hash Map
// Idea: Use a queue to traverse the graph level by level.
//       Create the clone of the starting node and store it in the map.
//       For every node, check all its neighbors.
//       If a neighbor has not been cloned, create its clone and add it to the queue.
//       Then connect the cloned node to the cloned neighbor.
//
// Time: O(V + E)
// Space: O(V) for the map + O(V) queue
//
// Key Pattern:
// Original Node → Cloned Node
// map[original] = clone
//
// Why do we need the map?
// Graphs can contain cycles.
// Without the map, DFS/BFS could keep visiting the same nodes forever.
//
// Example:
// 1 → 2 → 1
//
// When cloning 1:
// clone 1 → clone 2
// clone 2 → clone 1
//
// The map tells us that clone 1 already exists.


class Solution {
public:
// DFS APPROACH
    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        if(!node) return NULL;

        if(oldToNew.count(node)){
            return oldToNew[node];
        }
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for(Node* neighbor : node->neighbors){
            copy->neighbors.push_back(dfs(neighbor, oldToNew));
        }
        return copy;
    }
    Node* cloneGraphDFS(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }

// BFS APPROACH:
    Node* cloneGraphBFS(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* neighbor : curr->neighbors){
                if(!oldToNew.count(neighbor)){
                    oldToNew[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[neighbor]);
            }
        }
        return oldToNew[node];
    }
};
