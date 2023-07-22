#include <leetcode.h>

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        f[m - 1][n - 1] = dungeon[m - 1][n - 1];
        for (int i = m - 2; i >= 0; --i) f[i][n - 1] = dungeon[i][n - 1] + min(f[i + 1][n - 1], 0);
        for (int j = n - 2; j >= 0; --j) f[m - 1][j] = dungeon[m - 1][j] + min(f[m - 1][j + 1], 0);
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                f[i][j] = dungeon[i][j] + min(max(f[i + 1][j], f[i][j + 1]), 0);
            }
        }
        return 1 - min(f[0][0], 0);
    }
};