#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            triangle[i][0] += triangle[i-1][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
            triangle[i][i] += triangle[i-1][i-1];
        }

        int mn = triangle[n-1][0];
        for (int i = 1; i <= n-1; i++) { mn = min(mn, triangle[n-1][i]); }

        return mn;
    }
};