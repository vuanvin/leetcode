#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix_1(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, 100000));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) res[i][j] = 0;
            }
        }

        for (int i = 1; i < m; i++) {
            res[i][0] = min(res[i][0], res[i-1][0]+1);
            res[i][n-1] = min(res[i][n-1], res[i-1][n-1]+1);
        }
        for (int i = m-2; i >= 0; i--) {
            res[i][0] = min(res[i][0], res[i+1][0]+1);
            res[i][n-1] = min(res[i][n-1], res[i+1][n-1]+1);
        }

        for (int j = 1; j < n; j++) {
            res[0][j] = min(res[0][j], res[0][j-1]+1);
            res[m-1][j] = min(res[m-1][j], res[m-1][j-1]+1);
        }
        for (int j = n-2; j >= 0; j--) {
            res[0][j] = min(res[0][j], res[0][j+1]+1);
            res[m-1][j] = min(res[m-1][j], res[m-1][j+1]+1);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (res[i][j] <= 1) continue;
                res[i][j] = min(res[i][j], res[i-1][j] + 1);
                res[i][j] = min(res[i][j], res[i][j-1] + 1);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = n-2; j >= 0; j--) {
                if (res[i][j] <= 1) continue;
                res[i][j] = min(res[i][j], res[i-1][j] + 1);
                res[i][j] = min(res[i][j], res[i][j+1] + 1);
            }
        }

        for (int i = m-2; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (res[i][j] <= 1) continue;
                res[i][j] = min(res[i][j], res[i+1][j] + 1);
                res[i][j] = min(res[i][j], res[i][j-1] + 1);
            }
        }

        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                if (res[i][j] <= 1) continue;
                res[i][j] = min(res[i][j], res[i+1][j] + 1);
                res[i][j] = min(res[i][j], res[i][j+1] + 1);
            }
        }

        return res;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    res[i][j] = 0;
                    Q.push(make_pair(i, j));
                }
            }
        }

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int T = Q.size();
        int dist = 0;
        while (T) {
            dist++;
            for (int t = 0; t < T; t++) {
                auto p = Q.front(); Q.pop();
                auto u = p.first, v = p.second;

                for (auto& dir : dirs) {
                    auto x = u + dir[0], y = v + dir[1];
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        if (dist < res[x][y]) {
                            res[x][y] = dist;
                            Q.push(make_pair(x, y));
                        }
                    }
                }
            }
            T = Q.size();
        }

        return res;
    }
};