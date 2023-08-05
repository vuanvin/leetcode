#include <leetcode.h>

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        auto p = head;
        head = head->next;
        auto q = head;
        while (q) {
            p->next = q->next;
            q->next = p;
            if (!p->next) {
                break;
            }
            q = p->next;
            if (!q->next) {
                break;
            }
            p->next = q->next;
            p = q;
            q = q->next;
        }
        return head;
    }
};