#include <leetcode.h>

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int which = 1;
        int x = 0, y = 0, m = mat.size(), n = mat[0].size();
        vector<int> ans;
        while (x < m && y < n) {
            ans.push_back(mat[x][y]);
            if (which == 1) {
                if (x == 0) {
                    if (y == n - 1) {
                        x++;
                    } else {
                        y++;
                    }
                    which = 1 - which;
                } else {
                    if (y == n - 1) {
                        x++;
                        which = 1 - which;
                    } else {
                        x--;
                        y++;
                    }
                }
            } else {
                if (y == 0) {
                    if (x == m - 1) {
                        y++;
                    } else {
                        x++;
                    }
                    which = 1 - which;
                } else {
                    if (x == m - 1) {
                        y++;
                        which = 1 - which;
                    } else {
                        x++;
                        y--;
                    }
                }
            }
        }
        return ans;
    }
};