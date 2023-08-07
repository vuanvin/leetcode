#include <leetcode.h>

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = 0, mn = 0;
        int vx = 0, vn = 0;
        for (auto v : nums) {
            vx += v;
            vn += v;
            vx = max(0, vx);
            vn = min(0, vn);
            mx = max(vx, mx);
            mn = min(vn, mn);
        }

        return max(mx, -mn)
    }
};