#include <leetcode.h>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f{{nums[0]}};
        for (int i = 0; i < n; i++) {
            if (int num = nums[i]; num > f.back()) {
                f.push_back(num);
            } else {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }

        return f.size();
    }
};