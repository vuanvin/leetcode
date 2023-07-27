#include <leetcode.h>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return nums[0];
    }
};