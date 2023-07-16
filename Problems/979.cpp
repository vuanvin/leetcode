#include <leetcode.h>

class Solution {
    int ans;
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        auto sum = dfs(root->left) + dfs(root->right) + root->val - 1;
        ans += abs(sum);
        return sum;
    }

    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};