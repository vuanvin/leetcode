#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<pair<int, int>> stk;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        auto h = heights[i];
        int nextH = (i + 1 < n) ? heights[i+1] : INT_MIN;
        ans = max(ans, h);
        for (int j = stk.size() - 1; j >= 0; j--) {
            auto p = stk[j];
            if (p.second <= nextH) {
                break;
            }
            ans = max(ans, (i - p.first + 1) * min(h, p.second));
        }

        // pop
        int pos = i;
        while (!stk.empty() && stk.back().second >= h) {
            pos = stk.back().first;
            stk.pop_back();
        }
        stk.push_back({pos, h});
    }

    return ans;
}

int maximalRectangle(vector<string>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    if (n == 0) return 0;

    vector<vector<int>> graph(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        graph[0][i] = matrix[0][i] == '1' ? 1 : 0;
    }

    for (int i = 1; i < m; i++) {
        auto row = matrix[i];
        for (int j = 0; j < n; j++) {
            graph[i][j] = row[j] == '1' ? 1 + graph[i-1][j] : 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, largestRectangleArea(graph[i]));
    }

    return ans;
}