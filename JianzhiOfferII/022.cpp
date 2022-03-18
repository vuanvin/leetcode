#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    if (!head) return nullptr;

    q = q->next;
    if (!q) { return nullptr; }
    q = q->next;
    if (!q) { return nullptr; }
    p = p->next;
    int n = 1;
    while (p != q) {
        q = q->next;
        if (!q) { return nullptr; }
        q = q->next;
        if (!q) { return nullptr; }
        p = p->next;
        n++;
    }

    p = p->next;
    q = q->next->next;
    int m = 1;
    while (p != q) {
        q = q->next->next;
        p = p->next;
        m++;
    }

    int l = n / m;
    
    if (l == 0) return head;

    p = head;
    for (int i = 0; i < (l-1)*m; i++) {
        p = p->next;
    }
    q = p;
    for (int i = 0; i < m; i++) {
        q = q->next;
    }

    while (p != q) {
        p = p->next; 
        q = q->next; 
    }

    return p;
}