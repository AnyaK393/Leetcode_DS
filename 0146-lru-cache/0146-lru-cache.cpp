class LRUCache {
public:

    // Doubly Linked List Node
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    // Dummy nodes
    // head = most recently used side
    // tail = least recently used side
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // key -> address of node
    unordered_map<int, Node*> m;

    int limit;


    // Add a node immediately after head
    // This means the node becomes MOST recently used
    void addNode(Node* newNode) {

        Node* oldNode = head->next;

        head->next = newNode;
        oldNode->prev = newNode;

        newNode->next = oldNode;
        newNode->prev = head;
    }


    // Remove a node from the linked list
    void deleteNode(Node* oldNode) {

        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }


    LRUCache(int capacity) {

        limit = capacity;

        // Initially:
        // head <-> tail
        head->next = tail;
        tail->prev = head;
    }


    int get(int key) {

        // Key not present
        if(m.find(key) == m.end()) {
            return -1;
        }

        // Get the node from map
        Node* ansNode = m[key];

        // Store its value
        int ans = ansNode->val;

        // Remove it from its current position
        deleteNode(ansNode);

        // Put it at the front
        // because it was just used
        addNode(ansNode);

        return ans;
    }


    void put(int key, int value) {

        // If key already exists
        if(m.find(key) != m.end()) {

            Node* oldNode = m[key];

            // Remove old node from linked list
            deleteNode(oldNode);

            // Remove from map
            m.erase(key);

            // Free memory
            delete oldNode;
        }


        // Cache is full
        if(m.size() == limit) {

            // tail->prev is the LEAST recently used node
            Node* oldNode = tail->prev;

            // Remove it from map
            m.erase(oldNode->key);

            // Remove it from linked list
            deleteNode(oldNode);

            // Free memory
            delete oldNode;
        }


        // Create new node
        Node* newNode = new Node(key, value);

        // New node becomes most recently used
        addNode(newNode);

        // Store node address in map
        m[key] = newNode;
    }
};