#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *dummyNode = new ListNode();
    auto p = dummyNode;

    int start = 0;
    int n = lists.size();
    while (start < n && !lists[start]) start++;

    while (start < n) {
        auto minId = start;
        for (int i = start; i < n; i++) {
            if (lists[i] && lists[i]->val < lists[minId]->val) {
                minId = i;
            }
        }
        p->next = new ListNode(lists[minId]->val);
        p = p->next;

        lists[minId] = lists[minId]->next;
        while (start < n && !lists[start]) start++;
    }

    auto res = dummyNode->next;
    delete dummyNode;
    return res;
}