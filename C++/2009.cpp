#include <leetcode.h>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, ans = n - 1, n_ops = n - 1;
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[j - 1]) {
                n_ops--;
                while (nums[j] - nums[i] >= n) {
                    i++;
                    if (nums[i] != nums[i - 1]) {
                        n_ops++;
                    }
                }
                ans = min(ans, n_ops);
            }
        }
        return ans;
    }
};