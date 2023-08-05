#include <leetcode.h>

class Solution {
public:
    int ans;

    static constexpr int dir[] = {-1, 0, 1, 0, -1};

    void dfs(vector<vector<int>>& grid, int x, int y, int cnt) {
        cnt--;
        int m = grid.size(), n = grid[0].size();
        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d], ny = y + dir[d + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (grid[nx][ny] == 0) {
                    grid[nx][ny] = -2;
                    dfs(grid, nx, ny, cnt);
                    grid[nx][ny] = 0;
                } else if (grid[nx][ny] == 2) {
                    if (cnt == 0) {
                        ans++;
                    }
                }
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        ans = 0;
        int m = grid.size(), n = grid[0].size();
        int x, y, cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
                if (grid[i][j] == 0) {
                    cnt++;
                }
            }
        }

        dfs(grid, x, y, cnt + 1);
        return ans;
    }
};