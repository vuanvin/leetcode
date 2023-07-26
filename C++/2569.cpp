#include <leetcode.h>

class Solution {
public:
    struct Node {
        bool tag;
        int l, r, num;  // [l, r)
    };
    vector<Node> tree;
    int build(int i, int x, int y, const vector<int>& nums) {
        tree[i].tag = false;
        tree[i].l = x, tree[i].r = y;
        if (x + 1 == y) {
            tree[i].num = nums[x];
        } else {
            int m = (x + y) / 2;
            tree[i].num = build(i * 2 + 1, x, m, nums) + build(i * 2 + 2, m, y, nums);
        }
        return tree[i].num;
    }
    int flip(int i, int x, int y, bool tag) {
        if (tag) {
            tree[i].num = (tree[i].r - tree[i].l) - tree[i].num;
            tree[i].tag = !tree[i].tag;
        }
        if (x <= tree[i].l && tree[i].r <= y) {
            tree[i].num = (tree[i].r - tree[i].l) - tree[i].num;
            tree[i].tag = !tree[i].tag;
        } else if (x < tree[i].r && tree[i].l < y) {
            tree[i].num = flip(i * 2 + 1, x, y, tree[i].tag) + flip(i * 2 + 2, x, y, tree[i].tag);
            tree[i].tag = false;
        }
        return tree[i].num;
    }
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> ans;
        tree.resize(4 * nums1.size());
        build(0, 0, nums1.size(), nums1);
        auto sum = accumulate(nums2.begin(), nums2.end(), static_cast<long long>(0));
        for (auto q : queries) {
            if (q[0] == 1) {
                flip(0, q[1], q[2] + 1, false);
            } else if (q[0] == 2) {
                sum += static_cast<long long>(tree[0].num) * q[1];
            } else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};