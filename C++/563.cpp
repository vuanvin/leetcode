#include <leetcode.h>

class Solution {
public:
    int ans;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        auto lv = dfs(root->left), rv = dfs(root->right);
        ans += abs(lv - rv);
        return lv + rv + root->val;
    }
    int findTilt(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};