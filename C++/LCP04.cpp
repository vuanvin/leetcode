// https://leetcode.cn/problems/broken-board-dominoes/
#include <leetcode.h>

class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_map<int, vector<int>> G;
    vector<int> link;
    vector<int> visited;
    int step;

    bool dfs(int u) {
        visited[u] = step;  // avoid dead loop
        for (auto v : G[u]) {
            if (link[v] == -1) {
                link[u] = v;
                link[v] = u;
                return true;
            }
        }
        for (auto v : G[u]) {
            if (visited[link[v]] != step && dfs(link[v])) {
                link[u] = v;
                link[v] = u;
                return true;
            }
        }
        return false;
    }

    int match(int num_nodes) {
        link.assign(num_nodes, -1);
        visited.assign(num_nodes, -1);
        step = 0;

        int res = 0;
        while (true) {
            int cnt = 0;
            for (auto& [u, _] : G) {
                if (link[u] == -1) {
                    if (dfs(u)) cnt++;
                    step++;
                }
            }
            if (cnt == 0) break;
            res += cnt;
        }
        return res;
    }

    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<vector<int>> obt(n, vector<int>(m, 0));
        for (auto& b : broken) obt[b[0]][b[1]] = 1;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (obt[x][y] == 1 || (x + y) % 2 == 0) continue;

                for (int d = 0; d < 4; d++) {
                    auto nx = x + dirs[d][0], ny = y + dirs[d][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && obt[nx][ny] == 0) {
                        int h1 = x * m + y, h2 = nx * m + ny;
                        G[h1].push_back(h2);
                    }
                }
            }
        }
        return match(m * n);
    }
};