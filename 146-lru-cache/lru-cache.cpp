class LRUCache {
    class Node {
    public:
        int key, val;
        Node *next, *prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
    int limit;

    // Helper functions to add and remove nodes from the doubly linked list
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;  // The oldNext is guaranteed to exist (tail in worst case).
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode) {
        Node* prevNode = oldNode->prev;
        Node* nextNode = oldNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;

        Node* ansNode = m[key];
        int ans = ansNode->val;

        // Move the accessed node to the front (most recently used)
        deleteNode(ansNode);
        addNode(ansNode);

        return ans;
    }

    void put(int key, int value) {
        // If key already exists, remove the old node
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        // If capacity is reached, remove the least recently used (LRU) node (tail->prev)
        if (m.size() == limit) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // Insert the new node
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
    
    ~LRUCache() {
        // Free the memory allocated for head, tail, and other nodes
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
