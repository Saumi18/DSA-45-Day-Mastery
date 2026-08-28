// Day 18 — Linked List Adv.
// Problem: Linked List Cycle
//
// My notes:
// Pattern: Hash Map / Visited Nodes
// Time: O(n)
// Space: O(n)
//
// Idea:
// Store every node's address in a hash map.
// If we encounter the same node again, a cycle exists.
// If temp becomes NULL, there is no cycle.

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> mp;
        ListNode* temp = head;

        while (temp != NULL) {
            mp[temp]++;
            if (mp[temp] > 1)
                return true;
            temp = temp->next;
        }
        return false;
    }
};
