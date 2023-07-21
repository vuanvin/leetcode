#include <leetcode.h>

class Solution {
public:
    int candy(vector<int>& ratings) {
        int up = 0, n = ratings.size();
        vector<int> f(n, 0);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                up += 1;
                f[i] = up;
            } else {
                up = 0;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                up += 1;
                f[i] = max(f[i], up);
            } else {
                up = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += f[i] + 1;
        }
        return ans;
    }
};