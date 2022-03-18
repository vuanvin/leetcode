#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

void add(Node *currNode, Node *nextNode) {
    currNode->next = nextNode;
    nextNode->prev = currNode;
}

Node* flatten(Node* head) {
    if (!head) return head;
    stack<Node*> st;
    auto currNode = head;
    while (currNode) {
        auto childNode = currNode->child;
        auto nextNode = currNode->next;

        if (childNode) {
            if (!nextNode) st.push(nextNode);
            add(currNode, childNode);
            currNode->child = nullptr;
        } else if (!nextNode && !st.empty()) {
            add(currNode, st.top());
            st.pop();
        }

        currNode = currNode->next;
    }
    return head;
}