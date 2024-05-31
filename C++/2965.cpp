#include <leetcode.h>

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr(n * n, 0), ans(2, 0);
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n; j++) {
                auto k = grid[i][j];
                if (arr[k - 1] != 0) {
                    ans[0] = k;
                } else {
                    arr[k - 1] = k;
                }
            }
        }
        for (int i = 0; i < n * n; i++) {
            if (arr[i] == 0) {
                ans[1] = i + 1;
            }
        }
        return ans;
    }
};