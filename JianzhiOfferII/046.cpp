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
    vector<int> ans;

public:
    void dfs(TreeNode *root, int deep) {
        if (!root) return;
        if (ans.size() <= deep) {
            ans.push_back(root->val);
        }
        dfs(root->right, deep + 1);
        dfs(root->left, deep + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);

        return ans;
    }
};