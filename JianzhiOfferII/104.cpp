#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4_1(vector<int>& nums, int target) {
        int ans = 0;
        int len = nums.size();

        function<void(int)> find;

        find = [&] (int sum) {
            if (sum == target) ans++;
            if (sum >= target) return;

            for (auto num : nums) {
                find(num + sum);
            }
        };

        find(0);

        return ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        int len = nums.size();
        vector<unsigned int> dp(target+1, 0);

        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};