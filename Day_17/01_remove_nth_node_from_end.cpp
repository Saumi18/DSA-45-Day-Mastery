// Day 17 — Linked List (cont.)
// Problem: Remove Nth Node From End
//
// My notes:
// Pattern: Find length → Find node before target → Skip target
// Time: O(n)
// Space: O(1)


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Find the length of the linked list
        ListNode* temp = head;
        int m = 0;

        while (temp != NULL) {
            m++;
            temp = temp->next;
        }
        // If nth node from end is the head
        if (m == n)
            return head->next;
        // Move to the node just before the node to remove
        int cnt = 1;
        temp = head;
        while (cnt != m - n) {
            temp = temp->next;
            cnt++;
        }
        // t1 = node to remove
        // t2 = node after the node to remove
        ListNode* t1 = temp->next;
        ListNode* t2 = temp->next->next;
        // Skip t1
        temp->next = t2;
        return head;
    }
};
