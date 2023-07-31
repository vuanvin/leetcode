#include <leetcode.h>

constexpr int lowbit(int x) { return x & (-x); }

struct BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int n) : n(n), tree(n + 1) {}

    void update(int x, int d) {
        while (x <= n) {
            tree[x] += d;
            x += lowbit(x);
        }
    }

    int query(int x) const {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution {
public:
    using LL = long long;
    int reversePairs(vector<int>& nums) {
        set<LL> numbers;
        for (auto x : nums) {
            numbers.insert(x);
            numbers.insert((LL)x * 2);
        }
        unordered_map<LL, int> values;
        int idx = 0;
        for (LL x : numbers) values[x] = ++idx;

        int ans = 0;
        BIT bit(values.size());
        for (int i = 0; i < nums.size(); i++) {
            int l = values[(LL)nums[i] * 2], r = values.size();
            ans += bit.query(r) - bit.query(l);
            bit.update(values[nums[i]], 1);
        }
        return ans;
    }
};