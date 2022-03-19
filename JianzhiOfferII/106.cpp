#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);

        int tag = 1;
        queue<int> Q;

        for (int k = 0; k < n; k++) {
            if (color[k]) continue;

            color[k] = tag;
            Q.push(k);
            int T = 1;

            while (T) {
                tag = -tag;

                for (int i = 0; i < T; i++) {
                    auto u = Q.front(); Q.pop();
                    for (auto v : graph[u]) {
                        if (color[v]) {
                            if (color[v] != tag) return false;
                        } else {
                            color[v] = tag;
                            Q.push(v);
                        }
                    }
                }
                T = Q.size();
            }
        }

        return true;
    }
};