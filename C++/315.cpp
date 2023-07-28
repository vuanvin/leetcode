#include <leetcode.h>

class Solution {
public:
    using pii = pair<int, int>;
    vector<pii> vals;
    vector<int> arr;
    void bisort(int l, int r) {
        if (r == l + 1) return;
        int m = (l + r) / 2;
        bisort(l, m);
        bisort(m, r);
        int i1 = l, i2 = m;
        vector<pii> tmp(r - l);

        int cnt = 0;
        for (int i = 0; i < r - l; i++) {
            if (i1 == m) { // right
                tmp[i] = vals[i2++];
                // cnt ++;
            } else if (i2 == r) {  // time to left
                tmp[i] = vals[i1++];
                arr[tmp[i].second] += cnt;
            } else if (vals[i1].first < vals[i2].first) {  // time to left
                tmp[i] = vals[i1++];
                arr[tmp[i].second] += cnt;
            } else if (vals[i2].first < vals[i1].first) { // right
                tmp[i] = vals[i2++];
                cnt++;
            } else {
                tmp[i] = vals[i1++]; // time to left
                arr[tmp[i].second] += cnt;
            }
        }
        for (int i = 0; i < r -l; i++) {
            vals[l + i] = tmp[i];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        arr.resize(n, 0);
        for (int i = 0; i < n; i++) vals.emplace_back(nums[i], i);
        bisort(0, n);
        return arr;
    }
};