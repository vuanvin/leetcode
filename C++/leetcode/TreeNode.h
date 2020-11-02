//
// Created by YUANYIN on 2020/10/29.
//

#ifndef C_TREENODE_H
#define C_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //C_TREENODE_H
