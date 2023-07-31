#include <leetcode.h>

class Solution {
public:
    unordered_map<int, vector<int>> g;
    unordered_map<int, unordered_map<char, int>> stat;
    vector<int> visited;
    bool ring;
    int step;

    void dfs(int u, string& colors) {
        int n = colors.size();
        if (visited[u] == step) {
            ring = true;
            return;
        }
        visited[u] = step;

        auto color = colors[u];
        stat[u][color] = 1;

        if (g.count(u) == 0) {
            stat[u][color] = max(stat[u][color], 1);
        } else {
            for (auto v : g[u]) {
                if (visited[v] == step) {
                    ring = true;
                }

                if (ring) return;
                if (!stat.count(v)) {
                    dfs(v, colors);
                }

                for (auto [ch, cnt] : stat[v]) {
                    if (ch == color) {
                        stat[u][ch] = max(stat[u][ch], stat[v][ch] + 1);
                    } else {
                        stat[u][ch] = max(stat[u][ch], stat[v][ch]);
                    }
                }
            }
        }
        visited[u] = 0;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> flags(n, 0);
        for (auto& e : edges) {
            if (e[0] == e[1]) return -1;
            g[e[0]].push_back(e[1]);
            flags[e[1]] = 1;
        }
        visited.resize(n, 0);
        ring = false;
        step = 1;
        int ans = 1;
        for (auto& [v, e] : g) {
            step++;
            dfs(v, colors);
            for (auto [ch, cnt] : stat[v]) ans = max(ans, cnt);
        }
        if (ring) return -1;
        return ans;
    }
};