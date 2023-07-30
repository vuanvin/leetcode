#include <leetcode.h>

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *p, *q, *h;
        if (!head || !head->next) return;
        p = h = head;
        while (p) {
            h = h->next;
            p = p->next;
            if (p) p = p->next;
        }

        q = nullptr;
        p = h;
        while (p) {
            h = p;
            p = h->next;
            h->next = q;
            q = h;
        }

        p = head;
        while (h) {
            q = p->next;
            p->next = h;
            p = p->next;
            h = q;
        }
        if (p) p->next = nullptr;
    }
};