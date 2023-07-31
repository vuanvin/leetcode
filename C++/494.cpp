#include <leetcode.h>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = accumulate(nums.begin(), nums.end(), 0);
        if (n < target) return 0;
        n = n - target;
        auto f = vector<int>(n + 1, 0);
        f[n] = 1;
        for (auto v : nums) {
            v <<= 1;
            for (int j = 0; j <= n - v; j++) {
                f[j] += f[j + v];
            }
        }
        return f[0];
    }
};

// class Solution {
// public:
//     int dfs(vector<int>& nums, int target, int i, int sum) {
//         if (i == nums.size()) {
//             return target == sum ? 1 : 0;
//         }
//         return dfs(nums, target, i + 1, sum + nums[i]) + dfs(nums, target, i + 1, sum - nums[i]);
//     }
//     int findTargetSumWays(vector<int>& nums, int target) { return dfs(nums, target, 0, 0); }
// };