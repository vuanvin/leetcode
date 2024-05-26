#include <leetcode.h>

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        constexpr long long N = 1e9 + 7;
        sort(ranges.begin(), ranges.end(), [&](auto& a, auto& b) { return a[0] < b[0]; });

        int cnt = 1;
        int r = ranges[0][1];
        for (int i = 1; i < ranges.size(); i++) {
            int l = ranges[i][0];
            if (l > r) {
                cnt++;
            }
            r = max(r, ranges[i][1]);
        }

        long long res = 1;
        for (int i = 0; i < cnt; i++) {
            res *= 2;
            res %= N;
        }
        return res;
    }
};