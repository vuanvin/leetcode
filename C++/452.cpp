#include <leetcode.h>

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto& x, auto& y) { return x[1] < y[1]; });
        int n = points.size();
        int r = points[0][1];
        int ans = 1;
        for (int i = 0; i < n; i++) {
            auto& p = points[i];
            if (r < p[0]) {
                r = p[1];
                ans++;
            }
        }
        return ans;
    }
};