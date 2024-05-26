#include <leetcode.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;

public:
    pair<int, int> dfs(TreeNode* root, int start) {
        if (!root) {
            return {0, 0};
        }

        if (start == root->val) {
            auto [l, ld] = dfs(root->left, start);
            auto [r, rd] = dfs(root->right, start);
            ans = max(l, r);
            return {0, 1};
        }

        auto [l, ld] = dfs(root->left, start);
        if (ld > 0) {
            auto [r, rd] = dfs(root->right, start);
            ans = max(r + ld, ans);
            return {0, ld + 1};
        }

        auto [r, rd] = dfs(root->right, start);
        if (rd > 0) {
            ans = max(l + rd, ans);
            return {0, rd + 1};
        }

        return {max(l, r) + 1, 0};
    }

    int amountOfTime(TreeNode* root, int start) {
        ans = 0;
        dfs(root, start);
        return ans;
    }
};