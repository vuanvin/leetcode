#include <leetcode.h>

class Solution {
private:
    int ans;

public:
    int inorder(TreeNode* root) {
        if (!root) return 0;
        int left = max(inorder(root->left), 0);
        int right = max(inorder(root->right), 0);
        ans = max(left + right + root->val, ans);
        return max(left + root->val, right + root->val);
    }

    int maxPathSum(TreeNode* root) {
        ans = root->val;
        inorder(root);
        return ans;
    }
};