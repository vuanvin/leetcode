#include <leetcode.h>

class Solution {
private:
    vector<vector<int>> edges, ans;
    vector<int> dfn, low;
    vector<bool> vis;
    int idx;

public:
    void Tarjan(int u, int f) {
        vis[u] = true;
        low[u] = dfn[u] = idx++;

        for (auto v : edges[u]) {
            if (!vis[v]) {
                Tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    ans.push_back({u, v});
                }
            } else if (v != f) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn.resize(n);
        low.resize(n);
        vis.resize(n, false);
        edges.resize(n, {});

        for (auto& e : connections) {
            int x = e[0], y = e[1];
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                idx = 0;
                Tarjan(i, i);
            }
        }
        return ans;
    }
};