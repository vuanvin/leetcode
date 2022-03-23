#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        Node *prev, *next;
        int key, val;
        Node(int k = 0, int v=0, Node *p=nullptr, Node *n=nullptr) 
                : key(k), val(v), prev(p), next(n) {}
    };
    unordered_map <int, Node*> val2node;
    Node *head;
    int capacity;

public:
    LRUCache(int capacity) {
        head = new Node();
        head->next = head->prev = head;
        this->capacity = capacity;
    }

    void remove(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void add(Node *node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }

    int del() {
        auto node = head->prev;
        node->prev->next = head;
        head->prev = node->prev;
        int key = node->key;
        delete node;
        return key;
    }

    int get(int key) {
        if (!val2node.count(key)) { return -1; }
        auto ret = val2node[key]->val;

        auto node = val2node[key];
        remove(node);
        add(node);

        return ret;
    }
    
    void put(int key, int value) {
        if (!val2node.count(key)) {
            if (val2node.size() == capacity) {
                val2node.erase(del());
            }
            auto node = new Node(key, value);
            add(node);
            val2node[key] = node;
        } else {
            auto node = val2node[key];
            remove(node);
            add(node);
            node->val = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */