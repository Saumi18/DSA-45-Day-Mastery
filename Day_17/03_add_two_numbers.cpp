// Day 17 — Linked List (cont.)
// Problem: Add Two Numbers
//
// My notes:
// Pattern: Digit-by-digit addition + Carry
// Idea: Add corresponding digits and carry, create a new node for each digit.
// Time: O(max(n, m))
// Space: O(max(n, m))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // Dummy node helps us easily build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        // Continue while nodes or carry are remaining
        while (l1 != NULL || l2 != NULL || carry != 0) {
            // Start sum with previous carry
            int sum = carry;
            // Add digit from first list
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add digit from second list
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            // Create a new node for the current digit
            temp->next = new ListNode(sum % 10);
            // Calculate carry for the next digit
            carry = sum / 10;
            // Move to the newly created node
            temp = temp->next;
        }
        // Skip dummy and return the actual result list
        return dummy->next;
    }
};
