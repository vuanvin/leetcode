#include <leetcode.h>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val > list2->val) {
            swap(list1, list2);
        }
        auto p = list1;
        while (list2) {
            if (p->next) {
                if (p->next->val > list2->val) {
                    auto tail = p->next;
                    p->next = list2;
                    list2 = list2->next;
                    p->next->next = tail;
                } else {
                    p = p->next;
                }
            } else {
                p->next = list2;
                break;
            }
        }
        return list1;
    }
};