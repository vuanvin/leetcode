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

class CBTInserter {
    TreeNode *root;
    int dir;
    int high;

public:
    void helper(TreeNode* p) {
        if (!p) return;
        dir++;
        helper(p->left);
        helper(p->right);
    }

    CBTInserter(TreeNode* root) {
        dir = 0;
        this->root = root;
        helper(root);
    }
    
    int insert(int v) {
        dir++;
        int base = 1 << 30;
        while (base & dir) { base >>= 1; }
        base >>= 1;

        auto p = root;
        while (base != 1) {
            if (base & dir) {
                p = p->right;
            } else {
                p = p->left;
            }
            base >>= 1;
        }
        if (base & dir) {
            p->right = new TreeNode(v);
        } else {
            p->left = new TreeNode(v);
        }
    }
    
    TreeNode* get_root() {
        return root;
    }
};