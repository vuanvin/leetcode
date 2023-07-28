#include <leetcode.h>

class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto [ly, ln] = dfs(root->left);
        auto [ry, rn] = dfs(root->right);
        auto sn = ly + ry;
        return {max(ln + rn + root->val, sn), sn};
    }
    int rob(TreeNode* root) {
        auto [y, n] = dfs(root);
        return max(y, n);
    }
};