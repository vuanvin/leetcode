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

class BSTIterator {
private:
    TreeNode *root;
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto p = st.top(); st.pop();
        auto ret = p->val;
        p = p->right;
        while (p) {
            st.push(p);
            p = p->left;
        }

        return ret;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */