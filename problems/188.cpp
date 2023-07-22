#include <leetcode.h>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size()< 2 || k < 1) return 0;
        vector<int> buys(k, -prices[0]), sells(k, 0);
        for (int j = 1; j < prices.size(); ++j) {
            auto p = prices[j];
            for (int i = k - 1; i >= 0; --i) {
                sells[i] = max(sells[i], buys[i] + p);
                buys[i] = max(buys[i], i > 0 ? sells[i - 1] - p : -p);
            }
        }
        return sells[k - 1];
    }
};