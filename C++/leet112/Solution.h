//
// Created by YUANYIN on 2020/10/21.
//

#ifndef C___SOLUTION_H
#define C___SOLUTION_H
#include "../leetcode.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) {
            if (root->val == sum) return true;
            else return false;
        }

        if (root->left && root->right) return hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val);
        if (root->left) return hasPathSum(root->left, sum - root->val);
        else  return hasPathSum(root->right, sum - root->val);
    }
};

#endif //C___SOLUTION_H
