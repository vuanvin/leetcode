#include <leetcode.h>

class Solution {
private:
    vector<int> eg;
    vector<vector<int>> ans;

public:
    void dfs(TreeNode* root, int sum, int target) {
        int val = root->val;
        eg.push_back(val);
        sum += val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target) {
                ans.push_back(eg);
            }
        } else {
            if (root->left) dfs(root->left, sum, target);
            if (root->right) dfs(root->right, sum, target);
        }
        eg.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root) dfs(root, 0, targetSum);
        return ans;
    }
};