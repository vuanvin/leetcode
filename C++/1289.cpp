#include <leetcode.h>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (n == 1) return grid[0][0];

        int idx = 0, mxv = grid[0][0];
        for (int j = 0; j < n; j++) {
            if (grid[0][j] < mxv) {
                idx = j;
                mxv = grid[0][j];
            }
        }

        for (int i = 1; i < m; i++) {
            int new_mxv = INT_MAX;
            int new_idx = 0;
            for (int j = 0; j < n; j++) {
                if (idx == j) {
                    int sec_mxv = INT_MAX;
                    for (int k = 0; k < n; k++) {
                        if (k == idx) continue;
                        sec_mxv = min(sec_mxv, grid[i - 1][k]);
                    }
                    grid[i][j] += sec_mxv;
                    if (grid[i][j] < new_mxv) {
                        new_mxv = grid[i][j];
                        new_idx = j;
                    }
                } else {
                    grid[i][j] += mxv;
                    if (grid[i][j] < new_mxv) {
                        new_mxv = grid[i][j];
                        new_idx = j;
                    }
                }
            }
            mxv = new_mxv;
            idx = new_idx;
        }
        return min_element(grid[m - 1].begin(), grid[m - 1].end())[0];
    }
};