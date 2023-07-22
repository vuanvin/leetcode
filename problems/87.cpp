#include <leetcode.h>

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        bool f[30][30][31] = {false};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s1[i] == s2[j]) f[i][j][1] = true;
            }
        }
        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i <= n - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    for (int l = 1; l < k; ++l) {
                        f[i][j][k] |= f[i][j][l] && f[i + l][j + l][k - l];
                        f[i][j][k] |= f[i][j + k - l][l] && f[i + l][j][k - l];
                    }
                }
            }
        }
        return f[0][0][n];
    }
};