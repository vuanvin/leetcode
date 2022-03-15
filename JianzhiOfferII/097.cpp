#include <bits/stdc++.h>
using namespace std;

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();

    if (m == 0 || n < m) { return 0; } 

    vector<vector<int>> f(m, vector<int>(n, 0));

    f[0][0] = ((t[0] == s[0]) ? 1 : 0);
    for (int i = 1; i < n; i++) {
        f[0][i] = f[0][i-1] + ((t[0] == s[i]) ? 1 : 0);
    }
    for (int i = 1; i < m; i++) {
        for (int j = i; j < n; j++) {
            if (t[i] == s[j]) {
                f[i][j] = f[i-1][j-1] + f[i][j-1];
            } else {
                f[i][j] = f[i][j-1];
            }
        }
    }

    return f[m-1][n-1];
}