#include <leetcode.h>

class Solution {
public:
    int INC(int x) { return x == INT_MAX ? INT_MAX : x + 1; }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(std::unique(arr2.begin(), arr2.end()), arr2.end());
        int m = arr1.size(), n = arr2.size();
        using pii = pair<int, int>;
        vector<vector<pii>> f(m, vector<pii>(n));
        for (int j = 0; j < n; j++) f[0][j] = {0, 1};

        for (int i = 1; i < m; i++) {
            int mn = INT_MAX;
            int stop = -1;
            for (int j = 0; j < n; j++) {
                if (arr1[i] > arr2[j]) stop = j;

                int u1 = arr1[i] > arr1[i - 1] ? f[i - 1][j].first : INT_MAX;
                int u2 = stop >= 0 ? f[i - 1][stop].second : INT_MAX;
                int u3 = j == 0 ? INT_MAX : f[i][j - 1].first;
                f[i][j].first = min(min(u1, u2), u3);

                int v1 = arr2[j] > arr1[i - 1] ? INC(f[i - 1][j].first) : INT_MAX;
                int v2 = INC(j == 0 ? INT_MAX : f[i - 1][j - 1].second);
                int v3 = j == 0 ? INT_MAX : f[i][j - 1].second;
                f[i][j].second = min(min(v1, v2), v3);
            }
        }
        int ans = min(f[m - 1][n - 1].first, f[m - 1][n - 1].second);
        return ans == INT_MAX ? -1 : ans;
    }
};