#include <leetcode.h>

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (sum + 1 < nums[i]) {
                if (sum >= n) return ans;
                sum = sum + (sum + 1);
                ans++;
            }
            sum = sum + nums[i];
        }
        while (sum < n) {
            if (sum + 1 > n - sum) {
                return ans + 1;
            }
            sum = sum + (sum + 1);
            ans++;
        }
        return ans;
    }
};