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
private:
    int sum;

public:
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->right);
        sum += root->val;
        root->val = sum;
        inorder(root->left);
    } 

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inorder(root);
        return root;
    }
};