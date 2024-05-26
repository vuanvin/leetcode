#include <leetcode.h>

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int i = std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int j = nums.size() - (std::upper_bound(nums.begin() + i, nums.end(), 0) - nums.begin());
        return max(i, j);
    }
};