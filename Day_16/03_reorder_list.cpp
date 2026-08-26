// Day 16 — Linked List
// Problem: Reorder List
//
// My notes:
// Pattern: Find middle(using slow and fast pointers) → Reverse second half → Merge alternately
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // 1. Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps
        }
        
        // Split into two lists
        // First half: head -> ... -> slow
        // Second half: slow->next -> ...
        ListNode* h1 = head;
        ListNode* h2 = slow->next;
        slow->next = NULL;  // Break the connection

        // 2. Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = h2;
        while (curr != NULL) {
            ListNode* next = curr->next; // Save next node
            curr->next = prev;           // Reverse link
            prev = curr;
            curr = next;
        }
        h2 = prev;  // h2 now points to reversed second half

        // 3. Merge the two halves alternately
        ListNode* s1 = h1;
        ListNode* s2 = h2;
        while (s1 != NULL && s2 != NULL) {
            // Save next nodes before changing links
            ListNode* next1 = s1->next;
            ListNode* next2 = s2->next;
            // Connect first node -> second node
            s1->next = s2;
            // Connect second node -> next first-half node
            s2->next = next1;
            // Move to the next pair
            s1 = next1;
            s2 = next2;
        }
    }
};
