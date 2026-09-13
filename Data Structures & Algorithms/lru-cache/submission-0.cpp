class Node {
   public:
    int key;
    int val;
    Node* prev;
    Node* next;

    // constructor
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
   private:
    int cap;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }
    void insertAfterHead(Node* node) {
        Node* currAfterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = currAfterHead;
        currAfterHead->prev = node;
    }

   public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;  // not present
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == cap) {
                Node* node = tail->prev;  // deleting the least recently used node
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};
