#include <leetcode.h>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, k = n - 1;
        for (int j = 0; j <= k; ++j) {
            while (j <= k && nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            }
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
    }
};