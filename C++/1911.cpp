#include <leetcode.h>

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        using LL = long long;
        auto n = nums.size();
        vector<LL> dp_odd(n), dp_even(n);
        dp_even[0] = nums[0];
        dp_odd[0] = 0;
        for (size_t i = 1; i < n; ++i) {
            dp_even[i] = max(dp_even[i - 1], dp_odd[i - 1] + nums[i]);
            dp_odd[i] = max(dp_odd[i - 1], dp_even[i - 1] - nums[i]);
        }
        return max(dp_even[n - 1], dp_odd[n - 1]);
    }
};