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

Node* insert(Node* head, int insertVal) {
    auto newNode = new Node(insertVal);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    bool isAscend = true; 
    auto currNode = head->next;
    int add = 0;
    while (currNode != head) {
        auto nextNode = currNode->next;
        if (currNode->val < nextNode->val) {
            add++;
        } else if (currNode->val > nextNode->val) {
            add--;
        }
        currNode = nextNode;
    }

    if (add == 0) {
        while (currNode->next == head || currNode->next->val != currNode->val)
    }

    if (add > 1) {

        while () {

        }
    } else {

    }
}