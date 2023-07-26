#include <leetcode.h>

class Solution {
public:
    vector<pair<bool, int>> tree;
    int build(int i, int x, int y, const vector<int>& seconds) {
        tree[i].first = false;
        if (x + 1 == y) {
            tree[i].second = seconds[x];
        } else {
            int m = (x + y) / 2;
            tree[i].second = build(i * 2 + 1, x, m, seconds) + build(i * 2 + 2, m, y, seconds);
        }
        return tree[i].second;
    }
    int flip(int i, int x, int y, int l, int r, bool tag) {
        if (tag) {
            tree[i].second = (r - l) - tree[i].second;
            tree[i].first = !tree[i].first;
        }
        if (x <= l && r <= y) {
            tree[i].second = (r - l) - tree[i].second;
            tree[i].first = !tree[i].first;
        } else if (x < r && l < y) {
            int m = (l + r) / 2;
            tree[i].second = flip(i * 2 + 1, x, y, l, m, tree[i].first) + flip(i * 2 + 2, x, y, m, r, tree[i].first);
            tree[i].first = false;
        }
        return tree[i].second;
    }
    vector<long long> handleQuery(vector<int>& seconds1, vector<int>& seconds2, vector<vector<int>>& queries) {
        vector<long long> ans;
        tree.resize(4 * seconds1.size());
        build(0, 0, seconds1.size(), seconds1);
        auto sum = accumulate(seconds2.begin(), seconds2.end(), static_cast<long long>(0));
        for (auto q : queries) {
            if (q[0] == 1) {
                flip(0, q[1], q[2] + 1, 0, seconds1.size(), false);
            } else if (q[0] == 2) {
                sum += static_cast<long long>(tree[0].second) * q[1];
            } else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};