#include <leetcode.h>

class Solution {
public:
    TreeNode* copyTree(TreeNode* root) { return root ? new TreeNode(0, copyTree(root->left), copyTree(root->right)) : nullptr; }
    void removeTree(TreeNode* root) {
        if (!root) return;
        removeTree(root->left);
        removeTree(root->right);
        delete root;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if (n % 2 == 0) return res;
        if (n == 1) {
            res.push_back(new TreeNode(0));
        }

        for (int i = 1; i < n; i += 2) {
            int j = n - 1 - i;
            auto l = allPossibleFBT(i);
            auto r = allPossibleFBT(j);

            for (int ii = 0; ii < l.size(); ii++) {
                for (int jj = 0; jj < r.size(); jj++) {
                    res.push_back(new TreeNode(0, copyTree(l[ii]), copyTree(r[jj])));
                }
            }

            for (int ii = 0; ii < l.size(); ii++) {
                removeTree(l[ii]);
            }
            for (int jj = 0; jj < r.size(); jj++) {
                removeTree(r[jj]);
            }
        }

        return res;
    }
};