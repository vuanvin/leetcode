#include <leetcode.h>

class Solution {
public:
    using pii = pair<int, int>;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) {
            return 0;
        }
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    Q.emplace(heightMap[i][j], i * n + j);
                    visit[i][j] = true;
                }
            }
        }
        int res = 0;
        constexpr int dirs[] = {-1, 0, 1, 0, -1};
        while (!Q.empty()) {
            auto [height, index] = Q.top();
            int x = index / n, y = index % n;
            Q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d], ny = y + dirs[d + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                    if (heightMap[nx][ny] < height) {
                        res += height - heightMap[nx][ny];
                    }
                    visit[nx][ny] = true;
                    Q.emplace(max(heightMap[nx][ny], height), nx * n + ny);
                }
            }
        }
        return res;
    }
};