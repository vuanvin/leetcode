#include <leetcode.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n, 0);
        int mn = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] > mn) {
                f[i] = max(prices[i] - mn, f[i - 1]);
            } else {
                f[i] = f[i - 1];
                mn = prices[i];
            }
        }
        int ans = f[n - 1], mx = prices[n - 1];
        for (int i = n - 2; i > 0; --i) {
            if (prices[i] < mx) {
                ans = max(f[i - 1] + mx - prices[i], ans);
            } else {
                mx = prices[i];
            }
        }
        return ans;
    }
};