#include <bits/stdc++.h>
using namespace std;

class MapSum {
private:
    struct Node {
        int val;
        int sum;
        vector<Node*> child;
        Node(int v = 0, int s = 0) : val(v), sum(s), child(26, nullptr) {}
    };

    Node *head;

public:
    /** Initialize your data structure here. */
    MapSum() {
        head = new Node(0, 0);
    }

    void insert(string key, int val) {
        auto p = head;
        for (auto ch : key) {
            p = p->child[ch - 'a'];
            if (!p) break;
        }
        if (p) {
            auto old_val = p->val;
            p = head;
            for (auto ch : key) {
                p->sum = p->sum + val - old_val;
                p = p->child[ch - 'a'];
            }
            p->sum = p->sum + val - old_val;
            p->val = val;
        } else {
            p = head;
            for (auto ch : key) {
                p->sum += val;
                if (!p->child[ch - 'a']) {
                    p->child[ch - 'a'] = new Node(0, 0);
                }
                p = p->child[ch - 'a'];
            }
            p->val = val;
            p->sum = val;
        }
    }
    
    int sum(string prefix) {
        auto p = head;
        for (auto ch : prefix) {
            p = p->child[ch - 'a'];
            if (!p) break;
        }

        if (!p) return 0;
        return p->sum;
    }
};