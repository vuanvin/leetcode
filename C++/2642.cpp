#include <leetcode.h>

class Graph {
    vector<vector<int>> adj;

public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        for (auto& edge : edges) {
            adj[edge[0]][edge[1]] = edge[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        int x = edge[0], y = edge[1], cost = edge[2];
        if (cost >= adj[x][y]) {
            return;
        }
        int n = adj.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][x] != INT_MAX && adj[y][j] != INT_MAX) {
                    adj[i][j] = min(adj[i][j], adj[i][x] + adj[y][j] + cost);
                }
            }
        }
    }

    int shortestPath(int node1, int node2) { return adj[node1][node2] == INT_MAX ? -1 : adj[node1][node2]; }
};
