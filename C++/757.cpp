#include <leetcode.h>

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int ans = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> order(n);
        vector<int> flag(n, false);
        for (int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int i, int j) {
            auto& P = intervals[i];
            auto& Q = intervals[j];
            return P[1] != Q[1] ? P[1] < Q[1] : P[0] < Q[0];
        });
        int j = 0, l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (flag[i]) continue;
            int x = intervals[i][0], y = intervals[i][1];
            while (j < n && intervals[order[j]][1] <= y) {
                int ord = order[j++];
                flag[ord] = true;
                int nx = intervals[ord][0], ny = intervals[ord][1];
                if (r < nx) {
                    r = ny;
                    l = ny - 1;
                    ans += 2;
                } else if (l < nx) {
                    l = r == ny ? ny - 1 : r;
                    r = ny;
                    ans += 1;
                }
            }
        }

        return ans;
    }
};