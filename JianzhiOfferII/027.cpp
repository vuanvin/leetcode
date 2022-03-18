#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head) return true;
    auto mid = middleNode(head);
    auto l1 = head;
    auto l2 = mid->next;
    mid->next = nullptr;
    l2 = reverseList(l2);
    while (l2) {
        if (l1->val != l2->val) return false;
        l1 = l1->next; l2 = l2->next;
    }
    return true;
}