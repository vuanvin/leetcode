#include <leetcode.h>

class Solution {
public:
    bool less(TreeNode* root, int val) {
        return !root || (root->val < val && less(root->left, root->val) && greater(root->right, root->val) && less(root->right, val));
    }

    bool greater(TreeNode* root, int val) {
        return !root || (root->val > val && greater(root->left, val) && less(root->left, root->val) && greater(root->right, root->val));
    }

    bool isValidBST(TreeNode* root) { return !root || (less(root->left, root->val) && greater(root->right, root->val)); }
};