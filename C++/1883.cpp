#include <leetcode.h>

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        if ((long)speed * (long)hoursBefore >= INT_MAX / 2) return 0;

        int n = dist.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int k = 0; k < n; k++) dp[0][k] = 0;

        for (int i = 1; i < n; i++) {
            int d = dist[i - 1];

            dp[i][0] = (dp[i - 1][0] + +d + speed - 1) / speed * speed;
            for (int k = 1; k <= i; k++) {
                dp[i][k] = min(dp[i - 1][k - 1] + d, (dp[i - 1][k] + d + speed - 1) / speed * speed);
            }
        }

        for (int k = 0; k < n; k++) {
            if (dp[n - 1][k] + dist[n - 1] <= speed * hoursBefore) {
                return k;
            }
        }

        return -1;
    }
};