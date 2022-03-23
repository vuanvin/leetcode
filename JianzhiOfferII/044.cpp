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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> st;

        st.push(root);
        int n = 1;

        while (n) {
            int mn = INT_MIN;
            for (int i = 0; i < n; i++) {
                auto p = st.front(); st.pop();
                mn = max(mn, p->val);
                if (p->left) st.push(p->left);
                if (p->right) st.push(p->right);
            }
            ans.push_back(mn);
            n = st.size();
        }
        return ans;
    }
};