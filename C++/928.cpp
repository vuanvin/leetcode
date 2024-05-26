#include <leetcode.h>

class Solution {
public:
    // int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    //     int ans = 0, M = INT_MAX, n = graph.size();
    //     for (auto node : initial) {
    //         int cnt = 0;
    //         queue<int> Q;
    //         vector<int> vis(n, false);
    //         for (auto inode : initial) {
    //             if (inode != node) {
    //                 Q.push(inode);
    //                 vis[inode] = true;
    //             }
    //         }
    //         while (!Q.empty()) {
    //             cnt++;
    //             auto p = Q.front();
    //             Q.pop();

    //             for (int q = 0; q < n; q++) {
    //                 if (q == node) continue;
    //                 if (!vis[q] && graph[p][q] == 1) {
    //                     Q.push(q);
    //                     vis[q] = true;
    //                 }
    //             }
    //         }
    //         if (cnt < M || cnt == M && node < ans) {
    //             ans = node;
    //             M = cnt;
    //         }
    //     }
    //     return ans;
    // }

    int find(vector<int>& uf, int u) {
        if (uf[u] == u) {
            return u;
        }
        uf[u] = find(uf, uf[u]);
        return uf[u];
    }

    void merge(vector<int>& uf, int u, int v) {
        int ru = find(uf, u), rv = find(uf, v);
        uf[ru] = rv;
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> initialSet(n);
        for (int v : initial) {
            initialSet[v] = 1;
        }
        vector<int> uf(n);
        iota(uf.begin(), uf.end(), 0);
        for (int u = 0; u < n; u++) {
            if (initialSet[u] == 1) continue;

            for (int v = 0; v < n; v++) {
                if (initialSet[v] == 1) continue;

                if (graph[u][v] == 1) {
                    merge(uf, u, v);
                }
            }
        }

        vector<int> infectedBy(n, -1);
        for (int v : initial) {
            vector<int> infectedSet(n);

            for (int u = 0; u < n; u++) {
                if (initialSet[u] == 1 || graph[u][v] == 0) continue;
                infectedSet[find(uf, u)] = 1;  // graph[u][v] == 1
            }

            for (int u = 0; u < n; u++) {
                if (infectedSet[u] == 1) {
                    infectedBy[u] = infectedBy[u] == -1 ? v : -2;
                }
            }
        }

        vector<int> count(n);
        for (int u = 0; u < n; u++) {
            if (infectedBy[u] < 0) continue;

            int v = infectedBy[u];
            for (int w = 0; w < n; w++) {
                if (find(uf, w) == find(uf, u)) {
                    count[v]++;
                }
            }
        }

        int res = initial[0];
        for (int v : initial) {
            if (count[v] > count[res] || count[v] == count[res] && v < res) {
                res = v;
            }
        }
        return res;
    }
};