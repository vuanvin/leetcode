#include <leetcode.h>

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) return true;
        int mx = 0;
        for (int i = 1; i < n; i++) {
            int val = nums[i - 1] + nums[i];
            mx = max(mx, val);
        }
        return mx >= m;
    }
};