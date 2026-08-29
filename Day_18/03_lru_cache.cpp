// Day 19 — Linked List Adv.
// Problem: LRU Cache
//
// My notes:
// Pattern: Hash Map + Doubly Linked List
// Time: O(1) for get() and put()
// Space: O(capacity)
//
// Idea:
// Hash map stores key -> Node* for O(1) lookup.
// Doubly linked list maintains usage order.
//
// left → LRU → ... → MRU → right
//
// On get():
// Remove the node and insert it at the MRU position.
//
// On put():
// Insert the new node at MRU.
// If capacity is exceeded, remove the LRU node.
//
// Dummy left and right nodes simplify insertion and deletion.


class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    // Removes a node from the doubly linked list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }
    // Inserts a node at the MRU side (just before right)
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:
    // Creates empty cache with given capacity
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    // Returns value and moves node to MRU
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    // Adds/updates key and removes LRU if capacity is exceeded
    void put(int key, int value) {
        if (cache.find(key) != cache.end())
            remove(cache[key]);
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
