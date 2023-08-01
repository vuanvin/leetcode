#include <leetcode.h>

class Solution {
public:
    using LL = long long;
    static constexpr LL mod = 1e9 + 7;
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        LL ans = 0, sum_mxv = 0, ov = 0;
        for (auto v : nums) {
            LL vv = ((LL)v * v) % mod;  // max
            LL cur_mxv = (sum_mxv * 2 + ov + v) % mod;  // min
            ans = (((cur_mxv * vv) % mod) + ans) % mod;
            sum_mxv = (sum_mxv * 2 + ov) % mod;
            ov = v;
        }
        return ans;
    }
};