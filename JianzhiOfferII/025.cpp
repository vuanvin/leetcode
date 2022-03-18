#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *r = nullptr, *p = l1, *q = nullptr;
    int m = 0, n = 0;
    while (p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
        m++;
    }
    l1 = r;

    r = nullptr; p = l2;
    while (p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
        n++;
    }
    l2 = r;

    if (m < n) swap(l1, l2);

    int carry = 0;
    p = l1;

    while (l2) {
        auto x = l1->val + l2->val + carry;
        carry = x / 10;
        l1->val = (x % 10);
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        auto x = l1->val + carry;
        carry = x / 10;
        l1->val = (x % 10);
        l1 = l1->next;
    }

    r = nullptr;
    while (p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }

    return carry ? new ListNode(carry, r) : r;
}