#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head) return head;
    ListNode *r = nullptr, *p = head, *q = nullptr;
    while (p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    return r;
}