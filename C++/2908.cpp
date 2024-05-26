#include <leetcode.h>

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> rmin(n, INT_MAX);
        int mn = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            rmin[i] = mn;
            if (nums[i] < mn) {
                mn = nums[i];
            }
        }
        int res = INT_MAX;
        mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (mn != INT_MAX && rmin[i] != INT_MAX && mn < nums[i] && rmin[i] < nums[i]) {
                res = min(res, mn + nums[i] + rmin[i]);
            }
            if (nums[i] < mn) {
                mn = nums[i];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};