#include <bits/stdc++.h>
using namespace std;

int res = 0;
int m, n;

int visit(vector<vector<int>>& matrix, int x, int y) {
    int val = matrix[x][y];
    int res = 0;
    if (x + 1 <  m && val < matrix[x+1][y]) res = max(visit(matrix, x+1, y), res);
    if (x - 1 >= 0 && val < matrix[x-1][y]) res = max(visit(matrix, x-1, y), res);
    if (y + 1 <  n && val < matrix[x][y+1]) res = max(visit(matrix, x, y+1), res);
    if (y - 1 >= 0 && val < matrix[x][y-1]) res = max(visit(matrix, x, y-1), res);

    return 1 + res;
}


int longestIncreasingPath_1(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            auto val = matrix[i][j];
            bool key = true;
            if (i + 1 <  m && val > matrix[i+1][j]) key = false;
            if (i - 1 >= 0 && val > matrix[i-1][j]) key = false;
            if (j + 1 <  n && val > matrix[i][j+1]) key = false;
            if (j - 1 >= 0 && val > matrix[i][j-1]) key = false;

            if (key) res = max(res, visit(matrix, i, j));
        }
    }
    return res;
}