//
// Created by YUANYIN on 2020/10/29.
//

#ifndef C_LISTNODE_H
#define C_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif //C_LISTNODE_H
