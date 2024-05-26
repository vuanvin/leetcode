#include <leetcode.h>

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> f(target + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i - num >= 0) f[i] += f[i - num];
            }
        }
        return f[target];
    }
};