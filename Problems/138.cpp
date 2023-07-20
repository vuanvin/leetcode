#include <leetcode.h>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        for (auto n = head; n != nullptr; n = n->next->next) {
            auto nw = new Node(n->val);
            nw->next = n->next;
            n->next = nw;
        }
        for (auto n = head; n != nullptr; n = n->next->next) {
            auto nw = n->next;
            nw->random = n->random ? n->random->next : nullptr;
        }
        auto root = head->next;
        for (auto n = head; n != nullptr; n = n->next) {
            auto nw = n->next;
            n->next = nw->next;
            nw->next = nw->next ? nw->next->next : nullptr;
        }
        return root;
    }
};