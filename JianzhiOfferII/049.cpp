#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans;

public:
    void dfs(TreeNode* root, int prefix) {
        if (!root->left && !root->right) {
            int num = prefix * 10 + root->val;
            ans += num;
            return;
        }

        (prefix *= 10) += root->val;
        if (root->left) { dfs(root->left, prefix); }
        if (root->right) { dfs(root->right, prefix); }
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};