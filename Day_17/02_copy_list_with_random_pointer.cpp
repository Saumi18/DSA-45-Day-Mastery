// Day 18 — Linked List (cont.)
// Problem: Copy List with Random Pointer
//
// My notes:
// Pattern: Hash Map (Original Node → Copy Node)
// Idea: Create a copy of every node and map each original node to its copy.
//       Then use the map to connect next and random pointers.
// Time: O(n)
// Space: O(n)


class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Map each original node to its copied node
        unordered_map<Node*, Node*> oldTocopy;
        oldTocopy[NULL] = NULL;
        
        Node* curr1 = head;
        // First pass: create all copied nodes
        for (curr1 = head; curr1 != NULL; curr1 = curr1->next) {
            Node* copy = new Node(curr1->val);
            oldTocopy[curr1] = copy;
        }

        Node* curr2 = head;
        // Second pass: connect next and random pointers
        while (curr2 != NULL) {
            Node* copy = oldTocopy[curr2];
            // Connect next pointer to copied next node
            copy->next = oldTocopy[curr2->next];
            // Connect random pointer to copied random node
            copy->random = oldTocopy[curr2->random];
            curr2 = curr2->next;
        }
        // Return the copied head
        return oldTocopy[head];
    }
};
