#include <leetcode.h>

class Solution {
    int res;

public:
    void dfs(TreeNode* root, int mn, int mx) {
        if (!root) {
            res = max(mx - mn, res);
            return;
        }
        mn = min(root->val, mn);
        mx = max(root->val, mx);
        dfs(root->left, mn, mx);
        dfs(root->right, mn, mx);
    }

    int maxAncestorDiff(TreeNode* root) {
        res = INT_MIN;
        dfs(root, root->val, root->val);
        return res;
    }
};