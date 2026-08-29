// Day 19 — Linked List Adv.
// Problem: Merge K Sorted Lists
//
// My notes:
// Pattern: Min Heap / Priority Queue
// Time: O(N log K)
// Space: O(K)
//
// Idea:
// Put the head of every non-empty list into a min heap.
// Take the smallest node, add it to the result,
// then push its next node into the heap.
// Continue until the heap is empty.
//
// N = total number of nodes
// K = number of linked lists
//
// Comparator:
// Custom comparator makes the priority queue a min heap
// based on ListNode->val.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> minHeap;
        ListNode* head = new ListNode(0);
        for (ListNode* node : lists) {
            if (node != NULL){
                minHeap.push(node);
            }
        }
        ListNode* tail = head;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();
            tail->next = node;
            tail = tail->next;
            if(node->next!=NULL) minHeap.push(node->next);
        }
        return head->next;
    }
};

