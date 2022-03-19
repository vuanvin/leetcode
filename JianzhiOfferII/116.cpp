#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> f;

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        f.assign(n, 0);
        int ans = n;
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }

        auto Find = [&](int v) {
            while (f[v] != v) { v = f[v]; }
            return v;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    auto fi = Find(i);
                    auto fj = Find(j);
                    if (fi != fj) {
                        ans--;
                        f[i] = f[j] = f[fj] = fi;
                    }
                }
            }
        }

        return ans;
    }
};