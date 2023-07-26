#include <leetcode.h>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        auto p = root;
        stack<TreeNode*> st;
        for (; p != nullptr; p = p->left) st.push(p);
        for (int i = 0; i < k; ++i) {
            p = st.top();
            st.pop();
            if (p->right) {
                auto q = p->right;
                for (; q != nullptr; q = q->left) st.push(q);
            }
        }
        return p->val;
    }
};