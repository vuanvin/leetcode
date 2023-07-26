#include <leetcode.h>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        using LL = long long;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i1 = 0; i1 < n - 3; ++i1) {
            if (i1 > 0 && nums[i1] == nums[i1 - 1]) continue;
            for (int i2 = i1 + 1; i2 < n - 2; ++i2) {
                if (i2 > i1 + 1 && nums[i2] == nums[i2 - 1]) continue;
                int i4 = n - 1;
                auto sub_target = (static_cast<LL>(target) - static_cast<LL>(nums[i1])) - nums[i2];
                for (int i3 = i2 + 1; i3 < i4; ++i3) {
                    if (i3 > i2 + 1 && nums[i3] == nums[i3 - 1]) continue;
                    while (i4 < n - 1 && i3 < i4 && nums[i4] == nums[i4 + 1]) {
                        --i4;
                    }
                    while (i3 < i4 && static_cast<LL>(nums[i3]) + nums[i4] > sub_target) {
                        --i4;
                    }
                    if (i3 < i4 && static_cast<LL>(nums[i3]) + nums[i4] == sub_target) {
                        ans.push_back({nums[i1], nums[i2], nums[i3], nums[i4]});
                    }
                }
            }
        }
        return ans;
    }
};