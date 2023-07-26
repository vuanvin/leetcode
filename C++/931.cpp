#include <leetcode.h>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        auto m = matrix.size();
        auto n = matrix[0].size();
        vector<vector<int>> dp(matrix);
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + matrix[i][j];
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
                if (j < n - 1) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
            }
        }
        auto ans = dp[n - 1][0];
        for (int j = 1; j < n; ++j) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};