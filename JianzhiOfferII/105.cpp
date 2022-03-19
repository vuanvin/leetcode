#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        function<int(int, int)> dfs;

        dfs = [&] (int x, int y) -> int {
            grid[x][y] = 0;
            int cnt = 1;
            for (const auto& dir : dirs) {
                int u = x + dir[0], v = y + dir[1];
                if (0 <= u && u < m && 0 <= v && v < n) {
                    if (grid[u][v]) {
                        cnt += dfs(u, v);
                    }
                }
            }
            return cnt;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        return ans;
    }
};