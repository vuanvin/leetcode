#include <leetcode.h>

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans(k);
        int i = -1, n = nums.size();
        for (int j = 0; j < n; j++) {
            while (i >= 0 && nums[j] < ans[i] && i + n - j >= k) {
                i--;
            }
            if (i < k - 1) {
                ans[++i] = nums[j];
            }
        }
        return ans;
    }
};