#include <leetcode.h>

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                }
            }
        }

        for (int s = 0; s <= m + n - 2; s++) {
            int y = min(s, n - 1);
            int x = s - y;
            while (x < m && y >= 0) {
                if (x - 1 >= 0) {
                    dist[x][y] = min(dist[x][y], dist[x - 1][y] + 1);
                }
                if (y - 1 >= 0) {
                    dist[x][y] = min(dist[x][y], dist[x][y - 1] + 1);
                }
                x++;
                y--;
            }
        }

        for (int s = m + n - 2; s >= 0; s--) {
            int y = min(s, n - 1);
            int x = s - y;
            if (grid[x][y] == 1) dist[x][y] = 0;

            while (x < m && y >= 0) {
                if (x + 1 < m) {
                    dist[x][y] = min(dist[x][y], dist[x + 1][y] + 1);
                }
                if (y + 1 < n) {
                    dist[x][y] = min(dist[x][y], dist[x][y + 1] + 1);
                }
                x++;
                y--;
            }
        }

        for (int s = 1 - n; s <= m - 1; s++) {
            int x = max(0, s);
            int y = x - s;
            while (x < m && y < n) {
                if (x - 1 >= 0) {
                    dist[x][y] = min(dist[x][y], dist[x - 1][y] + 1);
                }
                if (y - 1 >= 0) {
                    dist[x][y] = min(dist[x][y], dist[x][y - 1] + 1);
                }
                x++;
                y++;
            }
        }
        for (int s = m - 1; s >= 1 - n; s--) {
            int x = max(0, s);
            int y = x - s;
            while (x < m && y < n) {
                if (x + 1 < m) {
                    dist[x][y] = min(dist[x][y], dist[x + 1][y] + 1);
                }
                if (y + 1 < n) {
                    dist[x][y] = min(dist[x][y], dist[x][y + 1] + 1);
                }
                x++;
                y++;
            }
        }

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        using pii = pair<int, int>;
        auto cmp = [](pii x, pii y) { return (x.first != y.first) ? x.first < y.first : x.second < y.second; };
        priority_queue<pii, vector<pii>, decltype(cmp)> Q(cmp);
        int dir[] = {-1, 0, 1, 0, -1};

        Q.push({dist[0][0], 0});
        grid[0][0] = -1;

        while (!Q.empty()) {
            auto [score, s] = Q.top();
            Q.pop();
            int x = s / n, y = s % n;

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d], ny = y + dir[d + 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] >= 0) {
                        if (nx == m - 1 && ny == n - 1) {
                            return min(score, dist[nx][ny]);
                        }
                        Q.push({min(score, dist[nx][ny]), nx * n + ny});
                        grid[nx][ny] = -1;
                    }
                }
            }
        }

        return 0;
    }
};