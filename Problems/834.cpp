#include <leetcode.h>

class Solution {
    vector<int> ans, dp, sz;
    vector<vector<int>> graph;

public:
    void pre_dfs(int u, int f) {
        sz[u] = 1;
        dp[u] = 0;
        for (auto v : graph[u]) {
            if (v == f) continue;
            pre_dfs(v, u);
            sz[u] += sz[v];
            dp[u] += dp[v] + sz[v];
        }
    }

    void post_dfs(int u, int f) {
        ans[u] = dp[u];
        for (auto v : graph[u]) {
            if (v == f) continue;
            auto du = dp[u], dv = dp[v], su = sz[u], sv = sz[v];
            dp[u] -= dp[v] + sz[v], sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u], sz[v] += sz[u];
            post_dfs(v, u);
            dp[u] = du, dp[v] = dv, sz[u] = su, sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans.assign(n, 0);
        dp.assign(n, 0);
        sz.assign(n, 0);
        graph.assign(n, {});
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        pre_dfs(0, -1);
        post_dfs(0, -1);
        return ans;
    }
};