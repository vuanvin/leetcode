#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* inverse(ListNode *head) {
        ListNode *p = nullptr, *r = head;
        while (r) {
            head = r;
            r = head->next;
            head->next = p;
            p = head;
        }
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = inverse(l1);
        l2 = inverse(l2);
        ListNode *ans = nullptr, *p;
        int carry = 0;
        while (l1 || l2 || carry) {
            auto sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            } 
            if (l2) {
                sum += l2->val;
                l2 = l2->next; 
            }
            if (ans) {
                p->next = new ListNode(sum % 10);
                p = p->next;
            } else {
                p = ans = new ListNode(sum % 10);
            }
            carry = sum / 10;
        }
        return inverse(ans);
    }
};