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
public:

    int helper(TreeNode* root, int targetSum, bool is_start = false) {
        if (!root) return 0;

        int sum = 0;
        int val = root->val;
        if (val == targetSum) {
            sum++;
        }


        sum += helper(root->left, targetSum - val, true);
        sum += helper(root->right, targetSum - val, true);

        if (!is_start) {
            sum += helper(root->left, targetSum);
            sum += helper(root->right, targetSum);
        }

        return sum;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return helper(root, targetSum);
    }
};