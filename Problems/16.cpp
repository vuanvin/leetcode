#include <leetcode.h>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n; ++first) {
            int second = first + 1, third = n - 1;
            while (second < third) {
                auto sum = nums[first] + nums[second] + nums[third];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                if (sum < target) {
                    ++second;
                } else if (sum > target) {
                    --third;
                } else {
                    return ans;
                }
            }
        }
        return ans;
    }
};