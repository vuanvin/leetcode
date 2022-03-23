#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *pre;
    TreeNode *ans;

public:
    void inorder(TreeNode* root, TreeNode* p) {
        if (!root) return;
        inorder(root->left, p);
        if (pre == p) {
            ans = root;
        }
        pre = root;
        inorder(root->right, p);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        pre = nullptr;
        ans = nullptr;
        inorder(root, p);
        return ans;
    }
};