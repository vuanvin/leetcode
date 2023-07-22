#include <leetcode.h>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, l = 0, sum = 0;
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum >= target) {
                sum -= nums[l++];
                ans = min(ans, r - l + 1);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};