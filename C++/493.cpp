#include <leetcode.h>

class Solution {
public:
    int msort(vector<int>& nums, int l, int r) {
        using LL = long long;
        if (l == r) {
            return 0;
        }
        int m = (l + r) / 2;
        int ret = msort(nums, l, m) + msort(nums, m + 1, r);
        for (int i = l, j = m + 1; i <= m; i++) {
            for (; j <= r && (LL)nums[i] > 2 * (LL)nums[j]; j++)
                ;
            ret += j - m - 1;
        }
        vector<int> sorted(r - l + 1);
        int i1 = l, i2 = m + 1, i = 0;
        while (i1 <= m || i2 <= r) {
            if (i1 > m) {
                sorted[i++] = nums[i2++];
            } else if (i2 > r) {
                sorted[i++] = nums[i1++];
            } else {
                if (nums[i1] < nums[i2]) {
                    sorted[i++] = nums[i1++];
                } else {
                    sorted[i++] = nums[i2++];
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            nums[l + i] = sorted[i];
        }
        return ret;
    }
    int reversePairs(vector<int>& nums) {
        return msort(nums, 0, nums.size() - 1);
    }
};