#include <leetcode.h>

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int l = k, r = k;
        int lval = nums[k], rval = nums[k];
        res = max(res, min(lval, rval) * (r - l + 1));

        while (l != 0 || r != n - 1) {
            int nl = l - 1, nr = r + 1;
            if (nl < 0) {
                r = nr;
            } else if (nr >= n) {
                l = nl;
            } else {
                if (min(nums[nl], lval) < min(nums[nr], rval)) {
                    rval = min(rval, nums[nr]);
                    r = nr;
                } else {
                    lval = min(lval, nums[nl]);
                    l = nl;
                }
            }

            lval = min(lval, nums[l]);
            rval = min(rval, nums[r]);
            res = max(res, min(lval, rval) * (r - l + 1));
        }

        return res;
    }
};