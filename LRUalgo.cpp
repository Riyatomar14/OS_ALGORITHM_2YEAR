//LRU ALGORITHM
#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    // constructor
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    Node* head;
    Node* tail;

    // Helper function to move a node to the front (most recently used)
    void moveToFront(Node* node) {
        if (node == head) return; // Already at the front

        // Remove node from its current position
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        if (node == tail) {
            tail = node->prev; // Update tail if necessary
        }

        // Insert node at the front
        node->next = head;
        node->prev = nullptr;
        if (head) {
            head->prev = node;
        }
        head = node;

        // If it was the first node, update tail
        if (!tail) {
            tail = head;
        }
    }

    // Remove the least recently used node (tail)
    void removeTail() {
        if (!tail) return;
        int keyToRemove = tail->key;

        if (tail->prev) {
            tail->prev->next = nullptr;
        }
        Node* temp = tail;
        tail = tail->prev;
        delete temp; // Free memory

        // Logically "remove" the key (not physically, since we don't have a map)
        cout << "Removed key: " << keyToRemove << endl;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

    int get(int key) {
        Node* current = head;
        while (current) {
            if (current->key == key) {
                moveToFront(current);
                return current->value;
            }
            current = current->next;
        }
        return -1; // Not found
    }

    void put(int key, int value) {
        Node* current = head;
        while (current) {
            if (current->key == key) {
                current->value = value; // Update value
                moveToFront(current);
                return;
            }
            current = current->next;
        }

        // If the key is not found, create a new node
        Node* newNode = new Node(key, value);
        if (capacity == 0) {
            removeTail(); // Evict least recently used item
        } else {
            capacity--;
        }

        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;

        // If it's the first node, set tail
        if (!tail) {
            tail = head;
        }
    }

    ~LRUCache() {
        // Clean up memory
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LRUCache* cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl; // returns 1
    cache->put(3, 3); // evicts key 2
    cout << cache->get(2) << endl; // returns -1 (not found)
    cache->put(4, 4); // evicts key 1
    cout << cache->get(1) << endl; // returns -1 (not found)
    cout << cache->get(3) << endl; // returns 3
    cout << cache->get(4) << endl; // returns 4

    delete cache; // Clean up the cache
    return 0;
}
