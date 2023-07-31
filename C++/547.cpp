#include <leetcode.h>

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++) f[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    int x = i, y = j;
                    while (x != f[x]) x = f[x];
                    while (y != f[y]) y = f[y];
                    if (x < y) {
                        f[y] = f[i] = f[j] = x;
                    } else {
                        f[x] = f[i] = f[j] = y;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans += (i == f[i]) ? 1 : 0;
        return ans;
    }
};