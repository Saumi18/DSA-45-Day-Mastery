// Day 19 — Linked List Adv.
// Problem: Reverse Nodes in K-Group
//
// Pattern: Linked List Reversal + Grouping
// Time: O(n)
// Space: O(1)
//
// Idea:
// Divide the linked list into groups of k nodes.
// Find the end of each group and check if k nodes exist.
// Save the first node of the next group.
// Reverse the current group using 3 pointers.
// Connect the reversed group with the previous group.
//
// Pointers:
// start -> first node of current group
// end -> last node of current group
// nextGroup -> first node of next group
// prevGroup -> last node of previous reversed group
//
// During reversal:
// prev starts at nextGroup so the reversed group's last node
// automatically connects to the next group.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* prevGroup = NULL;
        while (start != NULL) {
            ListNode* end = start;
            int count = 1;
            while (count < k && end != NULL) {
                end = end->next;
                count++;
            }
            if (end == NULL)
                break;
            ListNode* nextGroup = end->next;
            ListNode* prev = nextGroup;
            ListNode* curr = start;
            while (curr != nextGroup) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            if (prevGroup != NULL)
                prevGroup->next = end;
            else
                head = end;
            prevGroup = start;
            start = nextGroup;
        }
        return head;
    }
};
