#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> f(m, vector<int>(n, 0));

        f[0][0] = (text1[0] == text2[0]) ? 1 : 0;

        for (int i = 1; i < m; i++) { f[i][0] = (f[i-1][0] || text1[i] == text2[0]) ? 1 : 0; }
        for (int j = 1; j < n; j++) { f[0][j] = (f[0][j-1] || text1[0] == text2[j]) ? 1 : 0; }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (text1[i] == text2[j]) {
                    f[i][j] = f[i-1][j-1] + 1;
                }
                else {
                    f[i][j] = max(f[i][j-1], f[i-1][j]);
                }
            }
        }

        return f[m-1][n-1];
    }
};