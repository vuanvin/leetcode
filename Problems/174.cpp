#include <leetcode.h>

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_MIN));
        f[m - 1][n] = f[m][n - 1] = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                f[i][j] = dungeon[i][j] + min(max(f[i + 1][j], f[i][j + 1]), 0);
            }
        }
        return 1 - min(f[0][0], 0);
    }
};