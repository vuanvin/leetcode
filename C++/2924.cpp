#include <leetcode.h>

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> flags(n, true);
        for (auto& e : edges) {
            flags[e[1]] = false;
        }
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (flags[i]) {
                if (res >= 0) {
                    return -1;
                }
                res = i;
            }
        }
        return res;
    }
};