#include <bits/stdc++.h>
using namespace std;

struct BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int n) : n(n), tree(n + 1) {}
    static constexpr int lowbit(int x) { return x & (-x); }
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
    int range_count(int left, int right) { return query(right + 1) - query(left); }
};

int main() {}