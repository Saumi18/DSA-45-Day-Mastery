// Day 16 — Linked List
// Problem: Merge Two Sorted Lists
//
// Pattern: Two Pointers
// Idea: Choose the smaller head, then repeatedly attach the smaller
//       current node to tail. Attach the remaining list at the end.
//
// Time: O(n + m)
// Space: O(1)


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;

        if (h1 == NULL) return h2;
        if (h2 == NULL) return h1;

        ListNode* head;
        ListNode* tail;

        // Choose the first node
        if (h1->val <= h2->val) {
            head = tail = h1;
            h1 = h1->next;
        }
        else {
            head = tail = h2;
            h2 = h2->next;
        }
        // Merge both lists
        while (h1 != NULL && h2 != NULL) {
            if (h1->val <= h2->val) {
                tail->next = h1;
                tail = h1;
                h1 = h1->next;
            }
            else {
                tail->next = h2;
                tail = h2;
                h2 = h2->next;
            }
        }
        // Attach remaining nodes
        tail->next = h1 ? h1 : h2;
        return head;
    }
};
