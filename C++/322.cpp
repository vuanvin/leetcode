#include <leetcode.h>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, INT_MAX);
        f[0] = 0;
        for (int i = 0; i < amount; i++) {
            if (f[i] != INT_MAX) {
                for (auto c : coins) {
                    if (c <= amount - i) {
                        f[i + c] = min(f[i] + 1, f[i + c]);
                    }
                }
            }
        }
        return f[amount] == INT_MAX ? -1 : f[amount];
    }
};