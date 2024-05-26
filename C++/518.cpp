#include <leetcode.h>

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), 0));

        for (int j = 0; j < coins.size(); j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            int acc = 0;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i][j] += dp[i - coins[j]][j];
                }
                dp[i][j] += acc;
                acc = dp[i][j];
            }
        }
        return dp[amount][coins.size() - 1];
    }
};