//
// Created by YUANYIN on 2020/10/9.
//

#ifndef CPPLEETCODE_SOLUTION_H
#define CPPLEETCODE_SOLUTION_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
#include <queue>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    bool hasCycle(ListNode *head) {
        if (!head || !(head->next)) return true;
        ListNode *p = head, *q = head;
        while (q) {
            p = p->next;

            q = q->next;
            if (!q) return false;
            q = q->next;

            if (q == p) return true;
        }
        return false;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode *p = head, *q = head;
        for (int i = 0; i < k-1; i++) {
            p = p->next;
        }
        while (head) {
            q = head->next;
            head->next = p;
            p = head;
            head = q;
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int first = 0, n = words.size(), slen = s.length();
        if (n == 0 || slen == 0) return res;
        int wlen = words[0].length();

        int arr[10000+5] = {0};
        for (int i = 0; i < slen; i++) arr[i] = -1;

        for (int i = 0; i < n; i++) {
            int p = s.find(words[i]);
            while (p < wlen) {
                arr[p] = i;
                p = s.find(words[i], p+1);
            }
        }

        list<int> appear;
        for (int first = 0; first < wlen; first++) {
            int start;
            for (int i = first; i < slen; i += wlen) {
                if (arr[i] == -1) {
                    appear.clear();
                } else {
                    if (appear.empty()) { start = i; }
                    list<int>::iterator it = find(appear.begin(), appear.end(), arr[i]);
                    appear.push_back(arr[i]);
                    if (appear.end() == it) {
                        appear.push_back(arr[i]);
                        if (appear.size() == n) {
                            res.push_back(start);
                            appear.pop_front();
                            start += wlen;
                        }

                    } else {
                        list<int>::iterator other = appear.begin();
                        if (other != it) {
                            other ++;
                            appear.pop_front();
                            start += wlen;
                        }
                        appear.pop_front();
                        start += wlen;
                    }
                }
            }
            appear.clear();
        }

        return res;
    }

};


#endif //CPPLEETCODE_SOLUTION_H
