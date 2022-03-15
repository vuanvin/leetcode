#include <bits/stdc++.h>
using namespace std;

int minCut(string s) {
    int n = s.size();
    if (n == 0) return 0;

    vector<vector<int>> f(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) { f[i][i] = 1; }
    for (int i = 0; i < n-1; i++) { if (s[i+1] == s[i]) f[i+1][i] = 1; }

    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n - k; i++) {
            if (s[i] == s[i+k] && f[i+1][i+k-1] == 1) {
                f[i][i+k] = 1;
            } 
        }
    }

    vector<int> step(n+1);
    step[n] = 0;
    for (int i = n - 1; i >= 0; i --) {
        int s = n+1;
        for (int j = i; j < n; j ++) {
            if (f[i][j]) {
                s = min(s, step[j+1] + 1);
            }
        }
        step[i] = s;
    }
    return step[0];
}