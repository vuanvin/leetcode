#include <leetcode.h>

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        if (n <= 2) return n;
        for (int i = 0; i < n; ++i) {
            int xi = points[i][0], yi = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int xj = points[j][0], yj = points[j][1];
                int dx = xj - xi, dy = yj - yi;
                int acc = 2;
                for (int k = j + 1; k < n; ++k) {
                    int xk = points[k][0], yk = points[k][1];
                    // (xj - xi, yj - yi), (xk - xi, yk - yi)
                    if ((xk - xi) * dy - (yk - yi) * dx == 0) {
                        acc += 1;
                    }
                }
                ans = max(acc, ans);
            }
        }
        return ans;
    }
};