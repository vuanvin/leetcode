#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            auto newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        auto curr = head;
        while (curr->next != head) {
            if ((curr->val <= insertVal) ^ (insertVal <= curr->next->val) ^
                    (curr->val <= curr->next->val)) {
                break;
            }
            curr = curr->next;
        }
        curr->next = new Node(insertVal, curr->next);

        return head;
    }

};