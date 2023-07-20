#include <leetcode.h>

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *pred = nullptr, *succ = nullptr;
        while (root) {
            if (root->left) {
                pred = root->left;
                succ = root->right;
                root->right = pred;
                root->left = nullptr;
                while (pred->right) pred = pred->right;
                pred->right = succ;
            }
            root = root->right;
        }
    }
};