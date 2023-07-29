#include <leetcode.h>

class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        int m = matrix.size(), n = matrix[0].size();
        auto f = vector<vector<int>>(m, vector<int>(n, 0));
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d][0], ny = y + dirs[d][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[x][y] < matrix[nx][ny]) {
                        f[x][y]++;
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (f[x][y] == 0) q.emplace(x, y);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ans++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d][0], ny = y + dirs[d][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] < matrix[x][y]) {
                        f[nx][ny]--;
                        if (f[nx][ny] == 0) {
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }
        return ans;
    }
};