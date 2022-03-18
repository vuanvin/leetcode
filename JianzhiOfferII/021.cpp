#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd_1(ListNode* head, int n) {
    if (!head) return head;
    int m = 0;
    auto p = head;
    while (p) {
        p = p->next;
        m ++;
    }
    n = m - n;
    auto dummyNode = new ListNode(0, head);
    p = dummyNode;

    for (int i = 0; i < n; i++) {
        p = p->next;
    }

    auto q = p->next;
    p->next = q->next;

    delete q;

    head = dummyNode->next;
    delete dummyNode;
    return head;
}