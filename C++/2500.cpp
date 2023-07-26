#include <leetcode.h>

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) sort(grid[i].begin(), grid[i].end());
        int ans = 0;
        for (int j = n - 1; j >= 0; --j) {
            int mx = grid[0][j];
            for (int i = 1; i < m; ++i) {
                mx = max(mx, grid[i][j]);
            }
            ans += mx;
        }
        return ans;
    }
};