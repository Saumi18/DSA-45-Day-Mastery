// Day 17 — Linked List (cont.)
// Problem: Remove Nth Node From End
//
// My notes:
// Pattern: Find length → Find node before target → Skip target
// Time: O(n)
// Space: O(1)

// There are two approaches - One pass and two pass

// Two pass approach
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

// One pass :

/*## Intuition

Keep `fast` n nodes ahead of `slow`.
When `fast` reaches the end, `slow` is exactly before the node to remove.

A dummy node is used so removing the head works the same way as removing any other node.

## Complexity

- Time: O(n)
- Space: O(1)*/
    
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy handles the case where we remove the head
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n nodes ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // Move both until fast reaches the last node
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        // slow->next is the node to remove
        slow->next = slow->next->next;
        return dummy->next;
    }
};
