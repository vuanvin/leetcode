#include <leetcode.h>

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, INT_MIN);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                int cnt = num <= 0 ? 1 : 0;
                while (num) {
                    cnt++;
                    num /= 10;
                }
                ans[j] = max(ans[j], cnt);
            }
        }
        return ans;
    }
};