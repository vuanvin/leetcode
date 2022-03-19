#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        dp[0][nums[0]] = 0; dp[0][-nums[0]] = 0;
        dp[0][nums[0]]++; dp[0][-nums[0]]++;

        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (auto item : dp[i-1]) {
                auto sum = num + item.first;
                if (dp[i].count(sum)) {
                    dp[i][sum] += item.second;
                } else {
                    dp[i][sum] = item.second;
                }

                sum = item.first - num;
                if (dp[i].count(sum)) {
                    dp[i][sum] += item.second;
                } else {
                    dp[i][sum] = item.second;
                }
            }
        }

        return dp[n-1].count(target) ? dp[n-1][target] : 0;
    }
};