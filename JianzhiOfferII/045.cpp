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
    int n;
    int num;

public:
    void dfs(TreeNode *root, int deep) {
        if (!root) return;
        if (n <= deep) {
            n = deep + 1;
            num = root->val;
        }
        dfs(root->left, deep + 1);
        dfs(root->right, deep + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        n = 0;
        dfs(root, 0);

        return num;
    }
};