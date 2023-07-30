#include <leetcode.h>

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mn = nums[0];
        for (auto v : nums) mn = min(mn, v);
        for (auto v : nums) ans += v - mn;
        return ans;
    }
};