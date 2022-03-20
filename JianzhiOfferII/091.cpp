#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> totals(n, vector<int>(3));
        for (int i = 0; i < 3; i++) totals[0][i] = costs[0][i];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                totals[i][j] = costs[i][j] + min(totals[i-1][(j+1) % 3], totals[i-1][(j+2) % 3]);
            }
        }

        return min(min(totals[n-1][0], totals[n-1][1]), totals[n-1][2]);
    }
};