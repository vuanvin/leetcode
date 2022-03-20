#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if (n1 + n2 != n3) return false;

        vector<vector<bool>> f(n1+1, vector<bool>(n2+1, 0));
        f[0][0] = true;

        for (int i = 0; i < n1; i++) {
            if (s1[i] == s3[i]) {
                f[i+1][0] = f[i][0];
            }
        }

        for (int j = 0; j < n2; j++) {
            if (s2[j] == s3[j]) {
                f[0][j+1] = f[0][j];
            }
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                f[i][j] = (f[i-1][j] && s1[i-1] == s3[i+j-1]) || (f[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return f[n1][n2];
    }
};