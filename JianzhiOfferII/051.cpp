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

int res = INT_MIN;

int visit(TreeNode* root) {
    int val = root->val;
    int lv = 0, rv = 0;
    if (root->left) lv = visit(root->left);
    if (root->right) rv = visit(root->right);

    res = max(res, val);
    res = max(res, val + lv + rv);
    res = max(res, val + lv);
    res = max(res, val + rv);

    return max(max(val + rv, val + lv), val);
}

int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    visit(root);
    return res;
}