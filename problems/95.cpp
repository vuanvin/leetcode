#include <leetcode.h>

class Solution {
public:
    vector<TreeNode*> inorder(int head, int tail) {
        if (head == tail) return {nullptr};
        vector<TreeNode*> res;
        for (int mid = head; mid < tail; ++mid) {
            auto left = inorder(head, mid);
            auto right = inorder(mid + 1, tail);
            for (auto l : left) {
                for (auto r : right) {
                    auto m = new TreeNode(mid + 1);
                    m->left = l;
                    m->right = r;
                    res.push_back(m);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) { return inorder(0, n); }
};