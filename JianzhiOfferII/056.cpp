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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        stack<TreeNode*> ls;
        for (auto p = root; p; p = p->left) { ls.push(p); }
        stack<TreeNode*> rs;
        for (auto p = root; p; p = p->right) { rs.push(p); }

        auto lp = ls.top(); auto rp = rs.top();

        while (lp != rp) {
            if (lp->val + rp->val == k) {
                return true;
            }
            if (lp->val + rp->val < k) {
                ls.pop();
                lp = lp->right;
                while (lp) { ls.push(lp); lp = lp->left; }
                lp = ls.top();
            } else {
                rs.pop();
                rp = rp->left;
                while (rp) { rs.push(rp); rp = rp->right; }
                rp = rs.top();
            }
        }
        return false;
    }
};