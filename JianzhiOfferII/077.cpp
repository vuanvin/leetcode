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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        auto dummyNode = new ListNode();
        auto p = dummyNode;

        while (p) {
            if (!l1 && !l2) {
                p->next = nullptr;
            } else if (!l1) {
                p->next = l2;
                l2 = l2->next;
            } else if (!l2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                if (l1->val > l2->val) swap(l1, l2);
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        p = dummyNode->next;
        delete dummyNode;
        return p;
    }

    ListNode* sort(ListNode* head, int n) {
        if (n <= 1) {
            return head;
        }

        int n1 = n / 2;
        int n2 = n - n1;

        auto l1 = head, p = head;
        for (int i = 1; i < n1; i++) { p = p->next; }
        auto l2 = p->next;
        p->next = 0;

        return merge(sort(l1, n1), sort(l2, n2));
    }

    ListNode* sortList(ListNode* head) {
        vector<int> arr;

        int n = 0;
        auto p = head;
        while (p) {
            p = p->next;
            n++;
        }

        return sort(head, n);
    }
};