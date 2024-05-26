#include <leetcode.h>

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> ori{{original}}, clo{{cloned}};
        while (!ori.empty()) {
            auto p = ori.top();
            auto q = clo.top();
            ori.pop();
            clo.pop();
            if (p == target) {
                return q;
            }
            if (p->left) {
                ori.push(p->left);
                clo.push(q->left);
            }
            if (p->right) {
                ori.push(p->right);
                clo.push(q->right);
            }
        }
        return cloned;
    }
};