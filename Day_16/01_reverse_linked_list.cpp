// Day 16 — Linked List
// Problem: Reverse Linked List
//
// Pattern: Iterative Linked List Reversal
// Idea: Use 3 pointers — t1 (previous), t2 (current), t3 (next).
//       Save the next node, reverse the link, then move pointers forward.
//
// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* t1 = head;        // Previous node
        ListNode* t2 = t1->next;    // Current node
        t1->next = NULL;            // Old head becomes the last node

        while (t2 != NULL) {
            ListNode* t3 = t2->next; // Save next node
            t2->next = t1;           // Reverse the link
            t1 = t2;                 // Move previous forward
            t2 = t3;                 // Move current forward
        }
        return t1; // t1 is the new head
    }
};
