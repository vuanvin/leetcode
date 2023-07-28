#include <leetcode.h>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l1 = 0, l2 = 0, n = nums.size();
        while (l1 < n - 1 && nums[l1 + 1] <= nums[l1]) {
            l1++;
        }
        l2 = l1 + 1;
        if (l2 == n) { return false; }
        for (int i = l2 + 1; i < n; i++) {
            if (nums[i] < nums[l1]) {
                l1 = i;
            } else if (nums[l1] < nums[i] && nums[i] < nums[l2]) {
                l2 = i;
            } else if (nums[i] > nums[l2]) {
                return true;
            }
        }
        return false;
    }
};