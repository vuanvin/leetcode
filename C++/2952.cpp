#include <leetcode.h>

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int res = 0, curr = 1, i = 0;
        while (i < n) {
            if (coins[i] <= curr) {
                curr += coins[i];
                if (curr > target) {
                    return res;
                }
                i++;
            } else {
                res++;
                curr <<= 1;
            }
        }

        while (curr <= target) {
            res++;
            curr <<= 1;
        }

        return res;
    }
};